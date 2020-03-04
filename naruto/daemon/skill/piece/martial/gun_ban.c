#include <ansi.h>
#define SKILL_NAME "gun ban"
#define SKILL_NAME_C "���j�E��"
#define SKILL_CLASS "martial"

inherit SKILL;

void create()
{
    seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
}

string query_class() { return SKILL_CLASS; }

void skill_advanced(object me, string skill)
{
    int lv = me->query_skill(skill, 1);
    switch( lv ) {
        case 189: me->set_skill_require(skill, 1500000); break; // ���d3 : 189��190
        case 149: me->set_skill_require(skill, 1000000); break; // ���d2 : 149��150
        case  99: me->set_skill_require(skill, 500000);  break; // ���d1 :  99��100
        default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

int sock(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/40;
}

// �p��H��
int check_number(object me, int sk)
{
    int number;

    if( sk >= 100 ) {
        number = (sk/40) - 1;
        if( number <= 0 ) number = 0;
    } else {
        number = 0;
    }
    return number;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int hit, meHit, targetHit;

    meHit = me->query_ability("intimidate");
    targetHit = target->query_ability("wittiness");

    me->add_temp("apply/exact", meHit);
    target->add_temp("apply/evade",  targetHit);
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("apply/exact", -meHit);
    target->add_temp("apply/evade", - targetHit);

    return hit;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk + me->query_skill("martial")/2;

    if( wp = me->query_temp("weapon/twohanded") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*4/5;
    else if( wp = me->query_temp("weapon/righthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*4/5;
    else if( wp = me->query_temp("weapon/lefthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*4/5;
    else raiseDamage -= COMBAT_D->isDamage(me, target, 0)*4/5;

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);


    return damage;
}

int autoCasting(object me, object target, object weapon)
{
    string *name = ({ "�ӻH", "�k�j�L", "�{�l", "�k�u", "�I��", "�k�p�L", "�ݤf", 
                      "���j�L", "���u", "���p�L", "�k��", "����", "�߷F", "����",
                      "���\\", "����", "�@�B", "��m", "����", "���U", "���",
                      "�{��", "�Ǥl", "�@����", "����", });

    int damage, sk, i, number, hit;
    object *targets;

    sk = me->query_skill(SKILL_NAME, 1);
    targets = me->query_enemy();

    // �P�_�O�_�Ұ�
    if( me->query_stat("mp") < 100 ) return 1;
    if( me->query_skill("martial", 1) < 60 ) return 1;
    if( sk < 40 ) return 1;

    if( sk < 80 ) {
        if( random(sk) < sk*9/10 ) return 1; // 20~80 �� 10%
    } else if( sk < 150 ) {
        if( random(sk) < sk*8/10 ) return 1; // 81~150 �� 20%
    } else {
        if( random(sk) < sk*7/10 ) return 1; // 151~200 �� 30%
    }
    // �p������H��
    number = check_number(me, sk);

    message_vision("$N�k�}������V�a���Q�X�@�D�շ�"HIW"�u�c�v"NOR"�P�ɨ��p�P�j�L�u�B��V�|�P�I"HIR"�y"HIY"���j�E��"HIR"�z"NOR"�I\n", me, target);
    for(i=0;i<sizeof(targets);i++) {
        if( i > number ) break;   // �̦h�������H
        hit = isHit(me, target);  // �R���P�_
        if( !hit ) {
            message_vision("$n���G����ݲM$N���������u�A�����S�Q����C\n", me, targets[i]);
        } else {
            damage = getDamage(me, targets[i], sk);
            targets[i]->receive_damage(damage, me);
            message_vision( sprintf("$n���l�h�B�Q$N��������ˡA"+name[random(sizeof(name))]+"���ЬƲ`�A��y����(%d) %s\n", damage, COMBAT_D->report_status(targets[i])), me, targets[i]);
        }
    }
    me->damage_stat("mp", 20*i, me);
    me->improve_skill(SKILL_NAME, 1);
    return 1;
}

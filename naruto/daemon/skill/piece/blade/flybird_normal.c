#include <ansi.h>
#define SKILL_NAME "flybird normal"
#define SKILL_NAME_C "��������"
#define SKILL_CLASS "blade"

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

int exact(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/40;
}

int attack(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

int defend(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->exact(me, target, 1) + COMBAT_D->intimidate(me, 1);
    j = COMBAT_D->evade(target, me, 1)*2;

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk;

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

// �ޯ�ϥΫ� 
void setEffect(object me, int sk, int i)
{
    me->damage_stat("mp", 10*i, me);
    me->improve_skill(SKILL_NAME, 1);
}

int autoCasting(object me, object target, object weapon)
{
    int damage, sk, i, number;
    object *targets;

    sk = me->query_skill(SKILL_NAME, 1);
    targets = me->query_enemy();

    // �P�_�O�_�Ұ�
    if( !me->query_temp("weapon/righthand") && !me->query_temp("weapon/lefthand") && !me->query_temp("weapon/twohanded")) return 1;
    if( me->query_stat("mp") < 60 ) return 1;
    if( me->query_skill("blade", 1) < 40 ) return 1;
    if( sk < 60 ) return 1;

    if( sk < 80 ) {
        if( random(sk) < sk*9/10 ) return 1;  // 20~80 �� 10%
    } else if( sk < 150 ) {
        if( random(sk) < sk*17/20 ) return 1; // 81~150 �� 15%
    } else {
        if( random(sk) < sk*8/10 ) return 1;  // 151~200 �� 20%
    }
    message_vision("\n$N���D�R"HIG"�M�k�N�Ӫ��Ӫ����I�u"+me->query("name")+HIG"�j���v�I\n\n"NOR, me, target);

    // �h�H�����P�w
    if( sk >= 100 ) {
        number = sk/50;
        message_vision("$N�e�ᴧ�ʪZ���A�o�X�ƹD���u����"HIW"�y"HIC"��������"HIW"�z"NOR"�g�V�b���ĤH�I\n", me, target);
    } else {
        number = 0;
        message_vision("$N�e�ᴧ�ʪZ���A�o�X�ƹD���u����"HIW"�y"HIC"��������"HIW"�z"NOR"�g�V$n�I\n", me, target);
    }
    for(i=0;i<sizeof(targets);i++) {
        if( i > number ) break;             // �̦h�������H
        if( !isHit(me, target) ) {
            message_vision("$n��C���l�V����{���A���}�F�����C\n", me, targets[i]);
        } else {
            damage = getDamage(me, targets[i], sk); // �ˮ`�P�_
            targets[i]->receive_damage(damage, me);
            message_vision( sprintf("�������p�������@��s��ĦV$n�y���ˮ`(%d) %s\n", damage, COMBAT_D->report_status(targets[i])), me, targets[i]);
        }
    }
    setEffect(me, sk, i);
    return 1;
}
#include <ansi.h>
#define SKILL_NAME "outfit kick"
#define SKILL_NAME_C "��ޥ��\"
#define SKILL_CLASS "spurn"

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
    return ability + me->query_skill(SKILL_NAME)/10;
}

int defend(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/5;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int hit, raiseHit;

    raiseHit = me->query_skill(SKILL_NAME, 1)/2;

    me->add_temp("apply/exact", raiseHit);
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("apply/exact", -raiseHit);

    return hit;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage;
    object wp;

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    if( sk < 100 ) return damage*30/100;       // 30%
    else if( sk < 120 ) return damage*40/100;  // 40%
    else if( sk < 150 ) return damage*50/100;  // 50%
    else if( sk < 180 ) return damage*57/100;  // 57%
    else if( sk < 199 ) return damage*63/100;  // 63%
    else return damage*75/100;                 // 75%
}

int autoCasting(object me, object target, object weapon)
{
    string *name = ({ "�Y", "��", "��", "�Ө���", "�V", "�o���V", "��", "�y",
                      "�j�L", "�W���j�L", "�I", "���", "��", "�b�U", "��",
                      "�L��", "����", "�H��", "�T�ŵ�", "�G�ŵ�", "�@�ŵ�", });

    int damage, sk;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);

    // �P�_�O�_�Ұ�
    if( target->is_busy() ) return 1;
    if( me->query_stat("mp") < sk/20 ) return 1;
    if( me->query_skill("spurn", 1) < 20 ) return 1;
    if( sk < 20 ) return 1;

    if( sk < 80 ) {
        if( random(sk) < sk*9/10 ) return 1; // 20~80 �� 10%
    } else if( sk < 150 ) {
        if( random(sk) < sk*8/10 ) return 1; // 81~150 �� 20%
    } else {
        if( random(sk) < sk*7/10 ) return 1; // 151~200 �� 30%
    }

    cnd["name"] = YEL+"�S�˪��A"+NOR;
    cnd["duration"] = 5;
    cnd["damage"] = sk/3;
    cnd["from"] = me;

    // �ˮ`�T�w
    damage = getDamage(me, target, sk);

    // �P�_�O�_���c�]���}���A
    if( me->query_condition("diabo") ) message_vision("$N�µ�$n���F�_�ӡA�@��"HIW"�y"HIR"�c�]���}�E" + name[random(sizeof(name))] + "��"HIW"�z"NOR"��V$n�I\n", me, target);
    else message_vision("$N�µ�$n���F�_�ӡA�@��"HIW"�y"HIY"" + name[random(sizeof(name))] + "��"HIW"�z"NOR"��V$n�I\n", me, target);

    if( !isHit(me, target) ) {
        if( me->query_condition("diabo") ) message_vision("�|�P�o�X�j�P���{���A���O�o�S����$N...\n", target, me);
        else message_vision("$N���l�@�n�׹L�F�o��������...\n", target);
    } else {
        if( me->query_condition("diabo") ) {
            target->set_condition("burn", cnd);
            message_vision( sprintf("�u�I�v�a�@�n�A$n���W�o�X�j�P���{���A�٤����o�X�����n(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
        } else message_vision( sprintf("$n�{�פ��ΡA�Q�𪺲��_���P...(%d)%s\n", damage, COMBAT_D->report_status(target) ), me, target);

        // �P�_�w�H�ĪG
        if( me->query_skill("spurn", 1) >= 40 ) {
            target->start_busy(1);
        }
        target->receive_damage(damage, me);
    }
    me->damage_stat("mp", sk/20, me);
    me->improve_skill(SKILL_NAME, 1);
}
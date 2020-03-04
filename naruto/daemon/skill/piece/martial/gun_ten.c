#include <ansi.h>
#define SKILL_NAME "gun ten"
#define SKILL_NAME_C "�Q���j"
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

int intimidate(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/40;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1)*2;
    j = COMBAT_D->wittiness(target, 1) + COMBAT_D->evade(target, me, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk*4 + me->query_skill("martial") + me->query_skill("gun finger");

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
                      "���\\", "����", });

    int damage, sk;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);

    // �P�_�O�_�Ұ�
    if( me->query_stat("mp") < sk/3 ) return 1;
    if( me->query_skill("martial", 1) < 160 ) return 1;
    if( me->query_skill("gun finger", 1) < 100 ) return 1;
    if( sk < 60 ) return 1;

    if( sk < 80 ) {                          // 20~80 �� 5%
        if( random(sk) < sk*19/20 ) return 1;
    } else if( sk < 150 ) {                  // 81~150 �� 10%
        if( random(sk) < sk*9/10 ) return 1;
    } else {                                 // 151~200 �� 20%
        if( random(sk) < sk*8/10 ) return 1;
    }
    message_vision("$N�N�Q�ڤ���W�U�r�X�A���$n�ϥX"HIR"�y"RED"�Q���j"HIR"�z"NOR"�Q�ڤ���@�P��V$n�I\n", me, target);
    if( !isHit(me, target) ) {
        message_vision("$n�@�Ӱj�۽��$N������A���n�N$N���������ҥ��äF�C\n", me, target);
    } else {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("�u�P�v�a���n�A$N��������i$n"+name[random(sizeof(name))]+"�d�U�F�Q�Ӳ`�`���]�K(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
        if( sk >= 120 ) {

            cnd["name"] = RED+"���媬�A"+NOR;
            cnd["duration"] = sk/20;
            cnd["from"] = me;

            target->set_condition("blood", cnd);
        }
    }
    me->damage_stat("mp", sk/3, me);
    me->improve_skill(SKILL_NAME, 1);
    return 1;
}
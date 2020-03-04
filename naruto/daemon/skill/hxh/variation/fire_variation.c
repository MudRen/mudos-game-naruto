// �ܤƨt lv1�G�����O
// -Tmr 2005/10/27
// update by Acme 2007.03.16
// �W�[���[��O by mouse 2007/7/25

#include <ansi.h>
#define SKILL_NAME "fire variation"
#define SKILL_NAME_C "�����O�ܤ�"
#define SKILL_CLASS "variation"

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

// �����O�q�v�T
int attack(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/2;
}

// �����ޥ��v�T
int intimidate(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*11/200;
}

// �O�_�R��
int isHit(object me, object target, int sk)
{
    int hit, i;

    i = sk;

    me->add_temp("exact", i);
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("exact", -i);

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

    if( sk < 100 ) return damage*3/4;          // 75%
    else if( sk < 120 ) return damage*9/10;    // 90%
    else if( sk < 150 ) return damage*11/10;   // 110%
    else if( sk < 180 ) return damage*5/4;     // 125%
    else if( sk < 199 ) return damage*7/5;     // 140%
    else return damage*3/2;                    // 150%
}

int autoCasting(object me, object target, object weapon)
{
    int hit, damage, sk;

    sk = me->query_skill(SKILL_NAME);

    // ���v 30%
    if( sk < 40 ) return 1;
    if( me->query_skill("variation") < 20 ) return 1;
    if( random(sk) < sk*7/10 ) return 1;

    // mp �������ϥ�
    if( me->query_stat("mp") < 30 ) return 1;

    // �R��
    hit = isHit(me, target, sk);

    if( !hit ) {
        message_vision("$N���W�����O�o�X�@�}�����A���O�H�Y�S���������F...\n", me);
    } else {
        // �ˮ`
        damage = getDamage(me, target, sk);

        // �ˮ`�ާl��
        damage = COMBAT_D->receive_damage(target, me, damage);

        target->receive_damage(damage, me);
        message_vision( sprintf("$N���W�����O���M���ܦ��@��"HIR"�U�N�������K"NOR"�A$n�{�פ��ΡA�Q�N�쨭�W�_�F�ƭӤ��w�F...(%d) %s\n", damage, COMBAT_D->report_status(target)), me, target);
    }
    if( sk > 150) me->damage_stat("mp", 25, me);
    else if( sk > 100) me->damage_stat("mp", 20, me);
    else me->damage_stat("mp", 15, me);

    me->improve_skill(SKILL_NAME, 1);
    return 1;
}

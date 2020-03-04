// �ܤƨt lv1�G�B���O
// -Tmr 2005/10/27
// �W�[���[��O by mouse 2007/7/25

#include <ansi.h>
#define SKILL_NAME "ice variation"
#define SKILL_NAME_C "�B���O�ܤ�"
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

// �R����O�v�T
int exact(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/20;
}

// �j�ׯ�O�v�T
int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/25;
}

// �O�_�R��
int isHit(object me, object target, int sk)
{
    int hit, i;

    i = sk/2;

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

    if( sk < 100 ) return damage/2;          // 50%
    else if( sk < 120 ) return damage*3/5;   // 60%
    else if( sk < 150 ) return damage*7/10;  // 70%
    else if( sk < 180 ) return damage*4/5;   // 80%
    else if( sk < 199 ) return damage*9/10;  // 90%
    else return damage;                      // 100%
}

int autoCasting(object me, object target, object weapon)
{
    int hit, damage, sk;

    sk = me->query_skill(SKILL_NAME);

    // ���w�H�A�o�ʲv�C�@�� 20%
    if( target->is_busy() ) return 1;
    if( sk < 20 ) return 1;
    if( me->query_skill("variation") < 40 ) return 1;
    if( random(sk) < sk*8/10 ) return 1;

    // mp �ݨD
    if( me->query_stat("mp") < 50 ) return 1;

    // �R��
    hit = isHit(me, target, sk);

    if( !hit ) {
        message_vision("$N���W�����O�o�X�@�}�ť��A���O�H�Y�S���������F...\n", me, target);
    } else {
        // �ˮ`
        damage = getDamage(me, target, sk);

        // �ˮ`�ާl��
        damage = COMBAT_D->receive_damage(target, me, damage);

        target->receive_damage(damage, me);
        message_vision( sprintf("$N���W�����O���M����"HIB"���P���H��"NOR"�A$n�{�פ��ΡA���W�n�ɦh�F�ƭӭ�H...(%d) %s\n", damage, COMBAT_D->report_status(target)), me, target);
    }

    if( sk > 150) me->damage_stat("mp", 30, me);
    else if( sk > 100) me->damage_stat("mp", 25, me);
    else me->damage_stat("mp", 20, me);

    // ���w�H�ĪG
    target->start_busy(1);

    // ���\�����h�W�[�g��
    me->improve_skill(SKILL_NAME, 1);

    return 1;
}

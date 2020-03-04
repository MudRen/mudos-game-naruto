/* �W�[��O���ɳ��� by mouse 2007/8/14 */

#include <ansi.h>
#define SKILL_NAME "muye wind"
#define SKILL_NAME_C "�줧���P��"
#define SKILL_CLASS "force"

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
    return ability + me->query_skill(SKILL_NAME)*3/40;
}

int sock(object me, object target, int ability, int type)
{
    if( me->query_skill("force", 1) >= 100 ) {
        if( me->query_skill(SKILL_NAME, 1) >= 200 ) return ability+2;
        else if( me->query_skill(SKILL_NAME, 1) >= 100 ) return ability+1;
    }
    return ability;
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
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk;

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

// �۰ʬI�i�ޡA�P�_�O�_�Ұʤ줧���P��
int autoCasting(object me, object target, object weapon)
{
    int hit, damage, sk, bsk;

    bsk = me->query_skill("force", 1);
    sk = me->query_skill(SKILL_NAME,1);

    // �P�_�O�_�Ұ�
    if( target->is_busy() ) return 1;
    if( me->query_stat("mp") < sk/20 ) return 1;
    if( bsk < 20 ) return 1;
    if( sk < 20 ) return 1;

    // ���ܲr���T�^�w�H..�o�ʲv�j�T���C
    if( sk < 80 ) {
        if( random(sk) < sk*99/100 ) return 1;     // 20~80 �� 1%
    } else if( sk < 150 ) {
        if( random(sk) < sk*19/20 ) return 1;      // 81~150 �� 5%
    } else if( random(sk) < sk*9/10 ) return 1;    // 151~200 �� 10%

    message_vision("$N���Χֳt���ʡA��$n�ϥX�@��"HIW"�y"HIY + SKILL_NAME_C + HIW"�z"NOR"����L...\n", me, target);

    // �O�_�R��
    hit = isHit(me, target);

    if( !hit ) {
        message_vision("$N����L�I���{�L�F�o�@��...\n", target);
    } else {
        damage = getDamage(me, target, sk);

        // �ˮ`�ާl��
        damage = COMBAT_D->receive_damage(target, me, damage);

        target->receive_damage(damage, me);
        message_vision( sprintf("$n�{�פ��ΡA�w�ͥͤ��F�o�ۭ��^�F�Ƥ�...(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);

        // �w�H���P�_
        if( !target->is_busy() && bsk >= 50 ) {
            if( sk >= 200 ) target->start_busy(3);
            else if( sk >= 150 ) target->start_busy(2);
            else if( sk >= 75 ) target->start_busy(1);
        }
    }
    me->damage_stat("mp", sk/10, me);
    me->improve_skill(SKILL_NAME, 1);

    return 1;
}
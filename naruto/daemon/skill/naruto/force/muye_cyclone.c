/* �W�[�@��ˮ`���� by mouse 2007/8/14 */

#include <ansi.h>
#define SKILL_NAME "muye cyclone"
#define SKILL_NAME_C "�줧���ۭ�"
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

int exact(object me, object target, int ability, int type)
{
    if( me->query_skill("force", 1) < 60 ) return ability;
    return ability + me->query_skill(SKILL_NAME)*33/200;
}

int sock(object me, object target, int ability, int type)
{
    if( me->query_skill("force", 1) >= 150 ) {
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

    if( wp = me->query_temp("weapon/twohanded") ) raiseDamage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) raiseDamage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) raiseDamage = COMBAT_D->isDamage(me, target, wp);
    else raiseDamage = COMBAT_D->isDamage(me, target, 0);

    // �۰ʧިS��k�� cd �P�_
    // ���ĪG���L���W���� sk �٭n�t�@��
    if( sk >= 181 ) {
        damage = target->query_stat_maximum("hp")*3/100;
        if( damage > 750 ) damage = 750;
    } else if( sk >= 101 ) {
        damage = target->query_stat_maximum("hp")*2/100;
        if( damage > 500 ) damage = 500;
    } else {
        damage = target->query_stat_maximum("hp")/100;
        if( damage > 500 ) damage = 250;
    }

    // �򥻶ˮ`�����N�����v�T
    damage += raiseDamage/4;

    return damage;
}

// �۰ʬI�i�ޡA�P�_�O�_�n�h���@�U
int autoCasting(object me, object target, object weapon)
{
    int hit, damage, sk, bsk;

    bsk = me->query_skill("force", 1);
    sk = me->query_skill(SKILL_NAME,1);

    // �P�_�O�_���\�o��
    if( me->query_stat("mp") < sk/10 ) return 1;
    if( bsk < 80 ) return 1;
    if( sk < 30 ) return 1;

    if( sk < 80 ) {
        if( random(sk) < sk*9/10 ) return 1;     // 20~80 �� 10%
    } else if( sk < 150 ) {
        if( random(sk) < sk*8/10 ) return 1;     // 81~150 �� 20%
    } else if( random(sk) < sk*7/10 ) return 1;  // 151~200 �� 30%

    message_vision("$N�}�B�ֳt����¶��$n�A��M�@��"HIW"�y"HIG + SKILL_NAME_C + HIW"�z"NOR"��$n����...\n", me, target);

    // �O�_�R��
    hit = isHit(me, target);

    if( !hit ) {
        message_vision("$N����L�I���{�L�F�o�@��...\n", target);
    } else {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("$n�S��S���}�A�Q���o�R�X�@�f�A��...(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
    }
    me->damage_stat("mp", sk/5, me);
    me->improve_skill(SKILL_NAME, 1);

    return 1;
}
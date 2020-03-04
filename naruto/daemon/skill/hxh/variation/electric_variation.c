// �ܤƨt lv1�G�q���O
// -Tmr 2005/10/27

// 2006/06/04 -Tmr
// update by Acme 2007.03.16
// �W�[���[��O by mouse 2007/7/25

#include <ansi.h>
#define SKILL_NAME "electric variation"
#define SKILL_NAME_C "�q���O�ܤ�"
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

// ���m�ޥ��v�T
int wittiness(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/20;
}

// �����O�q�v�T
int attack(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/40;
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

    if( sk < 100 ) return damage/4;          // 25%
    else if( sk < 120 ) return damage*7/25;  // 28%
    else if( sk < 150 ) return damage/3;     // 33%
    else if( sk < 180 ) return damage*13/50; // 36%
    else if( sk < 199 ) return damage*2/5;   // 40%
    else return damage*50/100;               // 50%

    return damage;
}

int autoCasting(object me, object target, object weapon)
{
    int hit, damage, i, sk;
    object *targets;

    sk = me->query_skill(SKILL_NAME);
    targets = me->query_enemy();

    // ���v 30%
    if( sk < 30 ) return 1;
    if( me->query_skill("variation") < 30 ) return 1;
    if( random(sk) < sk*7/10 ) return 1;

    // mp �������ϥ�
    if( me->query_stat("mp") < 50 ) return 1;

    message_vision("$N���W�����O���M���ܦ�"HIC"�b�H���q��"NOR"...\n", me, target);

    for(i=0;i<sizeof(targets);i++) {
        if( i > 2 ) break;                 // �u��T�ӤH����
        hit = isHit(me, targets[i], sk);   // �R��

        if( !hit ) {
            message_vision("$n�׶}�F�����A�a�W�N�X�@�I�J�¡C\n", me, targets[i]);
        } else {
            damage = getDamage(me, targets[i], sk);  // �ˮ`

            // �ˮ`�ާl��
            damage = COMBAT_D->receive_damage(targets[i], me, damage);

            targets[i]->receive_damage(damage, me);
            message_vision( sprintf("$n�@�n�G�s�A���W�ǥX�}�}�J��...(%d) %s\n", damage, COMBAT_D->report_status(targets[i])), me, targets[i]);
        }
    }
    me->improve_skill(SKILL_NAME, 1);

    if( sk > 150 ) me->damage_stat("mp", 35, me);
    else if( sk > 100 ) me->damage_stat("mp", 25, me);
    else me->damage_stat("mp", 15, me);

    return 1;
}
// chain_lighting.c �ܤƨt lv2 - �s��{�q
// 2006/06/04 -Tmr
// update by Acme 2007.03.16
// �s�W�S��ޯ� by mouse 2007/7/25

#include <ansi.h>
#define SKILL_NAME "chain lighting"
#define SKILL_NAME_C "�s��{�q"
#define SKILL_CLASS "variation"

inherit SKILL;

int number=0, attack;

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

/*
|       �ޯ�v�T�G
|                �ޯ�G 0------50------100------150---175---200
|            �ĤH�ƶq�G     1      2        3       4     5
|            �ˮ`�t�ơG 50% ---------------------------> 90%
|
*/

/*
|       �ק�᪺���A�G 2007/7/25
|
|       �ˮ`�P�w���p��̰��ˮ`�A�q�̰��ˮ`����X�Ʀr�����ˮ`
|       �̫�@�ӼĤH�|�N�ҳѪ��ˮ`�����α��A�{�L���|���O�ˮ`��
*/

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, object target)
{
    if( !objectp(me) || !objectp(target) ) return 0;

    if( act != "chain" ) {
        tell_object(me, SKILL_NAME_C + "�ثe�u�� chain �\\��C\n");
        return 0;
    }

    if( me->is_busy() ) {
        tell_object(me, "�A�����ۡA�S���Ũϥγo�ӧޯ�C\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "�A�å��M���b�԰���...\n");
        return 0;
    }

    if( me->query_skill("variation", 1) < 80 ) {
        tell_object(me, "�A���ܤƨt�{���٨S�F�� 80 �šA�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_skill("electric variation", 1) < 50 ) {
        tell_object(me, "�A���q���O�ܤ��٨S�F�� 50 �šA�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_stat("mp") < 100 ) {
        tell_object(me, "�A������O���� 100 �I�C\n");
        return 0;
    }

    if( me->query_condition("chain_cd") ) {
        tell_object(me, "�A�ثe�ٵL�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }
    return 1;
}

int get_times(int lv)
{
    if( lv <= 50 ) return 1;
    if( lv <= 100 ) return 2;
    if( lv <= 150 ) return 3;
    if( lv <= 175 ) return 4;
    if( lv <= 200 ) return 5;
    return 0;
}

void do_attack(object me, object target, int times)
{
    int hit, raiseHit, i, raiseDamage, damage;
    object wp;

    i = me->query_skill(SKILL_NAME)/4;

    // �R���v�A�q�t�y�L��lv�v�T�R��
    raiseHit = me->add_temp("exact", i);
    hit = COMBAT_D->isHit(me, target);
    raiseHit = me->add_temp("exact", -i);

    if( number >= times ) {
        raiseDamage = attack;
    } else {
        raiseDamage = random(attack)/2;
    }
    if( hit ) {
        number += 1;

        me->add_temp("apply/attack", raiseDamage); 

        if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
        else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
        else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
        else damage = COMBAT_D->isDamage(me, target, 0);

        me->add_temp("apply/attack", -raiseDamage);

        attack -= raiseDamage;

        // �ˮ`�ާl���P�_���b�O�d�ˮ`
        damage = COMBAT_D->receive_damage(target, me, damage);

        target->receive_damage(damage, me);
        message_vision( sprintf(HIW"�o�D�{�q�ֳt�a��z�L$n������A$n�o�X�@�}�Y�F���s�n.."NOR"(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
    } else {
        number += 1;
        message_vision("$N"NOR"�����k�L�o�D�{�q�������F...\n", target);
    }
}

void do_shoot(object me, object target)
{
    int i, j, times, ntar;
    object* targets;
    mapping cnd = ([]);

    targets = me->query_enemy();
    ntar = sizeof(targets);

    times = get_times(me->query_skill(SKILL_NAME));
    attack = me->query_skill(SKILL_NAME)*2 + me->query_skill("electric variation")/2 + me->query_skill("variation")/2;

    message_vision(HIC"\n�@�D���@�T���p�q�q$N���W«�X�A���ĦV$n"HIC"�I�I�I\n\n"NOR, me, target);
    number = 1;

    for(i=0,j=0;i<times;i++,j++) {
        if( j == ntar ) j = 0;    // ���@��
        do_attack(me, targets[j], times);
    }
    cnd["name"] = HIC+"(CD)�{�q"+NOR;
    cnd["duration"] = 6;

    // ���ެO�_���������Ӧ�cd
    me->set_condition("chain_cd", cnd);

    // ���� msg
    message_vision(HIC"\n�Ѿl�� "+attack+" �˹q���ƴ��b�Ů�...\n\n"NOR, me);
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    if( !isCast(me, act, target) ) return 1;

    do_shoot(me, target);

    me->improve_skill(SKILL_NAME, 1);
    me->damage_stat("mp", 60, me);
    me->start_busy(2);
    return 1;
}

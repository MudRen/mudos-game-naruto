// psychical_bullet.c ��X�t-���u
// 2005/10/23 -Tmr
// �ק� by mouse 2007/7/25

#include <ansi.h>
#define SKILL_NAME "psychical bullet"
#define SKILL_NAME_C "���u"
#define SKILL_CLASS "emit"

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

// �P�R�@���v�T
int sock(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/20;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, object target)
{
    if( !objectp(me) || !objectp(target) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "shoot" ) {
        tell_object(me, "�ثe���u�u�� shoot �\\��C\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "�A�å��M���b�԰���...\n");
        return 0;
    }

    if( me->query_skill("emit") < 40 ) {
        tell_object(me, "�A����X�t�{���٨S�F�� 40 �šA�٤����H�o�g���u�C\n");
        return 0;
    }

    if( me->query_skill(SKILL_NAME) < 20 ) {
        tell_object(me, "�A�����u���Ť����H�ϥΧޯ�C\n");
        return 0;
    }

    if( me->query_stat("mp") < 50 || me->query_stat("ap") < 50) {
        tell_object(me, "�A���骬�p���ΡA����ϥΩ��u�C\n");
        return 0;
    }
    return 1;
}

// ���o�ˮ`
int getDamage(object me, object target, int bonus)
{
    int raiseDamage, damage;
    object wp;

    if( bonus == 100 ) { // ���u���p��
        raiseDamage = me->query_skill(SKILL_NAME)*3 + me->query_skill("emit");
    } else {
        raiseDamage = bonus + (me->query_skill(SKILL_NAME) + me->query_skill("emit"))/2;

        // �s��������ִ�����C���s�����v�T
        // ��������j�̦h 6 �s�A4�s��~�����ݥX�v�T�¤O
        if( wp = me->query_temp("weapon/twohanded") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
        else if( wp = me->query_temp("weapon/righthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
        else if( wp = me->query_temp("weapon/lefthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
        else raiseDamage -= COMBAT_D->isDamage(me, target, 0)*3/4;
    }
    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);
    return damage;
}

void do_shoot(object me, object target, int bonus)
{
    int damage, hit;

    damage = getDamage(me, target, bonus);

    // �R���v
    hit = COMBAT_D->isHit(me, target);

    // ���]�L�ˮ`�ާl��
    damage = COMBAT_D->receive_damage(target, me, damage);

    if( bonus == 100 ) {
        message_vision("\n$N����Y���ʡA�g�X�j�Ӧ��O��"HIW"���u"NOR"�A����$n"NOR"���W�n�`...\n"NOR, me, target);
    }
    if( hit ) {
        target->receive_damage(damage, me);
        message_vision( sprintf("$n�{�פ��ΡA���F�@�o���u...(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
    } else {
        message_vision("$N���I�a���L�F���u������...\n", target);
        if( me->query_temp("psychical_busy") ) me->add_temp("psychical_busy", 1);
        else me->set_temp("psychical_busy", 1);
    }
}

// �p��Ĳ�ʪ����v
/*
�ޯস�Ƽv�T�G
        �ޯ�G 0------50------100------150------200
        ���v�G    15%    30%      35%      60%
        ���ơG     2      4        5       6
*/
int trigger_machine_gun(int lv) {
    if( lv < 10 ) return 0;
    if( lv <= 50 ) return ( random(100) < 15 );
    if( lv <= 100 ) return ( random(100) < 30 );
    if( lv <= 150 ) return ( random(100) < 45 );
    if( lv <= 200 ) return ( random(100) < 60 );
    return 0;
}

int get_gun_times(int lv)
{
    if( lv <= 50 ) return 2;
    if( lv <= 100 ) return 4;
    if( lv <= 150 ) return 5;
    if( lv <= 200 ) return 6;
    return 0;
}

int get_gun_bonus(int lv)
{
    if( lv < 40 ) return 40;
    return ( lv - 40 ) + 40;
}

// �ޯ�ϥΫ� 
void setEffect(object me, int bonus, int times)
{
    if( bonus != 100 ) {
        me->improve_skill("machine gun", 1);
        me->damage_stat("mp", 20*times, me);
        if( me->query_temp("psychical_busy") > 2 ) {
            me->start_busy(6);
        } else {
            me->start_busy(4);
        }
    } else {
        me->improve_skill(SKILL_NAME, 1);
        if( me->query_skill(SKILL_NAME) > 150 ) me->damage_stat("mp", 45, me);
        else if( me->query_skill(SKILL_NAME) > 100 ) me->damage_stat("mp", 35, me);
        else me->damage_stat("mp", 25, me);
        me->start_busy(3);
    }
    // �ƪ��Ϊ� msg
    message_vision("\n", me);
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    int machine_gun_lv;

    // ²�d�ޯ�ϥ�
    if( !isCast(me, act, target) ) return 1;

    // �[�W rank 2�ޯ�:
    // ��������j (machine gun) ���v�T 2006/06/04
    machine_gun_lv = me->query_skill("machine gun");

    if( me->query_stat("ap") > 200 && trigger_machine_gun(machine_gun_lv) ) {
        int i, times, bonus;
        times = get_gun_times(machine_gun_lv);
        bonus = get_gun_bonus(machine_gun_lv);

        message_vision(HIY"\n$N�y�W�S�X���c�����e�A���X�Q�ڤ���Y���$n"HIY"�I�I�I\n\n"NOR, me, target);
        message_vision("�u"HIB"����"HIR"�����j"NOR"�v$N���زu������F���I�����q����g�X���u�I\n"NOR, me, target);
        for(i=0;i<times;i++) {
            do_shoot(me, target, bonus);
        }
        setEffect(me, bonus, times);
    } else {
        do_shoot(me, target, 100);
        setEffect(me, 100, 1);
    }
    return 1;
}

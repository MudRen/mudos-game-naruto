// psychical_bullet.c ��X�t-���u
// 2005/10/23 -Tmr

#include <ansi.h>

#define SKILL_NAME "psychical bullet"

inherit SKILL;

// ���Φb force �W
int valid_enable(string base_skill) { return base_skill=="emit"; }

string query_class() { return "psychical"; }

void create()
{
    seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
    setup();
}

string report_status(object ob)
{
    int ratio;

    if( !ob->query_stat_maximum("hp") ) return "\n";

    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");

    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}


void do_shoot(object me, object target, int bonus)
{
        int attack, hit;
        /* �����O */
        // �ϥ� ability_attack �N���üƤF�A����ϥ� query_ability("attack")
    attack = me->ability_attack("attack");
        if( bonus == 100 ) {
                // ���u�������O�[�v
                if(  me->query_skill( SKILL_NAME, 1) < 50 ) {
                        // 75%
                        attack = attack*3/4;
                }
                else if(  me->query_skill( SKILL_NAME, 1) < 100 ) {
                        // 100%
                }
                else if(  me->query_skill( SKILL_NAME, 1) < 150 ) {
                        // 125%
                        attack = attack*5/4;
                }
                else  { 
                        attack = attack*3/2;
                }
        } else {
                // ��������j�������O�[�v
                attack = attack * bonus/100;
        }

        attack -= target->query_ability("defend");

        /* �R���v */
    hit = me->query_ability("exact") - target->query_ability("evade");

    if( hit < 10 ) hit = 10;
    else if( hit > 90 ) hit = 90;

    if( attack <= 10 ) attack = 10;

    message_vision("$N����Y���ʡA�g�X�j�Ӧ��O��"HIW"���u"NOR"�A����$n"NOR"���W�n�`...\n"NOR, me, target);

    if( random(100) < hit ) {
        // �Ѧ��禡�����ˮ`�A�H�Kfight�Ҧ��U�y���ˤ`
        target->receive_damage(attack, me);
        message_vision( sprintf("\t$n�{�פ��ΡA���F�@�o���u...(%d)%s",  attack, report_status(target) ), me, target);
        // ���\�����h�W�[�g��
        me->improve_skill("combat", 1);
        me->improve_skill(SKILL_NAME, 1);
    } else {
        message_vision("\t$N���I�a���L�F���u������...\n", target);
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

int get_gun_times(int lv) {
        if( lv <= 50 ) return 2;
        if( lv <= 100 ) return 4;
        if( lv <= 150 ) return 5;
        if( lv <= 200 ) return 6;
        return 0;
}

int get_gun_bonus(int lv) {
        if(lv < 5 ) return 40;
        return (lv/5) + 40;
}

// �ϥε���
int perform_action(object me, string act, object target)
{
        int machine_gun_lv;

    if( !objectp(me) || !objectp(target) ) return 0;

    if( me->is_busy() ) return notify_fail("�A�{�b�S���ŨϥΩ��u�C\n");
    if( act != "shoot" ) return notify_fail("�ثe���u�u�� shoot �\\��C\n");

    if( !me->is_fighting(target) ) return notify_fail("�A�å��M���b�԰���...\n");

    if( me->query_skill("combat", 1) < 60 ) return notify_fail("�A���氫�ޥ��٨S�F��60�šA�L�k�ϥΩ��u�C\n");
    if( me->query_skill("continual hit", 1) < 40 ) notify_fail("�A���s�����N�٨S�F��40�šA�L�k�ϥΩ��u�C\n");
        if( me->query_skill("emit", 1) < 40 ) return notify_fail("�A����X�t�{���٨S�F��40�šA�٤����H�o�g���u�C\n");

    if( me->query_stat("mp") < 50 || me->query_stat("ap") < 50)
         return notify_fail("�A���骬�p���ΡA����ϥΩ��u�C\n");

        /* �[�W rank 2�ޯ�: ��������j (machine gun) ���v�T
                2006/06/04
        */
        machine_gun_lv = me->query_skill("machine gun");
        if( me->query_stat("ap") > 200 && trigger_machine_gun(machine_gun_lv) ) {

                int i, times, bonus;
                times = get_gun_times(machine_gun_lv);
                bonus = get_gun_bonus(machine_gun_lv);

            message_vision( HIY"\n$N�y�W�S�X���c�����e�A���X�Q�ڤ���Y���$n"HIY"�I�I�I\n\n"NOR, me, target);

                for(i=0;i<times;i++) {
                        do_shoot(me, target, bonus );
                }

        me->improve_skill("machine gun", 1);
                me->damage_stat("mp", 20*times, me);
            me->start_busy(2);
        } else {
                do_shoot(me, target, 100);
            me->start_busy(1);
        }

        if( me->query_skill( SKILL_NAME) > 150 )
                me->damage_stat("mp", 45, me);
        else if( me->query_skill( SKILL_NAME) > 100 )
                me->damage_stat("mp", 35, me);
        else
                me->damage_stat("mp", 25, me);

    return 1;
}

// �ޯ�W�[�g��, ���ݰ��䥦��
void skill_improved(object me, string skill) { }

// �ޯ�ɯū�|�I�s���禡�A���n�I
void skill_advanced(object me, string skill)
{
    // �b�o�̳]�w�ޯ�U���ɯũһݪ��g��

    int lv;

    lv = me->query_skill(skill, 1);                                     // �ޯ൥��

    switch( lv ) {
        case 189: me->set_skill_require(skill, 3000000); break; // ���d3 : 189��190
        case 149: me->set_skill_require(skill, 2000000); break; // ���d2 : 149��150
        case  99: me->set_skill_require(skill, 1000000); break; // ���d1 :  99��100
        default:  me->set_skill_require(skill, lv*lv*15); break;
    }
}



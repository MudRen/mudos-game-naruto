// psychical_bullet.c 放出系-念彈
// 2005/10/23 -Tmr

#include <ansi.h>

#define SKILL_NAME "psychical bullet"

inherit SKILL;

// 應用在 force 上
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
        /* 攻擊力 */
        // 使用 ability_attack 就有亂數了，不能使用 query_ability("attack")
    attack = me->ability_attack("attack");
        if( bonus == 100 ) {
                // 念彈的攻擊力加權
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
                // 雙手機關槍的攻擊力加權
                attack = attack * bonus/100;
        }

        attack -= target->query_ability("defend");

        /* 命中率 */
    hit = me->query_ability("exact") - target->query_ability("evade");

    if( hit < 10 ) hit = 10;
    else if( hit > 90 ) hit = 90;

    if( attack <= 10 ) attack = 10;

    message_vision("$N手指頭撥動，射出強而有力的"HIW"念彈"NOR"，直攻$n"NOR"身上要害...\n"NOR, me, target);

    if( random(100) < hit ) {
        // 由此函式接受傷害，以免fight模式下造成傷亡
        target->receive_damage(attack, me);
        message_vision( sprintf("\t$n閃避不及，中了一發念彈...(%d)%s",  attack, report_status(target) ), me, target);
        // 成功擊中則增加經驗
        me->improve_skill("combat", 1);
        me->improve_skill(SKILL_NAME, 1);
    } else {
        message_vision("\t$N驚險地躲過了念彈的攻擊...\n", target);
    }
}

// 計算觸動的機率
/*
技能次數影響：
        技能： 0------50------100------150------200
        機率：    15%    30%      35%      60%
        次數：     2      4        5       6
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

// 使用絕招
int perform_action(object me, string act, object target)
{
        int machine_gun_lv;

    if( !objectp(me) || !objectp(target) ) return 0;

    if( me->is_busy() ) return notify_fail("你現在沒有空使用念彈。\n");
    if( act != "shoot" ) return notify_fail("目前念彈只有 shoot 功\能。\n");

    if( !me->is_fighting(target) ) return notify_fail("你並未和對方在戰鬥中...\n");

    if( me->query_skill("combat", 1) < 60 ) return notify_fail("你的格鬥技巧還沒達到60級，無法使用念彈。\n");
    if( me->query_skill("continual hit", 1) < 40 ) notify_fail("你的連擊之術還沒達到40級，無法使用念彈。\n");
        if( me->query_skill("emit", 1) < 40 ) return notify_fail("你的放出系程度還沒達到40級，還不足以發射念彈。\n");

    if( me->query_stat("mp") < 50 || me->query_stat("ap") < 50)
         return notify_fail("你身體狀況不佳，不能使用念彈。\n");

        /* 加上 rank 2技能: 雙手機關槍 (machine gun) 的影響
                2006/06/04
        */
        machine_gun_lv = me->query_skill("machine gun");
        if( me->query_stat("ap") > 200 && trigger_machine_gun(machine_gun_lv) ) {

                int i, times, bonus;
                times = get_gun_times(machine_gun_lv);
                bonus = get_gun_bonus(machine_gun_lv);

            message_vision( HIY"\n$N臉上露出邪惡的笑容，伸出十根手指頭對準$n"HIY"！！！\n\n"NOR, me, target);

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

// 技能增加經驗, 不需做其它事
void skill_improved(object me, string skill) { }

// 技能升級後會呼叫此函式，必要！
void skill_advanced(object me, string skill)
{
    // 在這裡設定技能下次升級所需的經驗

    int lv;

    lv = me->query_skill(skill, 1);                                     // 技能等級

    switch( lv ) {
        case 189: me->set_skill_require(skill, 3000000); break; // 關卡3 : 189升190
        case 149: me->set_skill_require(skill, 2000000); break; // 關卡2 : 149升150
        case  99: me->set_skill_require(skill, 1000000); break; // 關卡1 :  99升100
        default:  me->set_skill_require(skill, lv*lv*15); break;
    }
}



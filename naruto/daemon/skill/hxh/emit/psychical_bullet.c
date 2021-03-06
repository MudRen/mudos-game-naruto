// psychical_bullet.c 放出系-念彈
// 2005/10/23 -Tmr
// 修改 by mouse 2007/7/25

#include <ansi.h>
#define SKILL_NAME "psychical bullet"
#define SKILL_NAME_C "念彈"
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
        case 189: me->set_skill_require(skill, 1500000); break; // 關卡3 : 189升190
        case 149: me->set_skill_require(skill, 1000000); break; // 關卡2 : 149升150
        case  99: me->set_skill_require(skill, 500000);  break; // 關卡1 :  99升100
        default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

// 致命一擊影響
int sock(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/20;
}

// 檢查是否能使用技能
int isCast(object me, string act, object target)
{
    if( !objectp(me) || !objectp(target) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "你現在沒有空使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( act != "shoot" ) {
        tell_object(me, "目前念彈只有 shoot 功\能。\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "你並未和對方在戰鬥中...\n");
        return 0;
    }

    if( me->query_skill("emit") < 40 ) {
        tell_object(me, "你的放出系程度還沒達到 40 級，還不足以發射念彈。\n");
        return 0;
    }

    if( me->query_skill(SKILL_NAME) < 20 ) {
        tell_object(me, "你的念彈等級不足以使用技能。\n");
        return 0;
    }

    if( me->query_stat("mp") < 50 || me->query_stat("ap") < 50) {
        tell_object(me, "你身體狀況不佳，不能使用念彈。\n");
        return 0;
    }
    return 1;
}

// 取得傷害
int getDamage(object me, object target, int bonus)
{
    int raiseDamage, damage;
    object wp;

    if( bonus == 100 ) { // 念彈的計算
        raiseDamage = me->query_skill(SKILL_NAME)*3 + me->query_skill("emit");
    } else {
        raiseDamage = bonus + (me->query_skill(SKILL_NAME) + me->query_skill("emit"))/2;

        // 連擊部份減少普擊對每次連擊的影響
        // 雙手機關槍最多 6 連，4連後才比較能看出影響威力
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

    // 命中率
    hit = COMBAT_D->isHit(me, target);

    // 先跑過傷害盾吸收
    damage = COMBAT_D->receive_damage(target, me, damage);

    if( bonus == 100 ) {
        message_vision("\n$N手指頭撥動，射出強而有力的"HIW"念彈"NOR"，直攻$n"NOR"身上要害...\n"NOR, me, target);
    }
    if( hit ) {
        target->receive_damage(damage, me);
        message_vision( sprintf("$n閃避不及，中了一發念彈...(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
    } else {
        message_vision("$N驚險地躲過了念彈的攻擊...\n", target);
        if( me->query_temp("psychical_busy") ) me->add_temp("psychical_busy", 1);
        else me->set_temp("psychical_busy", 1);
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

// 技能使用後 
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
    // 排版用的 msg
    message_vision("\n", me);
}

// 使用絕招
int perform_action(object me, string act, object target)
{
    int machine_gun_lv;

    // 簡查技能使用
    if( !isCast(me, act, target) ) return 1;

    // 加上 rank 2技能:
    // 雙手機關槍 (machine gun) 的影響 2006/06/04
    machine_gun_lv = me->query_skill("machine gun");

    if( me->query_stat("ap") > 200 && trigger_machine_gun(machine_gun_lv) ) {
        int i, times, bonus;
        times = get_gun_times(machine_gun_lv);
        bonus = get_gun_bonus(machine_gun_lv);

        message_vision(HIY"\n$N臉上露出邪惡的笑容，伸出十根手指頭對準$n"HIY"！！！\n\n"NOR, me, target);
        message_vision("「"HIB"雙手"HIR"機關槍"NOR"」$N面目猙獰殺紅了眼！不停從手指射出念彈！\n"NOR, me, target);
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

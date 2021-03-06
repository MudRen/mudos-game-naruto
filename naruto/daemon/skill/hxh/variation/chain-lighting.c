// chain_lighting.c 變化系 lv2 - 連鎖閃電
// 2006/06/04 -Tmr
// update by Acme 2007.03.16
// 新增特殊技能 by mouse 2007/7/25

#include <ansi.h>
#define SKILL_NAME "chain lighting"
#define SKILL_NAME_C "連鎖閃電"
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
        case 189: me->set_skill_require(skill, 1500000); break; // 關卡3 : 189升190
        case 149: me->set_skill_require(skill, 1000000); break; // 關卡2 : 149升150
        case  99: me->set_skill_require(skill, 500000);  break; // 關卡1 :  99升100
        default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

/*
|       技能影響：
|                技能： 0------50------100------150---175---200
|            敵人數量：     1      2        3       4     5
|            傷害系數： 50% ---------------------------> 90%
|
*/

/*
|       修改後的狀態： 2007/7/25
|
|       傷害判定為計算最高傷害，從最高傷害中抽出數字給予傷害
|       最後一個敵人會將所剩的傷害全部用掉，閃過不會浪費傷害值
*/

// 檢查是否能使用技能
int isCast(object me, string act, object target)
{
    if( !objectp(me) || !objectp(target) ) return 0;

    if( act != "chain" ) {
        tell_object(me, SKILL_NAME_C + "目前只有 chain 功\能。\n");
        return 0;
    }

    if( me->is_busy() ) {
        tell_object(me, "你正忙著，沒有空使用這個技能。\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "你並未和對方在戰鬥中...\n");
        return 0;
    }

    if( me->query_skill("variation", 1) < 80 ) {
        tell_object(me, "你的變化系程度還沒達到 80 級，無法使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( me->query_skill("electric variation", 1) < 50 ) {
        tell_object(me, "你的電念力變化還沒達到 50 級，無法使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( me->query_stat("mp") < 100 ) {
        tell_object(me, "你的念能力不足 100 點。\n");
        return 0;
    }

    if( me->query_condition("chain_cd") ) {
        tell_object(me, "你目前還無法使用" + SKILL_NAME_C + "。\n");
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

    // 命中率，電系稍微用lv影響命中
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

        // 傷害盾吸收判斷不在保留傷害
        damage = COMBAT_D->receive_damage(target, me, damage);

        target->receive_damage(damage, me);
        message_vision( sprintf(HIW"這道閃電快速地穿透過$n的身體，$n發出一陣淒厲的叫聲.."NOR"(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
    } else {
        number += 1;
        message_vision("$N"NOR"堪堪逃過這道閃電的攻擊了...\n", target);
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

    message_vision(HIC"\n一道嗤嗤作響的雷電從$N身上竄出，直衝向$n"HIC"！！！\n\n"NOR, me, target);
    number = 1;

    for(i=0,j=0;i<times;i++,j++) {
        if( j == ntar ) j = 0;    // 輪一圈
        do_attack(me, targets[j], times);
    }
    cnd["name"] = HIC+"(CD)閃電"+NOR;
    cnd["duration"] = 6;

    // 不管是否擊中都應該有cd
    me->set_condition("chain_cd", cnd);

    // 結束 msg
    message_vision(HIC"\n剩餘的 "+attack+" 瓦電氣飄散在空氣中...\n\n"NOR, me);
}

// 使用絕招
int perform_action(object me, string act, object target)
{
    if( !isCast(me, act, target) ) return 1;

    do_shoot(me, target);

    me->improve_skill(SKILL_NAME, 1);
    me->damage_stat("mp", 60, me);
    me->start_busy(2);
    return 1;
}

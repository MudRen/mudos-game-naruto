#include <ansi.h>
#define SKILL_NAME "drench"
#define SKILL_NAME_C "滂沱大雨"
#define SKILL_CLASS "activity"

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

int wittiness(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// 檢查是否能使用技能
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) || !objectp(target) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "你現在沒有空使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( act != "assoil" ) {
        tell_object(me, "目前" + SKILL_NAME_C + "只有 assoil 功\能。\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "你並未和對方在戰鬥中...\n");
        return 0;
    }

    if( me->query_condition("drench_cd") ) {
        tell_object(me, "目前閃電聚集還不夠完整。\n");
        return 0;
    }

    if( me->query_skill("activity", 1) < 80 || sk < 40 ) {
        tell_object(me, "你的能力不足以使用這一招。\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/10 ) {
        tell_object(me, "你身體狀況不佳，不能使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    return 1;
}

// 計算是否命中
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1)*2;
    j = COMBAT_D->evade(target, me, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// 技能使用後 
void setEffect(object me, object target, int sk, int hit)
{
    if( hit || target->query_condition("rain") ) {
        me->start_busy(1);
    } else {
        me->start_busy(2);
    }
    me->damage_stat("mp", sk/10, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int damage, sk, hit;
    object staff;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);

    // 檢查是否能使用技能
    if( !isCast(me, act, target, sk) ) return 1;

    if( !objectp(staff = present("_WEATHER_", me)) ) return notify_fail("你身上沒有天候棒怎麼用技能。\n");

    if( !target->query_condition("rain", 1) ) {
        message_vision("\n$N說道："HIG"今日天氣將有雷雨，需注意影響視線。\n"NOR, me, target);
    }
    message_vision("\n$N使出"HIW"『"HIB"滂沱大雨"HIW"』"NOR"手上的"+staff->query("name")+"一揮，朝$n噴出大量的黑雲...。\n"NOR, me, target);

    // 判斷有沒有下雨，已經下雨就不再中特殊狀態，且攻擊命中率 100%
    // 傷害少而且有烏雲的判斷，就不再做基本傷害計算了
    if( target->query_condition("rain", 1) != 0) {
        damage = random(sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("黑雲中放出細小的閃電擊中了$n....(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);

        cnd["name"] = HIB+"(CD)雷雨"+NOR;
        cnd["duration"] = 2;

        me->set_condition("drench_cd", cnd);

    } else {

        // 判斷命中
        hit = isHit(me, target);

        if( !hit ) {
            message_vision("但是雲層似乎不夠完整，並沒有下雨。\n\n", target);
        } else {
            message_vision("黑雲覆蓋\在$n的頭頂，嘩啦一聲下起傾盆大雨，影響了$n的視線。\n\n", me, target);

            cnd["name"] = HIB+"雷雨影響"+NOR;
            cnd["duration"] = sk/4;
            cnd["intimidate"] = sk/5;
            cnd["exact"] = sk/3;

            target->set_condition("rain", cnd);
        }
    }
    setEffect(me, target, sk, hit);
    return 1;
}

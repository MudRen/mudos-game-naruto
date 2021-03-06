#include <ansi.h>
#define SKILL_NAME "hair order"
#define SKILL_NAME_C "毛髮念控"
#define SKILL_CLASS "operation"

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

// 命中能力影響
int exact(object me, object target, int ability, int type)
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

    if( act != "lunge" ) {
        tell_object(me, "目前" + SKILL_NAME_C + "只有 lunge 功\能。\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "你並未和對方在戰鬥中...\n");
        return 0;
    }

    if( me->query_skill("operation", 1) < 40 || sk < 60 ) {
        tell_object(me, "你的技能程度無法使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/5 ) {
        tell_object(me, "你身體狀況不佳，不能使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( target->query_condition("hairstick", 1) != 0) {
        tell_object(me, "對手已經中招了，等會再用吧。\n");
        return 0;
    }
    return 1;
}

// 取得傷害
int getDamage(object me, object target)
{
    int raiseDamage, damage;
    object wp;

    raiseDamage = me->query_skill(SKILL_NAME) + me->query_skill("operation")/2;
    me->add_temp("apply/attack", raiseDamage); 

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);
    damage = (damage*100)/(400-raiseDamage);

    return damage;
}

// 迴避能力影響
int evade(object me, object target, int ability, int type)
{
    int damage;

    if( !target->query_condition("hairstick", 1) ) return ability;

    if( random(3) != 1 ) {
        damage = getDamage(me, target);
        target->receive_damage(damage, me);
        message_vision("\n$N"HIW"隨意行動使"NOR"利刃般的毛髮"HIW"刺傷了$N"HIR"("+damage+")\n"NOR, target);
    }
    return ability;
}

// 能在傷害前跑出，用於製作無敵或盾防禦
int receiveDamage(object me, object target, int damage)
{
    int Adamage;

    if( !target->query_condition("hairstick", 1) ) return damage;

    if( COMBAT_D->isHit(me, target) ) {
        Adamage = getDamage(me, target);
        target->receive_damage(Adamage, me);
        message_vision("\n$N"HIW"隨意的行動使"NOR"利刃般的毛髮"HIW"刺傷了$N"HIR"("+Adamage+")\n"NOR, target);
    }
    return damage;
}

int perform_action(object me, string act, object target)
{
    mapping cnd = ([]);
    int sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    if( !isCast(me, act, target, sk) ) return 1;

    hit = COMBAT_D->isHit(me, target);

    message_vision("$N"HIW"忽然將雙手伸直，"NOR+BLINK"全身的頭髮纖毛"NOR+HIW"居然有如細針般刺向"NOR"$n！\n"NOR, me, target);
    if( !hit ) {
        message_vision("\t但是$n不斷的向後移動，最後逃出了$N的攻擊範圍。\n", me, target);
        me->damage_stat("mp", sk/10, me);
        me->start_busy(2);
        return 1;
    } else {
        message_vision("\t$n閃避不急，被$N的毛髮刺穿全身，只要隨便移動就會受到傷害！\n"NOR, me, target);
        me->damage_stat("mp", sk/5, me);
        me->start_busy(1);

        cnd["name"] = HIW+"毛髮影響"+NOR;
        cnd["duration"] = sk*3/10;
        cnd["from"] = me;

        target->set_condition("hairstick", cnd);
    }
    // 增加技能經驗
    me->improve_skill(SKILL_NAME, 1);
    return 1;
}
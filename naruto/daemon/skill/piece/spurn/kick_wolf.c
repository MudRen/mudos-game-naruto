#include <ansi.h>
#define SKILL_NAME "kick wolf"
#define SKILL_NAME_C "嵐腳•孤狼"
#define SKILL_CLASS "spurn"

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

int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*2/5;
}

int sock(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/40;
}

// 檢查是否能使用技能
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) || !objectp(target) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "你現在沒有空使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( act != "kick" ) {
        tell_object(me, "目前" + SKILL_NAME_C + "只有 kick 功\能。\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "你並未和對方在戰鬥中...\n");
        return 0;
    }

    if( me->query_condition("wolf_cd") ) {
        tell_object(me, "必須讓氣勁充滿彈性才能使用孤狼。\n");
        return 0;
    }

    if( me->query_skill("spurn", 1) < 60 || sk < 60 ) {
        tell_object(me, "你的能力不足以使用這一招。\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/8 ) {
        tell_object(me, "你身體狀況不佳，不能使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    return 1;
}

// 計算是否出現致命一擊
int isSock(object me, object target)
{
    // 踢技 80 以上增加致命影響
    if( me->query_skill("spurn", 1) < 80 ) return 0;

    // 加致命一擊機率
    return (COMBAT_D->sock(me, target, 1) > random(100));
}

// 計算是否命中
int isHit(object me, object target)
{
    int hit, raiseHit;

    raiseHit = me->query_skill(SKILL_NAME, 1)/2;

    me->add_temp("apply/exact", raiseHit);
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("apply/exact", -raiseHit);

    return hit;
}

// 取得傷害
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk + me->query_skill("spurn");

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

// 技能使用後 
void setEffect(object me, int sk, int hit)
{
    mapping cnd = ([]);

    if( !hit ) {
        me->start_busy(2);
    } else {
        me->start_busy(1);
    }
    cnd["name"] = HIY+"(CD)孤狼"+NOR;
    cnd["duration"] = 5;

    me->set_condition("wolf_cd", cnd);
    me->damage_stat("mp", sk/8, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    string msg, msgin, msgout;
    int damage, sk, sock, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    // 檢查是否能使用技能
    if( !isCast(me, act, target, sk) ) return 1;

    // 是否致命一擊
    sock = isSock(me, target);

    // 命中判斷
    hit = isHit(me, target);

    // 傷害
    damage = getDamage(me, target, sk);

    if( sock ) {
        msg = HIR"\n(致命一擊)"NOR" $N一連踢出五道彈跳"HIW"『"NOR+YEL"嵐腳•群狼連星"HIW"』"NOR"依照速度不同依續彈向$n！\n"NOR;
        msgin = "$n被群狼咬住，全身不斷的受到斬擊攻擊，幾乎快站不住了(%d) %s\n\n";
        msgout = "$N閃過了一道又一道的斬擊，終於避開所有的攻擊。\n\n";
        damage = (damage * COMBAT_D->sockPower(me, target, 1))/100;
    } else {
        msg = "\n$N跳前一步，踢出"HIW"『"HIY"嵐腳•孤狼"HIW"』"NOR"斬擊依著$N跳動的速率彈向$n。\n"NOR;
        msgin = "$n閃躲不急被孤狼咬中，並因此向後推了數尺(%d) %s\n\n";
        msgout = "孤狼跳動太過緩慢，$N早就跑到反方向去了。\n\n";
    }
    message_vision(msg, me, target);
    if( !hit ) {
        message_vision(msgout, me, target);
    } else {
        target->receive_damage(damage, me);
        message_vision( sprintf(msgin, damage, COMBAT_D->report_status(target) ), me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}

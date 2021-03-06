#include <ansi.h>
#define SKILL_NAME "kick luan"
#define SKILL_NAME_C "嵐腳•亂"
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

int defend(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/10;
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

    if( me->query_condition("luan_cd") ) {
        tell_object(me, "你才剛施展過亂，休息一下吧。\n");
        return 0;
    }

    if( me->query_skill("spurn", 1) < 180 || sk < 60 || me->query_skill("kick haze") < 120 ) {
        tell_object(me, "你的能力不足以使用這一招。\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/2 ) {
        tell_object(me, "你身體狀況不佳，不能使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    return 1;
}

// 計算人數
int check_number(object me, int sk)
{
    int number;

    if( sk < 100 ) {
        number = 0;
    } else {
        number = sk/100;
    }
    return number;
}

// 計算是否命中
int isHit(object me, object target)
{
    int hit, raiseHit;

    raiseHit = me->query_skill(SKILL_NAME, 1)/3;

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

    raiseDamage = sk*2 + me->query_skill("spurn") + me->query_skill("kick haze");

    if( wp = me->query_temp("weapon/twohanded") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*2/3;
    else if( wp = me->query_temp("weapon/righthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*2/3;
    else if( wp = me->query_temp("weapon/lefthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*2/3;
    else raiseDamage -= COMBAT_D->isDamage(me, target, 0)*2/3;

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

// 技能使用後 
void setEffect(object me, int sk)
{
    mapping cnd = ([]);

    cnd["name"] = HIB+"(CD)亂"+NOR;
    cnd["duration"] = 6;

    // 空行 msg
    message_vision("\n", me);
    me->set_condition("luan_cd", cnd);
    me->start_busy(2);
    me->damage_stat("mp", sk/2, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int damage, sk, i, number;
    object *targets;

    sk = me->query_skill(SKILL_NAME, 1);
    targets = me->query_enemy();

    // 檢查是否能使用技能
    if( !isCast(me, act, target, sk) ) return 1;

    // 計算人數
    number = check_number(me, sk);

    message_vision("\n$N兩手往地上一撐，雙腿連續踢擊出多道斬擊"HIW"『"HIB"嵐腳•亂"HIW"』"NOR"攻擊在場的敵人。\n", me, target);

    for(i=0;i<sizeof(targets);i++) {
        if( i > number ) break;       // 最多攻擊三人
        if( !isHit(me, targets[i]) ) {
            message_vision("亂踢造成攻擊也失去了準頭，連一下都沒打中$n。\n", me, targets[i]);
        } else {
            damage = getDamage(me, targets[i], sk);

            // 傷害盾吸收
            damage = COMBAT_D->receive_damage(target, me, damage);

            targets[i]->receive_damage(damage, me);
            message_vision( sprintf("「刷」地一聲，$n被斬擊劈中，身子停頓又被數道斬擊擊中(%d) %s\n", damage, COMBAT_D->report_status(targets[i])), me, targets[i]);
        }
    }
    setEffect(me, sk);
    return 1;
}

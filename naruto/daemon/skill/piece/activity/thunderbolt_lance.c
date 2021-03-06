#include <ansi.h>
#define SKILL_NAME "thunderbolt lance"
#define SKILL_NAME_C "雷光槍"
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

// 檢查是否能使用技能
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) || !objectp(target) ) {
        tell_object(me, "目前" + SKILL_NAME_C + "有 compo 和 back 兩種功\能。\n");
        return 0;
    }

    if( act != "back" ) {
        tell_object(me, "目前" + SKILL_NAME_C + "有 compo 和 back 兩種功\能。\n");
        return 0;
    }

    if( me->is_busy() ) {
        tell_object(me, "你現在沒有空使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( me->query_skill("activity", 1) < 180 || sk < 60 || me->query_skill("anemometer") < 80 ) {
        tell_object(me, "你的能力不足以使用這一招。\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "戰鬥都停止了還想做什麼。\n");
        return 0;
    }

    if( !me->query_condition("thunderbolt", 1) ) {
        tell_object(me, "沒有黑雲怎麼放雷電。\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/2 ) {
        tell_object(me, "你的狀態無法使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    return 1;
}

// 計算是否命中
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1)*1.5;
    j = COMBAT_D->evade(target, me, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// 取得傷害
int getDamage(object me, object target, int sk, object staff)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk*10 + me->query_skill("anemometer")*2 + me->query_skill("activity")*2;
    raiseDamage += staff->query("damage/twohanded/upper");

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
    if( !hit ) {
        me->damage_stat("mp", sk/10, me);
    } else {
        me->damage_stat("mp", sk/2, me);
    }
    me->start_busy(2);
    me->improve_skill(SKILL_NAME, 1);
    me->delete_condition("thunderbolt");
}

void do_perform(object me)
{
    int sk;
    object staff;

    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->query_stat("mp") < sk/30 ) {
        write("你的狀態無法使用" + SKILL_NAME_C + "。\n");
        return;
    }

    if( me->is_busy() ) {
        tell_object(me, "你暫時無法製造黑雲。\n");
        return 0;
    }

    if( sk < 10 ) {
        write("沒學會" + SKILL_NAME_C + "不會製造黑雲。\n");
        return;
    }

    if( me->query_condition("thunderbolt", 1) != 0) {
        write("雲已經產生了，再不發動攻擊雲可能會消失。\n");
        return;
    }

    if( !me->is_fighting() ) {
        write("沒事製造什麼黑雲。\n");
        return;
    }

    // 先偵測身上有沒有天候棒
    if( !objectp(staff = present("_WEATHER_", me)) ) {
        write("你身上沒有天候棒怎麼用技能。\n");
        return;
    }
    message_vision("$N"HIB"將"+staff->query("name")+NOR+HIB"交叉開始凝聚起一團黑色的烏雲...\n"NOR, me);

    cnd["name"] = HIK"凝聚黑雲"NOR;
    cnd["duration"] = 10;

    me->start_busy(2);
    me->damage_stat("mp", sk/30, me);
    me->set_condition("thunderbolt", cnd);
    return;
}

int perform_action(object me, string act, object target)
{
    object staff;
    int damage, sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    if( !objectp(me) ) return 0;

    if( act == "compo") {
        do_perform(me);
        return 1;
    }
    // 檢查是否能使用技能
    if( !isCast(me, act, target, sk) ) return 1;

    if( !objectp(staff = present("_WEATHER_", me)) )
        return notify_fail("沒有天候棒無法引導雷擊。\n");

    hit = isHit(me, target);

    message_vision("\n$N跑到$n的身後，慢慢的聚集"HIY"電氣"NOR"在"+staff->query("name")+"上，$n立刻轉身防禦...\n"NOR, me, target);

    if( !hit ) {
        message_vision(HIK"黑雲發出啪啪的聲響，然後慢慢的消失了...\n\n"NOR, me, target);
    } else {
        damage = getDamage(me, target, sk, staff);
        target->receive_damage(damage, me);
        message_vision("\n$N眼看黑雲逐漸成熟，大喊一聲"HIR"『"HIY+BLINK"雷光槍"NOR+HIR"』"NOR"！$n才知自己已經上當了！\n"NOR, me, target);
        message_vision( sprintf("忽然雷電從黑雲的方向射出，穿過$n的胸口直奔$N手中的"+staff->query("name")+"！(%d) %s\n\n", damage, COMBAT_D->report_status(target)), me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}

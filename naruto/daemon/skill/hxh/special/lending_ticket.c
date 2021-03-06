#include <ansi.h>
#define SKILL_NAME "lending ticket"
#define SKILL_NAME_C "借貸券"
#define SKILL_CLASS "special"

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

// 雨忍技能：水障壁 防禦壁 最高 +armor 100
void do_rain(object me)
{
    mapping cnd = ([]);
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->query_skill("special", 1) < 40 || sk < 40 ) {
        write("你的特質系程度與借貸券等級必須要在 40 以上。\n");
        return;
    }
    if( me->query_stat("mp") < 100 ) {
        write("你身體狀況不佳，不能使用" + SKILL_NAME_C + "。\n");
        return;
    }
    if( me->query_condition("waterwall", 1) != 0) {
        write("你已經用水障壁保護自己了。\n");
        return;
    }
    message_vision("\n$N結出『"CYN"水遁"NOR"』之印後雙手在身旁畫出一個巨大的圓形「"HIC"水障壁"NOR"」\n"NOR, me);

    cnd["name"] = HIC+"水障壁"+NOR;
    cnd["duration"] = sk/2;
    cnd["from"] = me;
    cnd["add"] = sk/2;
    cnd["ability"] = "armor";

    me->set_condition("waterwall", cnd);
    message_vision(HIC"用念力模仿出來的水柱快速包圍住"NOR"$N"HIC"，使"NOR"$N"HIC"的防禦能力提高了。\n\n"NOR, me);

    me->damage_stat("mp", 100, me);
    me->start_busy(3);
    me->improve_skill(SKILL_NAME, 1);
    return;
}

// 音忍技能：音療之術 治療自己 最高25%, cd時間3分鐘
void do_music(object me)
{
    mapping cnd = ([]);
    int sk, heal, cd, hd;

    sk = me->query_skill(SKILL_NAME, 1);
    hd = me->query_stat_maximum("hp")-me->query_stat_current("hp");
    heal = (me->query_stat_maximum("hp")*(sk + me->query_skill("special")))/1600;
 
    if( heal > hd ) {
        cd = 100*hd/me->query_stat_maximum("hp");
        heal = hd;
    }
    else cd = 100;

    if( me->query_skill("special", 1) < 50 || sk < 30 ) {
        write("你的特質系程度等級必須在 50 以上、借貸券等級必須在 30 以上。\n");
        return;
    }
    if( me->query_stat("mp") < 100 ) {
        write("你身體狀況不佳，不能使用" + SKILL_NAME_C + "。\n");
        return;
    }
    if( me->query_stat("hp") >= me->query_stat_maximum("hp") ) {
        write("你又沒有受傷，幹麻沒事對自己補血\n");
        return;
    }
    if( me->query_condition("music_heal") ) {
        write("你還無法使用這招。\n");
        return;
    }
    message_vision("\n$N將手貼在自己的傷口上，開始運起念力"HIM"「音療之術」"NOR"只見傷口瞬間就好轉了...("HIM+heal+NOR")\n\n"NOR, me);

    cnd["name"] = HIM+"(CD)音療"+NOR;
    cnd["duration"] = (cd*(18/10))/2;

    me->set_condition("music_heal", cnd);
    me->heal_stat("hp", heal);
    me->damage_stat("mp", 100, me);
    me->improve_skill(SKILL_NAME, 1);
    me->start_busy(1);
    return;
}

// 通倍利技能：菜刀戳刺-攻擊最大值 最多6%
void do_ton(object me, object target)
{
    mapping cnd = ([]);
    int sk, damage, i;

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->query_skill("special", 1) < 30 || sk < 50 ) {
        write("你的特質系程度等級必須在 30 以上、借貸券等級必須在 50 以上。\n");
        return;
    }
    if( me->query_stat("mp") < sk/5 ) {
        write("你身體狀況不佳，不能模仿通倍利攻擊。\n");
        return;
    }
    if( !me->is_fighting(target) ) {
        write("你跟對方並沒有在交戰中。\n");
        return;
    }
    if( me->query_condition("music_heal") ) {
        write("你還無法使用這招。\n");
        return;
    }
    message_vision(HIG"$N"HIG"偷偷從懷裡拿出菜刀，緩緩地靠近"NOR"$n"HIG"...\n"NOR, me, target);

    i = (sk-20)/30;
    damage = target->query_stat_maximum("hp")*i/100;

    // 對打體力最大值的 sk 做個限制
    if( damage >= i*500 ) damage = i*500;

    if( !COMBAT_D->isHit(me, target) ) {
        message_vision("\t但是$N光顧著注意$n沒看到地上的石頭，摔了個狗吃屎。\n"NOR, me, target);
        me->damage_stat("mp", sk/10, me);
        me->start_busy(2);
        return;
    }
    target->receive_damage(damage, me);
    message_vision( sprintf("\t$N面露邪笑地朝$n的背後用力一刺，「噗」的一聲鮮血四濺(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
    me->damage_stat("mp", sk/10, me);
    me->start_busy(2);

    cnd["name"] = HIW+"(CD)菜刀"+NOR;
    cnd["duration"] = 20;

    me->set_condition("music_heal", cnd);
    me->improve_skill(SKILL_NAME, 1);
    return;
}

// 蜘蛛人技能：蜘蛛網 -- 定人計，最高2-4回
void do_spider(object me, object target)
{
    mapping cnd = ([]);
    int sk, damage;

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->query_skill("special", 1) < 60 || sk < 60 ) {
        write("你的特質系程度等級必須在 60 以上、借貸券等級必須在 60 以上。\n");
        return;
    }
    if( me->query_stat("mp") < sk/10 ) {
        write("你身體狀況不佳，沒辦法念化蜘蛛絲。\n");
        return;
    }
    if( !me->is_fighting(target) ) {
        write("你跟對方並沒有在交戰中。\n");
        return;
    }
    if( me->query_condition("music_heal") ) {
        write("你還無法使用這招。\n");
        return;
    }
    if( target->is_busy() ) {
        write("對方已經無法行動了。\n");
        return;
    }
    message_vision(HIW"$N"HIW"將手掌朝上擺\出一個獨特的怪異姿勢，忽然手往前一伸噴出大量白絲！\n"NOR, me, target);
    if( !COMBAT_D->isHit(me, target) ) {
        message_vision("\t結果白絲沒有對準黏在附近的地上，反而影響了$N的行動。\n"NOR, me, target);
        me->damage_stat("mp", sk/10, me);
        me->start_busy(3);
    } else {
        message_vision("\t只見$n閃避不急被白絲團團黏住動彈不得等著$N來料理啦！\n"NOR, me, target);
        me->damage_stat("mp", sk/10, me);
        me->start_busy(1);
        target->start_busy(sk/50 - random(2));
    }
    cnd["name"] = HIW+"(CD)蜘蛛"+NOR;
    cnd["duration"] = 8;

    me->set_condition("music_heal", cnd);
    me->improve_skill(SKILL_NAME, 1);
    return;
}

// 豹族技能：氣功 (暫時沒有任務可以解)
void do_bow(object me)
{
    mapping cnd = ([]);
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->query_skill("special", 1) < 100 || sk < 80 ) {
        write("你的特質系程度等級必須在 100 以上、借貸券等級必須在 80 以上。\n");
        return;
    }
    if( me->query_stat("mp") < 200 ) {
        write("你身體狀況不佳，不能使用" + SKILL_NAME_C + "。\n");
        return;
    }
    if( me->query_condition("waterwall", 1) != 0) {
        write("你目前正處於發勁的狀態中。\n");
        return;
    }
    message_vision(HIY"\n$N"HIY"將念力轉換為氣力，在到達飽和時忽然大喝一聲「喝！」"HIR"『發勁』"NOR"\n"NOR, me);

    cnd["name"] = HIR+"發勁"+NOR;
    cnd["duration"] = sk;
    cnd["from"] = me;
    cnd["add"] = sk/2;
    cnd["ability"] = "attack";

    me->set_condition("waterwall", cnd);
    message_vision("$N提高了自身的攻擊力量，連握起拳頭時都發出喀喀聲響。\n"NOR, me);

    // 增加技能經驗
    me->damage_stat("mp", 200, me);
    me->start_busy(3);
    me->improve_skill(SKILL_NAME, 1);
    return;
}

// 竹取技能：早蕨之舞 (暫時沒有任務可以解)
void do_wheya(object me, object target)
{
    int sk, damage, raiseDamage, i;
    object wp;

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->query_skill("special", 1) < 100 || sk < 100 ) {
        write("你的特質系程度等級必須在 100 以上、借貸券等級必須在 100 以上。\n");
        return;
    }
    if( me->query_stat("mp") < sk/4 ) {
        write("你身體狀況不佳，無法使用竹取特技。\n");
        return;
    }
    if( !me->is_fighting(target) ) {
        write("你跟對方並沒有在交戰中。\n");
        return;
    }
    if( me->query_stat("hp") < 500 ) {
        write("你的體力太少了，無法負擔這個招式。\n");
        return;
    }
    me->damage_stat("mp", sk/4, me);
    message_vision(HIR"$N"HIR"顫抖身子，忽然骨頭刺破肉璧破體而出"HIY"『"NOR+RED+BLINK"早蕨之舞"NOR+HIY"』"HIR"全身骨頭戳向四面八方！\n"NOR, me, target);
    if( me->query_stat("hp") > 6000 ) {
        raiseDamage = sk*2 + 1500 + me->query_skill("special", 1);
    } else {
        raiseDamage = sk*2 + me->query_stat("hp")/4 + me->query_skill("special", 1);
    }
    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    if( !COMBAT_D->isHit(me, target) ) {
        message_vision("\t$N率先看穿了攻擊才避開此招，卻也被非竹取一族的$n嚇了一跳！\n", target, me);
        me->start_busy(2);
    } else {
        me->damage_stat("mp", sk/4, me);
        target->receive_damage(damage, me);
        message_vision( sprintf("\t骨頭飛快地刺向$n「噗噗」連續幾聲，$N早已被戳成蜂窩，血流如注(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
        me->start_busy(1);
        me->improve_skill(SKILL_NAME, 1);
    }
    i = sk + random(200);
    me->receive_damage(i, me);
    write("\n因為模仿竹取一族的血繼限界造成自身"HIR"("+i+")"NOR"點傷害。\n\n");
    return;
}
// 使用絕招
int perform_action(object me, string act, object target)
{
    if( me->is_busy() ) return notify_fail("你現在沒有空使用。\n");

    if( !me->query_condition("ticket") ) return notify_fail("你沒有使用任何借貸的技能阿。\n");

    switch( act ) {
        case "attack":
            if( !objectp(me) || !objectp(target) ) return notify_fail("沒有對手不能使用攻擊技能。\n");

            if( me->query_temp("ticket_card/ton") ) do_ton(me, target);
            else if( me->query_temp("ticket_card/spider") ) do_spider(me, target);
            else if( me->query_temp("ticket_card/wheya") ) do_wheya(me, target);
            else return notify_fail("你並沒有使用攻擊型借貸技能。\n");

            return 1;
            break;

        case "guard":
            if( !objectp(me) ) return 0;

            if( me->query_temp("ticket_card/rain") ) do_rain(me);
            else if( me->query_temp("ticket_card/music") ) do_music(me);
            else if( me->query_temp("ticket_card/bow") ) do_bow(me);
            else return notify_fail("你並沒有使用保護型借貸技能。\n");

            return 1;
            break;

        default: return notify_fail("目前借貸券分為攻擊型 attack 與保護型 guard 兩種功能。\n"); break;
    } return notify_fail("技能指令為 perform lending ticket.attack|guard。\n");
}

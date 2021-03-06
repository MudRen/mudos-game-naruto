#include <ansi.h>
#include <armor.h>

inherit F_ARMOR;

void create()
{
    set_name(HIM"不明"HIY"礦石"NOR, ({ "unknown stone", "stone" }));  // 名稱(id)
    set_weight(1000);                                                 // 重量
    setup_armor();
    if( !clonep() ) {
        set("unit", "塊");                                            // 物稱
        set("value", 10);                                             // 價格
        set("long", "從草摩家深山礦山所採集的特殊礦石融合而成，時常閃耀著七彩光輝\n"
                    "草摩家族投入了大量人力研究終於發現礦石所蘊藏的能量與使用方式\n"
                    "一直到目前草摩家族仍然在繼續的研究礦石其他能量功用為何。\n"
                    "  \n"
                    "以下為目前所發現的能量使用方法：\n"
                    "╭────┬────────┬──────────────╮\n"
                    "│"HIR"紅色殺謬"NOR"│fk <A> with <B> │讓非人為控制的生物互相攻擊。│\n"
                    "│"HIM"紫色吞食"NOR"│ate <A>         │將非玩家的東西吞食。        │\n"
                    "│"HIK"黑色死鐮"NOR"│hack <A>        │使用死神鐮刀瞬殺生物。      │\n"
                    "│"HIW"白色治癒"NOR"│heal <A>        │快速回復目標人物的生命。    │\n"
                    "╰────────────────────────────╯\n\n");
        set("wear_as", "armor");
        // wear穿著敘述, unequip脫下敘述
        set("wear_msg", "$N"HIW"將"NOR"$n"HIW"拿在手上，登時"NOR"$n"HIW"發出陣陣閃光照耀四周。\n"NOR);
        set("unequip_msg", "$n"HIK"的光芒漸漸暗淡了下來。\n"NOR);
        set("apply_armor/armor", ([                                   // 屬性設定
            "armor": 500,
            "dex": 50,
            "con": 50,
            "str": 50,
            "int": 50,
        ]));
    }
    setup();
}
void init()
{
    add_action("do_fk", "fk");
    add_action("do_eat", "ate");
    add_action("do_hack", "hack");
    add_action("do_heal", "heal");
}
int do_fk(string arg)
{
    string str, npc;
    object ob, me, obj;

    me = this_player();

    seteuid(getuid());
    if( !arg || sscanf(arg, "%s with %s", str, npc) != 2 )
        return notify_fail("指令格式﹕fk <Mob> with <Mob>\n");

   
 if( !(ob = present(str, environment(me))) )
        return notify_fail(HIR"這裡沒有 "NOR+str+HIR" 這號人物。\n"NOR);

    if( !(obj = present(npc, environment(me))) )
        return notify_fail(HIR"這裡沒有"NOR+npc+HIR"這號人物。\n"NOR);

    if( !ob->is_character() || !obj->is_character() )
        return notify_fail(HIY"兩個物件中有其中之一無法執行命令。\n"NOR);

    if( userp(ob) || userp(obj) )
        return notify_fail(HIY"被命令的雙方不可是玩家。\n"NOR);

    message_vision(HIR"$N發出神力讓"NOR+ob->name()+HIR"主動攻擊"NOR+obj->name()+HIR"！\n"NOR, me);
    ob->kill_ob(obj);
    obj->kill_ob(ob);
    return 1;
}
int do_eat(string arg)
{
    string target;
    object obj, me;

    me = this_player();

    seteuid(geteuid(this_player(1)));
    if( !arg ) return notify_fail("指令格式 : ate <物件之名稱或檔名>\n" );

    if( sscanf(arg, "%s", target) ==1 ) target = arg;

    obj = find_object(target);
    if (!obj) obj = present(target, me);
    if (!obj) obj = present(target, environment(me));
    if (!obj) obj = find_object( resolve_path(me->query("cwd"), target) );
    if (!obj) return notify_fail("好像太餓了...沒看到這樣物品。\n");

    if( (userp(obj) && !wizardp(obj)) || obj->query("userp") > 0 )
        return notify_fail(HIB"玩家不能隨便被你給吃掉。\n"NOR);

    message_vision(HIW"$N"HIM"使出"HIY"『"HIC"吞吞工廠"HIY"』"HIM"張開血盆大口把"NOR"$n"HIM"給吃掉了。\n"NOR, me, obj);
    if( environment(me)==environment(obj) ) {
        if( obj->is_character() ) {
            me->heal_stat("ap", obj->query_stat_current("ap"));
            me->heal_stat("hp", obj->query_stat_current("hp"));
            me->heal_stat("mp", obj->query_stat_current("mp"));
        } else {
            me->heal_stat("ap", 100);
            me->heal_stat("hp", 100);
            me->heal_stat("mp", 100);
        }
    }
    destruct(obj);
    if(obj) write("這樣東西似乎吞吞工廠也吃不掉。\n");
    return 1;
}
int do_hack(string arg)
{
    string npc;
    object obj, me;

    me = this_player();

    seteuid(geteuid(this_player(1)));
    if( !arg ) return notify_fail("指令格式 : hack <Mob Name>\n" );

    if( !arg || sscanf(arg, "%s", npc) != 1 )
        return notify_fail("指令格式 : hack <Mob Name>\n");

    if( !(obj = present(npc, environment(me))) )
        return notify_fail(NOR" npc"HIR" 又不在這裡，砍空氣嗎？\n"NOR);

    if( !obj->is_character() || obj->is_corpse() )
        return notify_fail(HIB"這樣東西沒生命，砍它也沒用。\n"NOR);

    if( (userp(obj) && wizardp(obj)) || obj->query("userp") > 0 )
        return notify_fail(HIB"怎麼能亂砍人的頭勒！\n"NOR);

    if( environment(me)==environment(obj) ) {
        obj->set_temp("last_damage_from", me);
        message_vision(HIR"$N"HIR"陰森的揮起"HIW+BLK"死神鐮刀"HIR"...順手就砍下了"NOR"$n"HIR"的腦袋...\n"NOR, me, obj);
        message_vision(HIR"只見"NOR"$n"HIR"的身子仍然不停抽動噴出剩餘的血液...\n"NOR, me, obj);
        obj->die();
    }
    destruct(obj);
    if(obj) write("死神鐮刀居然失靈了？我的天阿！\n");
    else write("Ok.\n");
    return 1;
}
int do_heal(string arg)
{
    string npc;
    object obj, me;

    me = this_player();

    seteuid(geteuid(this_player(1)));

    // 指定人物不在就判定是使用者
    if( !arg || sscanf(arg, "%s", npc) != 1 ) npc = me->query("id");
    if( !( obj = present(npc, environment(me)) ) ) obj = me;

    if( !obj->is_character() || obj->is_corpse() )
        return notify_fail(HIG"這樣東西沒生命，就算幫他治療也不會變成生物。\n"NOR);

    if( obj == me ) {
        message_vision(HIW"$N慈祥地唸起了古老的咒語，一陣溫暖的白光快速籠罩著你自己的全身...\n"NOR, me);
        tell_object(obj,HIY"你的身體受到白光加持，已經回復到最佳狀態了。\n"NOR);
    } else {
        message_vision(HIW"$N慈祥地唸起了古老的咒語，一陣溫暖的白光快速籠罩著$n的全身...\n"NOR, me, obj);
        tell_object(obj,HIY"你的身體受到白光加持，已經回復到最佳狀態了。\n"NOR);
    }
    // 體力回到最佳狀態
    obj->set_stat_current("hp", obj->query_stat_maximum("hp"));
    obj->set_stat_current("ap", obj->query_stat_maximum("ap"));
    obj->set_stat_current("mp", obj->query_stat_maximum("mp"));

    return 1;
}

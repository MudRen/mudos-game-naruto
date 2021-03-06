#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIR"紅包"HIW"發送機"NOR, ({ "Cash Robot", "cash", "robot" }));
    if( !clonep() ) {
        set("unit", "隻");
        set("value", 0);
        set("weight", 1);
        set("long", "一副員外模樣的機器人，專門發"HIY"(send to 某人)"NOR"紅包用。");
    }
    setup();
}
void init()
{
    add_action("do_send", "send");
}
int do_send(string arg)
{
    string npc;
    object ob, fm;

    if( !arg ) return notify_fail("指令格式: send to <某人> \n");
    if( sscanf(arg, "to %s", npc) !=1 ) return notify_fail("指令格式: send to <某人> \n");

    ob = LOGIN_D->find_body(npc);
    if(!ob) return notify_fail(HIR"線上沒有 "NOR+npc+HIR" 這號人物。\n"NOR);
    message_vision("$N拿出$n輸入"HIW+ob->name()+NOR"的名字，$n忽然發出一陣耀眼的光芒！\n"NOR, this_player(), this_object());
    if( !ob->is_character() || ob->is_corpse() || !userp(ob)) {
        message_vision("不過並沒有發生任何事情。\n"NOR, this_object());
        tell_object(this_player(),HIR"謎之聲：我不能將物品送給非玩家的人。\n"NOR);
        return 1;
    }
    fm = new("/u/m/mouse/npc/item/red.c");
    if( !objectp(fm) ) {
        write(HIR"謎之聲：紅包袋壞掉了！無法發送！\n"NOR);
        return 1;
    }
    if( environment(this_player())->is_area() ) {
        if( !area_move(environment(this_player()), fm, this_player()->query("area_info/x_axis"), this_player()->query("area_info/y_axis")) ) {
            message_vision(HIR"穿著聖誕裝的老員外"NOR"說道："HIG"我好像來錯地方了？\n"NOR, this_object());
            destruct(fm);
            return 1;
        }
    } else {
        if( !fm->move(environment(this_player())) ) {
            message_vision(HIR"穿著聖誕裝的老員外"NOR"說道："HIG"我好像來錯地方了？\n"NOR, this_object());
            destruct(fm);
            return 1;
        }
    }
    if( fm->move(ob) ) {
        message_vision(HIY"一位員外模樣的人在金光下現身，說了句"HIW"「恭喜發財」"HIY"後將"NOR"$N"HIY"交給了$n。\n"NOR, fm, ob);
    } else if( fm->move(environment(ob)) ) {
        message_vision(HIY"一位員外模樣的人在金光下現身，說了句"HIW"「恭喜發財」"HIY"後將"NOR"$N"HIY"放在$n腳邊。\n"NOR, fm, ob);
    } else {
        destruct(fm);
        return 0;
    }
    return 1;
}

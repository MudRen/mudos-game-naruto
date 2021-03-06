#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIR"紅色解封卷"NOR, ({ "red reel", "reel" }));
    if( !clonep() ) {
        set("base_unit", "卷");
        set("unit", "卷");
        set("base_value", 10);
        set("base_weight", 10);
        set("no_box", 1);
        set("long", "神秘的卷軸，不知有什麼用處。");
    }
    setup();
}
void do_use(object me)
{
    message_vision("$N將$n咬在嘴上，忽然秘卷散出紅光罩住$N！\n", me, this_object());
    message_vision("不一會兒，$N的臉上佈滿了可怕的"RED"紅色紋路"NOR"，而秘卷早已消失不見。\n", me);
    me->add_temp("quest/applaudbox", 1);
    destruct(this_object());
}

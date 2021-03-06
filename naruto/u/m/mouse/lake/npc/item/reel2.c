#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIC"藍色解封卷"NOR, ({ "blue reel", "reel" }));
    if( !clonep() ) {
        set("base_unit", "卷");
        set("unit", "卷");
        set("base_value", 10);
        set("base_weight", 10);
        set("long", "神秘的卷軸，不知有什麼用處。");
    }
    setup();
}
void do_use(object me)
{
    if( me->query_temp("quest/applaudbox") == 1) {
        message_vision("$N將$n咬在嘴上，只見秘卷發出激烈的藍色光芒！\n", me, this_object());
        message_vision("不一會兒，$N的臉上紅色紋路消失無蹤，但在雙手卻顯現出"HIB"藍色紋路"NOR"。\n", me);
        me->add_temp("quest/applaudbox", 1);
        destruct(this_object());
    } else {
        message_vision("$N將$n咬在嘴上，但沒有任何事情發生。\n", me, this_object());
        return;
    }
}

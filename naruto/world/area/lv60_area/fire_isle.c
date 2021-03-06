#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "火山列島");
    set("x_axis_size", 21);            // 橫向大小
    set("y_axis_size", 11);            // 縱向大小
    setup();
}
void init()
{
    add_action("do_jump", "jump");
}
int do_jump(string arg)
{
    object me, area;
    string area_file = "/world/area/benthal/sea12.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg == "海" || arg == "大海" ) {
        if( !objectp(area = load_object(area_file)) ) return 0;
        if( !area->is_area() ) return 0;
        message_vision("$N快速地衝向岸邊往海中一躍而下。\n", me);
        if( !area_move(area, me, 23, 12) ) return 0;
        message_vision("$N一臉爽快的從海面落了下來。\n", me);
        return 1;
    }
}

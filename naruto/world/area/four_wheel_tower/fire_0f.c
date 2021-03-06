#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "紅蓮之塔外");
    set("x_axis_size", 26);            // 橫向大小
    set("y_axis_size", 50);            // 縱向大小
    setup();
    set("no_recall", 1);
    set("no_drop", 1);
}



void init()
{
    add_action("do_enter", "enter");
}

int do_enter(string arg)
{
    int x, y;
    object me, area, npc, item;
    string area_file = "/world/area/four_wheel_tower/fire_1f.c";
    string *inv;

    me = this_player();

    if( !userp(me) || !this_object()->query_data(15, 40, "door_enter") ) return notify_fail("這個方向沒有出路。\n");

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;

    message_vision("$N推開大門直接衝了進去。\n", me);
    if( !area_move(area, me, 15, 18) ) return 0;
    return 1;
}

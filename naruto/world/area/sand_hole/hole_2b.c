inherit AREA;

void create()
{
    set("name", "地下沙穴B-2");
    set("x_axis_size", 31);            // 橫向大小
    set("y_axis_size", 31);            // 縱向大小
    setup();
}
void init()
{
    add_action("do_down", "down");
    add_action("do_up", "up");
}
int do_down(string arg)
{
    int x, y;
    object me, area;
    string area_file = "/world/area/sand_hole/hole_3b.c";

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( me->is_busy() ) return notify_fail("你現在正在忙，一時之間無法移動。\n");

    if( !userp(me) || !this_object()->query_data(x, y, "cord_down") ) return notify_fail("這個方向沒有出路。\n");

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N在手上吐了口口水，抓住繩頭溜了下去。\n", me);
    if( !area_move(area, me, x, y) ) return 0;
    return 1;
}
int do_up(string arg)
{
    int x, y;
    object me, area;
    string area_file = "/world/area/sand_hole/hole_1b.c";

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( me->is_busy() ) return notify_fail("你現在正在忙，一時之間無法移動。\n");

    if( !userp(me) || !this_object()->query_data(x, y, "cord_up") ) return notify_fail("這個方向沒有出路。\n");

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N搓了搓兩手，手腳並用往上爬去。\n", me);
    if( !area_move(area, me, x, y) ) return 0;
    return 1;
}

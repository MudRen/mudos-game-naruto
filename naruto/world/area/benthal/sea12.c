inherit AREA;

void create()
{
    set("name", "海底");
    set("x_axis_size", 50);            // 橫向大小
    set("y_axis_size", 50);            // 縱向大小
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    object me, area;
    string area_file = "/world/area/lv60_area/fire_isle.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "藤" && arg != "藤蔓" ) return 0;
    if( me->query("area_info/x_axis") != 23 || me->query("area_info/y_axis") != 12 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N稍微吐了幾口氣讓壓力減少，才緩緩爬上藤蔓。\n", me);
    if( !area_move(area, me, 10, 7) ) return 0;
    message_vision("$N嘩地一聲從海中爬上來。\n", me);
    return 1;
}
int valid_leave(object me, string dir)
{
    object ob;
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    ob = this_object();

    if( !userp(me) && x == 1 && y == 36 && dir == "west" ) return 0;
    return ::valid_leave(me, dir);
}

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
    string area_file = "/world/area/sifa_isle/sifa.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "岸邊" && arg != "岸" && arg != "岩石") return 0;

    if( me->query("area_info/x_axis") != 25 || me->query("area_info/y_axis") != 0 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N身手矯健的抓著四周海岩爬了上去。\n", me);
    if( !area_move(area, me, 45, 94) ) return 0;
    message_vision("$N快速地從海裡爬上岸來。\n", me);

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

    if( !userp(me) && x == 48 && y == 23 && dir == "southeast" ) return 0;
    if( !userp(me) && x == 48 && y == 24 && dir == "east" ) return 0;
    if( !userp(me) && x == 48 && y == 25 && dir == "northeast" ) return 0;
    return ::valid_leave(me, dir);
}

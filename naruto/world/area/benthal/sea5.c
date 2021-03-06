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
    add_action("do_swim", "swim");
}
int do_climb(string arg)
{
    object me, area;
    string area_file = "/world/area/ship/naval2.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "錨" ) return 0;

    if( me->query("area_info/x_axis") != 22 || me->query("area_info/y_axis") != 7 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N抓住錨的鐵鍊，手腳並用爬了上去。\n", me);
    if( !area_move(area, me, 8, 20) ) return 0;
    message_vision("$N從海裡爬了上來。\n", me);
    return 1;
}
int do_swim(string arg)
{
    object me, area;
    string area_file = "/world/area/benthal/sea9.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "珊瑚群" ) return 0;

    if( me->query("area_info/x_axis") != 49 || me->query("area_info/y_axis") != 3 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N伸手抓住珊瑚，緩緩的朝海流的上方游了上去。\n", me);
    if( !area_move(area, me, 2, 46) ) return 0;
    message_vision("$N辛苦渡過了強大的海流。\n", me);
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

    // return 0; 表示移動失敗
    if( userp(me) && ob->query_data(x, y, "northeast") && dir == "northeast"
        || userp(me) && ob->query_data(x, y, "northwest") && dir == "northwest"
        || userp(me) && ob->query_data(x, y, "southeast") && dir == "southeast"
        || userp(me) && ob->query_data(x, y, "southwest") && dir == "southwest"
        || userp(me) && ob->query_data(x, y, "north") && dir == "north"
        || userp(me) && ob->query_data(x, y, "south") && dir == "south"
        || userp(me) && ob->query_data(x, y, "west") && dir == "west"
        || userp(me) && ob->query_data(x, y, "east") && dir == "east" ) {

        message_vision("強大的海流將$N衝了回來！\n", me);
        return 0;
    }
    if( !userp(me) && x == 1 && y == 27 && dir == "west" ) return 0;
    if( !userp(me) && x == 2 && y == 48 && dir == "southeast" ) return 0;
    if( !userp(me) && x == 3 && y == 48 && dir == "south" ) return 0;
    if( !userp(me) && x == 4 && y == 48 && dir == "southwest" ) return 0;
    return ::valid_leave(me, dir);
}

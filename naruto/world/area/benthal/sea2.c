inherit AREA;

void create()
{
    set("name", "海底");
    set("x_axis_size", 50);            // 橫向大小
    set("y_axis_size", 50);            // 縱向大小
    setup();
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
    if( userp(me) && ob->query_data(x, y, "leg") && dir == "west" 
        || userp(me) && ob->query_data(x, y, "leg") && dir == "southwest" 
        || userp(me) && ob->query_data(x, y, "leg") && dir == "northwest") {

        message_vision("$N似乎被四周海流影響，慢慢捲了進去...\n", me);
    }
    if( !userp(me) && ob->query_data(x, y, "leg") && dir == "southwest" ) return 0;
    if( !userp(me) && ob->query_data(x, y, "leg") && dir == "west" ) return 0;
    if( !userp(me) && ob->query_data(x, y, "leg") && dir == "northwest" ) return 0;
    return ::valid_leave(me, dir);
}

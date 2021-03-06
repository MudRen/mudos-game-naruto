inherit AREA;

void create()
{
    set("name", "音隱秘道");
    set("x_axis_size", 41);            // 橫向大小
    set("y_axis_size", 21);            // 縱向大小
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    // return 0; 表示移動失敗
    if( !userp(me) && x == 1 && y == 5 && dir == "north" ) return 0;
    if( !userp(me) && x == 7 && y == 19 && dir == "south" ) return 0;
    if( !userp(me) && x == 38 && y == 9 && dir == "north" ) return 0;
    return ::valid_leave(me, dir);
}

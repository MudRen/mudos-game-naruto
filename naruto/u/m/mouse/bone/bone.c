inherit AREA;

void create()
{
    set("name", "骸骨戰場");
    set("x_axis_size", 41);            // 橫向大小
    set("y_axis_size", 41);            // 縱向大小
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    // return 0; 表示移動失敗
    if( !userp(me) && x == 5 && y == 39 && dir == "southeast" ) return 0;
    if( !userp(me) && x == 6 && y == 39 && dir == "south" ) return 0;
    if( !userp(me) && x == 7 && y == 39 && dir == "southwest" ) return 0;
    if( !userp(me) && x == 5 && y == 40 && dir == "east" ) return 0;
    if( !userp(me) && x == 7 && y == 40 && dir == "west" ) return 0;
    if( !userp(me) && x == 1 && y == 6 && dir == "west" ) return 0;
    if( !userp(me) && x == 1 && y == 5 && dir == "southwest" ) return 0;
    if( !userp(me) && x == 1 && y == 7 && dir == "northwest" ) return 0;
    return ::valid_leave(me, dir);
}

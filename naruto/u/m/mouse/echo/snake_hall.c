inherit AREA;

void create()
{
    set("name", "神廟內部");
    set("x_axis_size", 31);            // 橫向大小
    set("y_axis_size", 31);            // 縱向大小
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( !this_player()->id("_HELP_GIRL_") ) {
        if( !userp(me) && x == 14 && y == 29 && dir == "southeast" ) return 0;
        if( !userp(me) && x == 15 && y == 29 && dir == "south" ) return 0;
        if( !userp(me) && x == 16 && y == 29 && dir == "southwest" ) return 0;
        if( !userp(me) && x == 15 && y == 21 && dir == "north" ) return 0;
    }
    return ::valid_leave(me, dir);
}

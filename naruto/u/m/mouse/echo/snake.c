inherit AREA;

void create()
{
    set("name", "�D�H���q");
    set("x_axis_size", 42);            // ��V�j�p
    set("y_axis_size", 41);            // �a�V�j�p
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( !this_player()->id("_HELP_GIRL_") ) {
        if( !userp(me) && x == 8 && y == 39 && dir == "southeast" ) return 0;
        if( !userp(me) && x == 9 && y == 39 && dir == "south" ) return 0;
        if( !userp(me) && x == 10 && y == 39 && dir == "southwest" ) return 0;
        if( !userp(me) && x == 8 && y == 40 && dir == "east" ) return 0;
        if( !userp(me) && x == 10 && y == 40 && dir == "west" ) return 0;
        if( !userp(me) && x == 20 && y == 17 && dir == "north" ) return 0;
    }
    if( !userp(me) && x == 37 && y == 0 && dir == "east" ) return 0;
    if( !userp(me) && x == 39 && y == 0 && dir == "west" ) return 0;
    if( !userp(me) && x == 37 && y == 1 && dir == "northeast" ) return 0;
    if( !userp(me) && x == 38 && y == 1 && dir == "north" ) return 0;
    if( !userp(me) && x == 39 && y == 1 && dir == "northwest" ) return 0;
    return ::valid_leave(me, dir);
}

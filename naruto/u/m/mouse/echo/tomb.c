inherit AREA;

void create()
{
    set("name", "�H���ӪL");
    set("x_axis_size", 31);            // ��V�j�p
    set("y_axis_size", 21);            // �a�V�j�p
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( !this_player()->id("_HELP_GIRL_") ) {
        if( !userp(me) && x == 30 && y == 16 && dir == "south" ) return 0;
        if( !userp(me) && x == 29 && y == 16 && dir == "southeast" ) return 0;
        if( !userp(me) && x == 29 && y == 17 && dir == "east" ) return 0;
        if( !userp(me) && x == 29 && y == 18 && dir == "northeast" ) return 0;
        if( !userp(me) && x == 30 && y == 18 && dir == "north" ) return 0;
    }
    return ::valid_leave(me, dir);
}

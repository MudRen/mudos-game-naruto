inherit AREA;

void create()
{
    set("name", "�ۥޤG�h");
    set("x_axis_size", 31);            // ��V�j�p
    set("y_axis_size", 41);            // �a�V�j�p
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 7 && y == 34 && dir == "south" ) return 0;
    if( !userp(me) && x == 7 && y == 35 && dir == "north" ) return 0;
    if( !userp(me) && x == 19 && y == 30 && dir == "east" ) return 0;
    if( !userp(me) && x == 20 && y == 30 && dir == "west" ) return 0;
    if( !userp(me) && x == 1 && y == 39 && dir == "south" ) return 0;
    if( !userp(me) && x == 16 && y == 5 && dir == "west" ) return 0;
    return ::valid_leave(me, dir);
}

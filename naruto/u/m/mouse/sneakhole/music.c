inherit AREA;

void create()
{
    set("name", "�������D");
    set("x_axis_size", 41);            // ��V�j�p
    set("y_axis_size", 21);            // �a�V�j�p
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 1 && y == 5 && dir == "north" ) return 0;
    if( !userp(me) && x == 7 && y == 19 && dir == "south" ) return 0;
    if( !userp(me) && x == 38 && y == 9 && dir == "north" ) return 0;
    return ::valid_leave(me, dir);
}

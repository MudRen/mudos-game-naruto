inherit AREA;

void create()
{
    set("name", "���v�_��");
    set("x_axis_size", 20);            // ��V�j�p
    set("y_axis_size", 15);            // �a�V�j�p
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 1 && y == 8 && dir == "west" ) return 0;
    if( !userp(me) && x == 7 && y == 13 && dir == "south" ) return 0;
    if( !userp(me) && x == 8 && y == 13 && dir == "southwest" ) return 0;
    if( !userp(me) && x == 18 && y == 1 && dir == "east" ) return 0;
    if( !userp(me) && x == 18 && y == 2 && dir == "northeast" ) return 0;
    return ::valid_leave(me, dir);
}

inherit AREA;

void create()
{
    set("name", "����_�w");
    set("x_axis_size", 20);            // ��V�j�p
    set("y_axis_size", 20);            // �a�V�j�p
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;
    if( !me ) return 0;
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 9 && y == 1 && dir == "north" ) return 0;
    return ::valid_leave(me, dir);
}

inherit AREA;

void create()
{
    set("name", "�j�Ѵ˪L");
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
    if( !userp(me) && x == 1 && y == 10 && dir == "west" ) return 0;

    return ::valid_leave(me, dir);
}

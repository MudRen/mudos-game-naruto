// �J(??,??)
inherit AREA;

void create()
{
    set("name", "�շҬ}�]");
    set("x_axis_size", 41);            // ��V�j�p
    set("y_axis_size", 41);            // �a�V�j�p
    setup();
    set("no_recall", 1);
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( !userp(me) && x == 39 && y == 20 && dir == "east" ) return 0;
    return ::valid_leave(me, dir);
}

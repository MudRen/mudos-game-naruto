// write by -Acme-

inherit AREA;

void create()
{
    set("name", "�����p��");
    set("x_axis_size", 19);            // ��V�j�p
    set("y_axis_size", 11);            // �a�V�j�p
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

if( !userp(me) && x == 5 && y == 9 && (dir == "east" || dir == "southeast") )return 0;

    return ::valid_leave(me, dir);
}

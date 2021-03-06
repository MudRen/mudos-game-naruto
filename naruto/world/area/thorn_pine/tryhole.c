// 入(??,??)
inherit AREA;

void create()
{
    set("name", "試煉洞窟");
    set("x_axis_size", 41);            // 橫向大小
    set("y_axis_size", 41);            // 縱向大小
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

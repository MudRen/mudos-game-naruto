#include <ansi.h>
inherit AREA;

void create()
{
    set("name", "荒山坑道");
    set("x_axis_size", 36);            // 橫向大小
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

    // return 0; 表示移動失敗
    if( !userp(me) && x == 25 && y == 39 && dir == "southeast" ) return 0;
    if( !userp(me) && x == 26 && y == 39 && dir == "south" ) return 0;
    if( !userp(me) && x == 27 && y == 39 && dir == "southwest" ) return 0;
    return ::valid_leave(me, dir);
}

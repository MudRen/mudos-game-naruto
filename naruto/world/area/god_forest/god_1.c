#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "神獸森林一區");
    set("x_axis_size", 49);            // 橫向大小
    set("y_axis_size", 49);            // 縱向大小
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
    if( !userp(me) && x == 1 && y == 29 && dir == "west" ) return 0;
    return ::valid_leave(me, dir);
}

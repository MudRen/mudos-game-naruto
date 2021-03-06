#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "蛇主房");
    set("x_axis_size", 21);            // 橫向大小
    set("y_axis_size", 11);            // 縱向大小
    setup();
}
void init()
{
    object me = this_player();

    if( me->hasCamp("snaker") == 0 ) {
        tell_object(me,HIR"蛇人對人類有一些敵意。\n"NOR);
        me->setCamp("snaker", -5000);
    }
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    // return 0; 表示移動失敗
    if( !userp(me) && x == 9 && y == 9 && dir == "southeast" ) return 0;
    if( !userp(me) && x == 10 && y == 9 && dir == "south" ) return 0;
    if( !userp(me) && x == 11 && y == 9 && dir == "southwest" ) return 0;
    return ::valid_leave(me, dir);
}

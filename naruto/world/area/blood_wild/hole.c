#include <ansi.h>
inherit AREA;

void create()
{
    set("name", "��s�|�D");
    set("x_axis_size", 36);            // ��V�j�p
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

    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 25 && y == 39 && dir == "southeast" ) return 0;
    if( !userp(me) && x == 26 && y == 39 && dir == "south" ) return 0;
    if( !userp(me) && x == 27 && y == 39 && dir == "southwest" ) return 0;
    return ::valid_leave(me, dir);
}

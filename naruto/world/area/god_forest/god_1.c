#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "���~�˪L�@��");
    set("x_axis_size", 49);            // ��V�j�p
    set("y_axis_size", 49);            // �a�V�j�p
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
    if( !userp(me) && x == 1 && y == 29 && dir == "west" ) return 0;
    return ::valid_leave(me, dir);
}

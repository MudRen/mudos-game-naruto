#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "�ԨƪL");
    set("x_axis_size", 41);            // ��V�j�p
    set("y_axis_size", 31);            // �a�V�j�p
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 39 && y == 8 && dir == "east" ) return 0;
    if( !userp(me) && x == 39 && y == 9 && dir == "northeast" ) return 0;
    if( !userp(me) && x == 10 && y == 11 && dir == "north" ) return 0;
    if( !userp(me) && x == 9 && y == 11 && dir == "northeast" ) return 0;
    if( !userp(me) && x == 2 && y == 1 && dir == "north" ) return 0;
    if( !userp(me) && x == 3 && y == 1 && dir == "northwest" ) return 0;
    if( userp(this_player()) && me->is_fighting() ) {
        if( (x == 39 && y == 8 && dir == "east") ||
            (x == 39 && y == 9 && dir == "northeast") ||
            (x == 2 && y == 1 && dir == "north" ) ||
            (x == 3 && y == 1 && dir == "northwest" )) {

            message_vision(HIR"$N���۰k�]�o�g���F��V�A�����X�ԨƪL�F�I\n"NOR, me);
            return 1;
        }
    }
    return ::valid_leave(me, dir);
}

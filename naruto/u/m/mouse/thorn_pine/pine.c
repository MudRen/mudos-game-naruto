// (15,0) �J   (8,29) �X

inherit AREA;
#include <ansi.h>

void create()
{
    set("name", "��Q�L");
    set("x_axis_size", 30);            // ��V�j�p
    set("y_axis_size", 30);            // �a�V�j�p
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y, i, damage;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    i = random(10)+1;
    damage = random(26)+5;

    if( userp(this_player()) ) {
        if( i < 2) {
            message_vision("$N"HIR"�������p�ߡA�Q�@�Ǫ��y���ˤF�I"NOR"("HIY+damage+NOR")\n"NOR, this_player());
            this_player()->damage_stat("hp", damage, this_player());
            this_player()->start_busy(1);
            return 1;
        }
    }
    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 15 && y == 1 && dir == "north" ) return 0;
    if( !userp(me) && x == 14 && y == 1 && dir == "northeast" ) return 0;
    if( !userp(me) && x == 16 && y == 1 && dir == "northwest" ) return 0;
    if( !userp(me) && x == 8 && y == 28 && dir == "south" ) return 0;
    if( !userp(me) && x == 7 && y == 28 && dir == "southeast" ) return 0;
    if( !userp(me) && x == 9 && y == 28 && dir == "southwest" ) return 0;
    if( !userp(me) && x == 12 && y == 12 && dir == "south" ) return 0;
    if( !userp(me) && x == 12 && y == 12 && dir == "southeast" ) return 0;
    return ::valid_leave(me, dir);
}

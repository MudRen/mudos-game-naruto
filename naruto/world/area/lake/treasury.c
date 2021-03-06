#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "遺跡寶庫");
    set("x_axis_size", 20);            // 橫向大小
    set("y_axis_size", 20);            // 縱向大小
    setup();
}
void init()
{
    object me = this_player();

    // muye的會扣比較多
    if( me->hasCamp("rain") == 0 && this_player()->query("guild") == "muye" ) {
        tell_object(me,HIR"雨忍者村的忍者發現你了！他們與木葉的關係一直都不是很好...\n"NOR);
        me->setCamp("rain", -50000);
    } else if( me->hasCamp("rain") == 0 ) {
        tell_object(me,HIR"雨之忍者對你似乎不太友善。\n"NOR);
        me->setCamp("rain", -10000);
    }
}
int valid_leave(object me, string dir)
{
    int x, y;
    if( !me ) return 0;
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    // return 0; 表示移動失敗
    if( !userp(me) && x == 9 && y == 1 && dir == "north" ) return 0;
    return ::valid_leave(me, dir);
}

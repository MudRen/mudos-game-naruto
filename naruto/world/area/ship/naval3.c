#include <ansi.h>
inherit AREA;

void create()
{
    set("name", "大海上");
    set("x_axis_size", 30);            // 橫向大小
    set("y_axis_size", 40);            // 縱向大小
    setup();
}
void init()
{
    object me = this_player();

    add_action("do_jump", "jump");
    // 因為海賊海軍同屬 piece...所以只好用 class 判斷, 設到二轉應該不會有人漏掉吧
    if( userp(me) && me->hasCamp("robber") == 0 && (this_player()->query_class() == "work_sea" || this_player()->query_class() == "soldier_sea") ) {
        tell_object(me,HIR"受到海軍前輩們的指導，你愈來愈厭惡海賊了。\n"NOR);
        me->setCamp("robber", -34999);
    }
    if( userp(me) && me->hasCamp("police") == 0 && (this_player()->query_class() == "little_sea" || this_player()->query_class() == "thief_sea") ) {
        tell_object(me,HIR"一個海賊居然出現在海軍領地...當然立刻引起了海軍的注意。\n"NOR);
        me->setCamp("police", -34999);
    }
}
int do_jump(string arg)
{
    object me, area;
    string area_file = "/world/area/benthal/sea4.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "海" && arg != "大海" ) return 0;

    if( me->query("area_info/x_axis") != 19 || me->query("area_info/y_axis") != 24 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N往海裡一跳，結果撞到礁石之後才跌進海中。\n", me);
    if( !area_move(area, me, 22, 28) ) return 0;
    message_vision("$N從海面跌了進來，頭上還長個大包。\n", me);
    return 1;
}

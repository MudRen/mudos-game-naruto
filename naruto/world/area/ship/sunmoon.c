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
        tell_object(me,HIR"身為海軍的你單槍匹馬誤闖海賊船...立刻被當成目標了。\n"NOR);
        me->setCamp("robber", -34999);
    }
    if( userp(me) && me->hasCamp("police") == 0 && (this_player()->query_class() == "little_sea" || this_player()->query_class() == "thief_sea") ) {
        tell_object(me,HIR"身為海賊的你，對海軍自然會感到厭惡。\n"NOR);
        me->setCamp("police", -34999);
    } 
}
int do_jump(string arg)
{
    object me, area;
    string area_file = "/world/area/benthal/sea10.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "海" && arg != "大海" ) return 0;

    if( me->query("area_info/x_axis") != 9 || me->query("area_info/y_axis") != 25 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N左看右看，終於下定決心跳入海中。\n", me);
    if( !area_move(area, me, 14, 24) ) return 0;
    message_vision("$N似乎喝了幾口海水，難過的沉了下來。\n", me);
    return 1;
}

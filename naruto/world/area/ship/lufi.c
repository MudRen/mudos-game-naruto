#include <ansi.h>
inherit AREA;

void create()
{
    set("name", "大海上");
    set("x_axis_size", 48);            // 橫向大小
    set("y_axis_size", 48);            // 縱向大小
    setup();
}
void init()
{
    object me = this_player();

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

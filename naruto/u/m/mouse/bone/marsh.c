#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "絕望沼澤");
    set("x_axis_size", 31);            // 橫向大小
    set("y_axis_size", 50);            // 縱向大小
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}
int do_climb()
{
    if(this_player()->is_busy()) {
        tell_object(this_player(), "你正累的無法動彈，休息一下吧。\n");
        return 1;
    }
    if( this_player()->query_temp("quest/marsh_stop") != 1 ) return 0;
    if( random(4) == 1) {
        message_vision(HIM"$N辛苦的從沼澤中爬了出來！\n"NOR, this_player());
        this_player()->delete_temp("quest/marsh_stop");
        return 1;
    }
    message_vision(HIM"$N努力的爬動，沒想到愈陷愈深了！\n"NOR, this_player());
    this_player()->start_busy(2);
    return 1;
}
int valid_leave(object me, string dir)
{
    int x, y;
    object item;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( userp(this_player()) && me->is_fighting() && y >= 25 ) {
        tell_object(me,HIR"在沼澤中戰鬥還想分心移動太危險了！\n"NOR);
        return 1;
    }
    if( me->query_temp("quest/marsh_stop") == 1 ) {
        tell_object(me,"你被沼澤困住了無法移動！快想辦法爬(climb)出來吧！\n");
        return 1;
    }
    if( userp(this_player()) && y >= 25 ) {
        if( random(20) == 5 ) {
            me->add_temp("quest/marsh_stop", 1);
            message_vision(HIM"$N踩的太用力，慢慢陷進沼澤中了！\n"NOR, me);
            return 1;
        }
    }
    // return 0; 表示移動失敗
    if( !userp(me) && x == 0 && y == 24 && (dir == "south" || dir == "southeast") ) return 0;
    if( !userp(me) && x == 22 && y == 25 && (dir == "south" || dir == "southwest" || dir == "southeast") ) return 0;
    if( !userp(me) && x == 14 && y == 14 && dir == "northeast" ) return 0;
    if( !userp(me) && x == 15 && y == 14 && dir == "north" ) return 0;
    if( !userp(me) && x == 16 && y == 14 && dir == "northwest" ) return 0;
    if( !userp(me) && x == 2 && y == 25 && dir == "west" ) return 0;
    if( !userp(me) && x == 7 && y == 48 && (dir == "east" || dir == "southeast") ) return 0;
    return ::valid_leave(me, dir);
}

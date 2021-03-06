#include <ansi.h>

inherit AREA;

string say = "";
int i=0;

void create()
{
    set("name", "回音山洞");
    set("x_axis_size", 21);            // 橫向大小
    set("y_axis_size", 21);            // 縱向大小
    setup();
}
void init()
{
    add_action("do_say", "say");
}
int do_say(string arg)
{
    object me;
    me = this_player();
    if( !arg ) return notify_fail("你要說什麼？\n");
    if( say == "" ) {
    say = arg;
    call_out("say_1", 10, me);
    }
}
void say_1()
{
    if( i <= 3) {
        message_vision(HIM"四周傳出某人的回音﹕"HIC+say+NOR"\n", this_object());
        i++;
        call_out("say_1", 10, this_object());
        return;
    }
    say = "";
    message_vision(HIM"回音漸漸消失了。\n"NOR, this_object());
    i = 0;
    return;
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( !this_player()->id("_HELP_GIRL_") ) {
        if( !userp(me) && x == 16 && y == 3 && dir == "east" ) return 0;
        if( !userp(me) && x == 1 && y == 8 && dir == "south" ) return 0;
        if( !userp(me) && x == 11 && y == 13 && dir == "north" ) return 0;
        if( !userp(me) && x == 11 && y == 11 && dir == "south" ) return 0;
        if( !userp(me) && x == 15 && y == 9 && dir == "north" ) return 0;
        if( !userp(me) && x == 15 && y == 8 && dir == "south" ) return 0;
    }
    if( !userp(me) && x == 14 && y == 19 && dir == "southeast" ) return 0;
    if( !userp(me) && x == 15 && y == 19 && dir == "south" ) return 0;
    if( !userp(me) && x == 16 && y == 19 && dir == "southwest" ) return 0;
    return ::valid_leave(me, dir);
}

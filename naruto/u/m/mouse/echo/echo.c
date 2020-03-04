#include <ansi.h>

inherit AREA;

string say = "";
int i=0;

void create()
{
    set("name", "�^���s�}");
    set("x_axis_size", 21);            // ��V�j�p
    set("y_axis_size", 21);            // �a�V�j�p
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
    if( !arg ) return notify_fail("�A�n������H\n");
    if( say == "" ) {
    say = arg;
    call_out("say_1", 10, me);
    }
}
void say_1()
{
    if( i <= 3) {
        message_vision(HIM"�|�P�ǥX�Y�H���^���R"HIC+say+NOR"\n", this_object());
        i++;
        call_out("say_1", 10, this_object());
        return;
    }
    say = "";
    message_vision(HIM"�^�����������F�C\n"NOR, this_object());
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

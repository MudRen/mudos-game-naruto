#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "商之間");
    set("long", @long
小房間，房內正中間有個似乎可以扳動的機關，你仔細的研究
了一下這個機關，發現它可以往上或往下扳動，可能要按照固定的
規則去扳動機關到指定的鎖點，才會發生事情吧。
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"hole_2b.c",
                      "x_axis": 5,
                      "y_axis": 4,
                 ]),
    ]));
    set("detail", ([
        "機關": "似乎可以上推(pushup)、下推(pushdown)。",
    ]));
    setup();
}
void init()
{
    add_action("do_pushup", "pushup");
    add_action("do_pushdown", "pushdown");
}
int do_pushup(string arg)
{
    int i = this_player()->query_temp("quest/music_B");
    if( arg == "機關" ) {
        if( this_player()->query_temp("quest/music_B") < -4 ) {
            message_vision("機關好像扳到底了。\n", this_player());
            return 1;
        }
        if( !this_player()->query_temp("quest/music_F") ) {
            message_vision("機關似乎無法扳動。\n", this_player());
            return 1;
        }
        message_vision("$N用力的將機關往上扳了一格。\n", this_player());
        this_player()->add_temp("quest/music_B", -1);
        return 1;
    }
    return notify_fail("目前所扳動的刻度為 "HIY+i+NOR" 。\n");
}
int do_pushdown(string arg)
{
    int i = this_player()->query_temp("quest/music_B");
    if( arg == "機關" ) {
        if( this_player()->query_temp("quest/music_B") > 14 ) {
            message_vision("機關好像扳到頂了。\n", this_player());
            return 1;
        }
        if( !this_player()->query_temp("quest/music_F") ) {
            message_vision("機關似乎無法扳動。\n", this_player());
            return 1;
        }
        message_vision("$N用力的將機關往下扳了一格。\n", this_player());
        this_player()->add_temp("quest/music_B", 1);
        return 1;
    }
    return notify_fail("目前所扳動的刻度為 "HIY+i+NOR" 。\n");
}

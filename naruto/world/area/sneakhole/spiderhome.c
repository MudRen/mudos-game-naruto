#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "蜘蛛間");
        set("long", @LONG
一間由蜘蛛絲組成的房子，房內也到處都是蜘蛛絲。唯有牆角有
個非常顯眼的紅黑色相間物體在那裡，好像是什麼東西蹲在那。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"path.c",
                       "x_axis" : 17,
                       "y_axis" : 5,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/spiderman.c" : 1,
    ]));
    setup();
}

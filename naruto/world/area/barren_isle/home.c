#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","寶箱人的家");

    set("long", @long
房間中充滿了一股酒香，聞起來像是葡萄酒的味道，但是又多了
一種特殊的香味，似乎聞一聞就被這種香味給吸引住。只見一個人正
在房間裡大罵，不知道是因為什麼事情。
long);
    set("exits", ([
        "east" : ([ "filename": __DIR__"barren.c",
                    "x_axis": 18,
                    "y_axis": 8,
                 ]),
        "south" : ([ "filename": __DIR__"barren.c",
                     "x_axis": 15,
                     "y_axis": 11,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/ka.c" : 1,
    ]));
    set("no_recall", 1);
    setup();
}
int valid_leave(object me, string dir)
{
    object ob;

    if( !me ) return 0;
    if( dir == "south" ) { 
        if( me->query_temp("piece_test") != 1) return notify_fail("只有幫助寶箱人才能進去。\n");
    }
    return ::valid_leave(me, dir);
}

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "恆古空間");
    set("long", @long

    充滿著虛無的空間，彷彿所見的一切都是幻影。


long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"dragon_king.c",
                      "x_axis": 10,
                      "y_axis": 2,
                 ]),
        "west" : ([ "filename": __DIR__"dragon_king.c",
                      "x_axis": 9,
                      "y_axis": 1,
                 ]),
        "east" : ([ "filename": __DIR__"dragon_king.c",
                      "x_axis": 11,
                      "y_axis": 1,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/king.c" : 1,
    ]));
    set("no_recall", 1);
    setup();
}

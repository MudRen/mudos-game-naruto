#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�ؿv�Ǯ�");
    set("long", "�@���p�p�����ؿv�Ǹɲ߯Z�C\n");

    set("objects", ([ "/world/npc/architecture-teacher": 1 ]));
    set("exits", ([
        "east" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 13,
                       "y_axis" : 28,
                  ]),
        "south" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 10,
                       "y_axis" : 31,
                  ]),
        "west" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 7,
                       "y_axis" : 28,
                  ]),
        "north" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 10,
                       "y_axis" : 25,
                  ]),
    ]));

    setup();
}

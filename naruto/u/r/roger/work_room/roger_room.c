#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�T���");
        set("long", @LONG
�Q��²�����p�a��A�H�M���ä����A���o�ä����ǡC
�j�����G�T��å@�T���q�A�T�U�TĪ�иt��A���L�󦹤]�C
LONG);
    set("exits", ([ 
        "wizard" : ([ "filename" : __DIR__"guildhall.c",
                       "x_axis" : 13,
                       "y_axis" : 5,
                   ]),
        "south" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 35,
                       "y_axis" : 15,
                  ]),
    ]));
        setup();
}

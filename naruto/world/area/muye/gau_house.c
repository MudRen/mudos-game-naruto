#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��������s��");
        set("long", @LONG
    �@���}�ª��p�ΡA�̭����@�Ǫv���Ϊ������C
LONG);
    set("exits", ([
        "east" : ([ "filename" : __DIR__"muye.c",
                       "x_axis" : 11,
                       "y_axis" : 10,
                  ]),
    ]));
    set("objects", ([
        _DIR_AREA_"bone/npc/gau.c" : 1,
        __DIR__"npc/white_eyes_ninja.c": 1,
    ]));
    setup();
}

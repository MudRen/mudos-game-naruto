#include <ansi.h>

inherit ROOM;

int i;

void create()
{
        set("short", "������");
        set("long", @LONG
�ﺡ�F�������p�ж��A�@�I���i��N�@�o���i���B�C
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"music.c",
                       "x_axis" : 34,
                       "y_axis" : 5,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/san.c" : 1,
    ]));
    setup();
}

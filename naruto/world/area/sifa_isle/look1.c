#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�A��x�@��");
    set("long", @LONG
�U�����Ŷ�...���䦳���i�H�q���G��
LONG);

    set("exits", ([
        "up" : __DIR__"look2.c",
        "south" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 45,
                     "y_axis" : 38,
                 ]),
    ]));
    setup();
}

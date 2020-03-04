#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "正門守衛室");
    set("long", @LONG
裡面有一些輪班正在休息的海軍士兵，有些雖然睡著了卻仍然不
停喊著保護司法島、捍衛世界正義等等的夢話，看來海軍中還是有很
多的士兵都是真正嚮往著正義的。
LONG);
    set("exits", ([
        "south" : ([ "filename": __DIR__"sifa.c",
                     "x_axis": 51,
                     "y_axis": 38,
                  ]),
    ]));
    setup();
}

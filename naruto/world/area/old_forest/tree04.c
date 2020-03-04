#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","古森枝部");

    set("long", @long
眼前的黑暗中露出了幾個明亮的光點，仔細看才發現，居然是沒
有穿著衣服的人類！只見他們手拿武器喊叫著，只是他們說的語言和
一般用語不同，完全聽不懂。
long);
    set("exits", ([
        "east" : __DIR__"tree03.c",
        "north" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 1,
                      "y_axis": 12,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/warrior.c" : 1,
    ]));
    setup();
}

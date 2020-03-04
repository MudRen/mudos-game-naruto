#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "廚房餐廳");
        set("long", @LONG
一間不是很大的廚房，裡面卻放著許多的食材和鋒利的器具，雖
然是廚房和餐廳，卻被打掃的一塵不染，可見廚師除了對吃很講究，
對於環境的影響也沒有忽視。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"lufi.c",
                       "x_axis" : 10,
                       "y_axis" : 22,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/sanji.c" : 1,
    ]));
    setup();
}

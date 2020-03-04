#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "浴室房間");
    set("long", @LONG
整個房間就像個浴室，尤其是房內正中央的巨大浴缸，裡面似乎
還有放好的熱水，不停的冒出泡沫。浴缸前面擺著一張不該出現在浴
室內卻顯得很搭配的圓桌，桌上還擺著熱騰騰的紅茶。
LONG);
    set("exits", ([
        "north" : __DIR__"hall4.c",
    ]));
    set("objects", ([
        __DIR__"npc/ka.c" : 1,
    ]));
    setup();
}
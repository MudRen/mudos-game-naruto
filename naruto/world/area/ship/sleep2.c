#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "臥房地下室");
        set("long", @LONG
臥房地下室，比一樓還要大很多。房間中也比樓上豐富，不但有
桌子，還有書櫃和非常多的航海圖和畫海圖用的紙。
LONG);
    set("exits", ([
        "up" : __DIR__"sleep1.c",
    ]));
    set("objects", ([
        __DIR__"npc/nami.c" : 1,
        __DIR__"npc/robin.c" : 1,
    ]));
    setup();
}

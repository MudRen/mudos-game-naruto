#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "長官房");
    set("long", @LONG
二樓最大的房間，不過桌子和沙發都擺在房間的右邊，左邊是一
塊很大的空地，除了地上放了一個裝水果的籃子之外，什麼東西也沒
有。桌子後面是一片玻璃窗，可以清楚的看到司法島外面的情況。
LONG);
    set("exits", ([
        "south" : __DIR__"hall3.c",
    ]));
    set("objects", ([
        __DIR__"npc/si.c" : 1,
    ]));
    set("no_fight", 1);
    setup();
}

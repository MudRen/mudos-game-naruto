#include <room.h>

inherit HOCKSHOP;

void create()
{
        set("short", "海軍當鋪");
        set("long", @LONG
因為有自以為強的海賊會跑來偷襲司法島，導致海軍士兵們常撿
到一些用不上的海賊物品，眼尖的商人馬上看準了這個商機，千心萬
苦連合了所有商人公會之後終於在政府的司法島上開了第一家也是唯
一的一家民營機購。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 35,
                     "y_axis" : 76,
                  ]),
    ]));
    setup();
}

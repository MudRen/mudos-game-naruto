#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "右側三樓");
    set("long", @LONG
樓上似乎有光亮，應該是快到頂樓了。不過上頭一直傳來奇怪的
叫聲「喳叭叭...」還是小心一點吧。
LONG);
    set("exits", ([
        "up" : __DIR__"right4.c",
        "down" : __DIR__"right2.c",
    ]));
    setup();
}

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "左側三樓");
    set("long", @LONG
樓上似乎有光亮，應該是快到頂樓了。不過上頭一直傳來奇怪的
說話聲「呦伊呦伊...」還是小心一點吧。
LONG);
    set("exits", ([
        "up" : __DIR__"left4.c",
        "down" : __DIR__"left2.c",
    ]));
    setup();
}

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","土著村");

    set("long", @long
遠處似乎可以聽到一些吵雜聲，表示這裡應該離處著的村子不遠
了，不然在這密林之中聲音不易傳開。如果不想去土著的村子，可以
從剛才的樹枝爬回去。
long);
    set("exits", ([
        "west" : __DIR__"tree37.c",
    ]));
    set("detail", ([
        "樹枝": "剛才爬下來的樹枝，要爬(climb)上去小心剛才追你的土著喔。",
    ]));
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}

int do_climb(string arg)
{
    if( arg == "樹枝") {
    message_vision("$N緩緩的爬了上去。\n", this_player());
    this_player()->move(__DIR__"tree33.c");
    message_vision("$N從下面爬上來。\n", this_player());
    return 1;
    }
    return notify_fail("你想爬什麼東西？\n");
}

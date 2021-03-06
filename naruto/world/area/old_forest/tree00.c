#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","古森根部");

    set("long", @long
眼前是一大片盤根錯節的樹根，抬頭望去除了樹根還是樹根，居
然連樹幹都看不到，可見這片森林有多麼巨大。
long);
    set("detail", ([
        "樹根": "一根粗大的樹根，你可以攀爬(climb)上去。",
    ]));
    set("exits", ([
        "north" : __DIR__"treein.c",
    ]));
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}

int do_climb(string arg)
{
    if( arg == "樹根") {
    message_vision("$N找了一條看似堅固的樹根，快速爬了上去。\n", this_player());
    this_player()->move(__DIR__"tree01.c");
    message_vision("$N滿頭大汗的從下面爬了上來。\n", this_player());
    return 1;
    }
    return notify_fail("你想爬什麼東西？\n");
}

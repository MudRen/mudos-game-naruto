#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","古森枝部");

    set("long", @long
樹枝上已經完全被樹葉所掩蓋，光芒完全透不進來。偶爾還會聽
到低沉的擊鼓聲與四周樹葉的沙沙聲，讓人對這未知的巨樹群感到害
怕。每一步都要小心翼翼的前進。
long);
    set("exits", ([
        "west" : __DIR__"tree02.c",
        "east" : __DIR__"tree05.c",
        "south" : __DIR__"tree10.c",
    ]));
    set("detail", ([
        "樹根": "一根粗大的樹根，你可以攀爬(climb)上去。",
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
    message_vision("$N順著原樹根，快速的爬了下去。\n", this_player());
    this_player()->move(__DIR__"tree00.c");
    message_vision("$N臉色蒼白的從上面爬了下來。\n", this_player());
    return 1;
    }
    return notify_fail("你想爬什麼東西？\n");
}

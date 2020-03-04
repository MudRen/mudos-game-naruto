#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "雞舍");
    set("long", @LONG
雞舍的內部堆了很多稻草，應該是讓雞能夠保暖。舍內的牆邊都
有放置雞的飼料，當雞餓的時候便會自己到牆邊去吃飼料，平常雞沒
事便會到外面亂跑，有點類似放牧型態的飼養法。
LONG);
    set("exits", ([
        "east" : __DIR__"chicken7.c",
        "north" : __DIR__"chicken1.c",
    ]));
    set("objects", ([
        __DIR__"npc/chicken.c" : 3,
    ]));
    setup();
}

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","古森枝部");

    set("long", @long
陰暗的樹叢中，除了聽到自己的腳步聲與四周風吹樹葉的聲音外
，一切都很平靜，但總讓人覺得會發生什麼事....
long);
    set("exits", ([
        "west" : __DIR__"tree12.c",
        "south" : __DIR__"tree20.c",
    ]));
    setup();
}

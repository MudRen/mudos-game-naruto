#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","古森上枝");

    set("long", @long
四周放著小小的臺子，仔細一看可以發現從這裡居然能夠一窺剛
才一路爬上來的樹枝！只見四周忽然冒出了不少土著，他們手拿弓箭
，大概是在這裡偷襲入侵者。
long);
    set("exits", ([
        "east" : __DIR__"tree23.c",
    ]));
    set("objects", ([
        __DIR__"npc/shooter.c" : 3,
    ]));
    setup();
}

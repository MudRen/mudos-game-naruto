#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "偏門");
    set("long", @long
酒窖的後面居然有一扇鐵門，但是鐵門也被大水沖的歪七扭八
完全變形，從這裡可以看到外面已經被古跡的破碎石塊堆積，無法
從這裡走到外面去了。
long);
    set("exits", ([
        "east" : __DIR__"wine.c",
    ]));
    set("objects", ([
    __DIR__"npc/zombie3.c" : 1,
    ]));
    setup();
}

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "海軍登記處");
    set("long", @LONG
房間的正中央擺了一張大桌子，上面掛了一個牌子寫著：「近年
海賊猖獗，希望有志人仕踴躍加入海軍的行列，一同制裁萬惡的海賊
，讓世界繼續保有和平。」
LONG);

    set("exits", ([
        "south" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 40,
                     "y_axis" : 32,
                  ]),
        ]));

    set("objects", ([
        __DIR__"npc/nai.c": 1,
        __DIR__"npc/bone.c": 1,
    ]));
    setup();
}
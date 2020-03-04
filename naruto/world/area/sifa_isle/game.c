#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "遊戲室");
    set("long", @LONG
一間小房間，裡面只有一張桌子和幾個凳子，角落有個泡茶的用
具。桌上擺了一些撲克牌，大概是海兵們無聊時玩大老二用的。
LONG);
    set("exits", ([
        "east" : ([ "filename" : __DIR__"sifa.c",
                    "x_axis" : 31,
                    "y_axis" : 40,
                 ]),
    ]));

    set("objects", ([
        _DIR_ITEM_"big2.c" : 1,
    ]));
    set("no_fight", 1);
    setup();
}

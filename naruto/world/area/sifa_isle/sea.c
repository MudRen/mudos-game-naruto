#include <ansi.h>
#include <room.h>

inherit INN;

void create()
{
    set("short", "海邊小屋");
    set("long", @LONG
在這裡可以感覺到旁邊海水的味道，不時的還有海風吹來十分涼爽。
房間內的牆上掛著許多海軍獎章，還有一把看起來有點古老的海軍長
刀掛在正中間。一位老人正哀傷地坐在房中。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 58,
                     "y_axis" : 77,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/oldman.c" : 1,
    ]));
    set("valid_startroom", 1);
    setup();
}
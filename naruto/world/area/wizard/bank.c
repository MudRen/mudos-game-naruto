#include <room.h>

inherit BANK;

void create()
{
	set("short", "天上掉下來的銀行");
	set("long", @LONG
天上人間的銀行，一個相當神秘的地方。
    存錢：deposit
    提錢：withdraw
    匯錢：outward
    查詢：balance
LONG);
    set("exits", ([
        "east" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 5,
                       "y_axis" : 36,
                  ]),
    ]));
    set("objects", ([
        _DIR_AREA_"old_forest/npc/test.c": 1,
    ]));
	setup();
}

#include <room.h>

inherit BANK;

void create()
{
        set("short", "銀行");
        set("long", @LONG
看起來不像豹人建設的建築，裡面有幾台提款機可以提錢。
    存錢：deposit       提錢：withdraw
    匯錢：outward       查詢：balance
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 26,
                       "y_axis" : 8,
                  ]),
    ]));
        setup();
}

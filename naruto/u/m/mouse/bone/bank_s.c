#include <room.h>

inherit BANK;

void create()
{
        set("short", "銀行");
        set("long", @LONG
輝夜一族的銀行，看起來非常破舊....
    [存錢]：deposit       [提錢]：withdraw
    [匯錢]：outward       [查詢]：balance
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"bone.c",
                     "x_axis" : 34,
                     "y_axis" : 15,
                  ]),
    ]));
    setup();
}

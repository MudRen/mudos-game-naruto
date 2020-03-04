#include <room.h>

inherit BANK;

void create()
{
        set("short", "銀行");
        set("long","由世界政府所營業的國家銀行，可以保證不會破產。\n"
                   "[存錢]：deposit       [提錢]：withdraw\n"
                   "[匯錢]：outward       [查尋]：balance\n");
    set("exits", ([
        "south" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 32,
                     "y_axis" : 76,
                  ]),
    ]));
    setup();
}

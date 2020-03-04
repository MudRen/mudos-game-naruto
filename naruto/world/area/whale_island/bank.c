/* write by -Acme- */

#include <room.h>

inherit BANK;

void create()
{
    set("short", "鯨魚銀行");

    set("long", @long
這兒是島上的唯一一間銀行 雖說是銀行，但倒不如說是間小辨公室。
屋子裡只有一張辦公桌，和一個年邁的老婆婆，似乎就是掌管這間銀行的
工作人員。
相關指令：[存錢] deposit <數量> <貨幣種類>
          [領錢] withdraw <數量> <貨幣種類>
          [匯錢] outward <人物> <數量>
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"area.c",
                      "x_axis": 28,
                      "y_axis": 26,
                 ]),
    ]));

    setup();
}

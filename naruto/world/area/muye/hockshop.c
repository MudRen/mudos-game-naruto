/* write by -Acme- */

#include <room.h>

inherit HOCKSHOP;

void create()
{
    set("short", "木葉當舖");

    set("long", @long
這裡是木葉村赫赫有名的當舖，在當舖的大門上方掛著一塊大匾
額，上頭寫著「不平交易，童叟相欺」看來這間當舖一定是間黑店了
。隔著鐵柵欄你可以看見裡面有個嘴歪眼斜的老闆，坐在那抖著腿正
數著大把大把白花花的銀子。
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 33,
                      "y_axis": 30,
                 ]),
    ]));

    setup();
}

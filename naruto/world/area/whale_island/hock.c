/* write by -Acme- */

#include <room.h>

inherit HOCKSHOP;

void create()
{
    set("short", "鯨魚當舖");

    set("long", @long
這裡是鯨魚島上唯一的一間當舖，在當舖的大門上方掛著一塊大匾，
上頭題著「十天九分利，保証高利貸」。隔著鐵柵欄，你可以看見裡
面有個豬頭的老闆，坐在那抖著腿正數著大把大把白花花的銀子。
long);

    set("exits", ([
        "north" : ([ "filename": __DIR__"area.c",
                      "x_axis": 10,
                      "y_axis": 33,
                 ]),
    ]));

    setup();
}

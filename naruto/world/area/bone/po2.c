#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "小屋");
        set("long", @LONG
一間還算完整的小屋，牆壁上灑滿了蛇人乾掉的血，也許是因為
這些血的關係，通倍利好像不太敢靠近這間房子，走到附近就不進來
了，如果打的很累應該能在這裡稍微休息一下。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"fight.c",
                       "x_axis" : 10,
                       "y_axis" : 11,
                  ]),
        "southwest" : ([ "filename" : __DIR__"fight.c",
                       "x_axis" : 9,
                       "y_axis" : 11,
                  ]),
    ]));
    setup();
}

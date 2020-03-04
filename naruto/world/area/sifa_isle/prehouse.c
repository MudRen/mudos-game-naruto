#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "前門守衛室");
    set("long", @LONG
士兵們正整裝待發，身為前門的守衛，對於時常跑來胡鬧的海賊
時時刻刻都必需小心謹慎，只見海兵們不斷的打量著你，可能只要有
點海賊的樣子，二話不說就會馬上被攻擊吧。
LONG);
    set("exits", ([
        "south" : ([ "filename": __DIR__"sifa.c",
                     "x_axis": 45,
                     "y_axis": 75,
                  ]),
    ]));
    setup();
}

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "海軍船操舵室");
        set("long", @LONG
操舵室中完全沒看到操舵人員，反而是通訊兵不斷地在使用電話
蟲還有打字機，霹靂啪啦的打個沒完。一個階級比較高的海軍將領就
站在旁邊，也是一臉焦慮和忿怒。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"naval2.c",
                       "x_axis" : 18,
                       "y_axis" : 18,
                  ]),
    ]));
    setup();
}

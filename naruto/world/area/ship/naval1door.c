#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "海軍船操舵室");
        set("long", @LONG
牆壁上掛了很多的海圖，桌子上則放了各個地方的記錄指針，因
為在偉大的航道中一般指南針是無法使用的，各島間氣候和磁場不同
會影響到指南針的正確性。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"naval1.c",
                       "x_axis" : 14,
                       "y_axis" : 18,
                  ]),
    ]));
    setup();
}

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "飼料種子室");
    set("long", @LONG
房間的右邊堆放著一些家畜的飼料，房間的左邊則放滿了農地用
的各種食材種子、秧苗。房間中到處都放著木碳，似乎要讓整間房間
內都保持乾燥的狀態，連進來太久的你都感覺皮膚有點乾乾的了。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"area.c",
                       "x_axis" : 20,
                       "y_axis" : 26,
                  ]),
    ]));
    setup();
}

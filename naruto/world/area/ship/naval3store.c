#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "船艦倉庫");
        set("long", @LONG
通常的海軍戰艦是沒有倉庫的，因此這艘船應該算是運輸艦之類
的船支吧，倉庫中就像個大冰箱，可以存放很多的食物和醫療材料，
不過現在這艘船的倉庫並沒有太多的東西，只有少量的食材而已。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"naval3.c",
                       "x_axis" : 10,
                       "y_axis" : 27,
                  ]),
    ]));
    setup();
}

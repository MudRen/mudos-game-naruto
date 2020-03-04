#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "畫室");
    set("long", @long
一間腐蝕非常嚴重的地下小屋，從佈置來看在未進水前應該是
非常典雅的房間。房間的四周牆壁上掛著許許多多的名畫，每一幅
都是很久以前的當代一流名師所畫，可惜因為泡水泡了太久，這些
畫都已經損壞的不成型了，雖尚未腐壞的部分仍然不減畫中所表答
的一切，但那畢竟只是很少的部份，其他都已經腐壞了。
long);
    set("exits", ([
        "west" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 23,
                      "y_axis": 12,
                 ]),
    ]));
    set("detail", ([
        "名畫": "看著它尚未腐壞的一角，有種深深被畫吸引的感覺。",
    ]));
    set("objects", ([
    __DIR__"npc/zombie4.c" : 1,
    ]));
    setup();
}

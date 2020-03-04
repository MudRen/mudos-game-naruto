#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "小屋");
    set("long", @LONG
這裡只有簡陋地擺放了幾張木椅和一個木桌，靠牆的那一端有一
張破舊的木床，是一間很普通的小屋。而牆上掛著幾隻鐵製卻生�蛌�
器具。一旁藤製的櫃子被打了開來，風一吹便發出「�U�U∼呀呀∼」
的聲音。
LONG);

    set("exits", ([
        "west" : ([ "filename" : __DIR__"land.c",
                    "x_axis" : 25,
                    "y_axis" : 4,
                 ]),           
        "east" : __DIR__"house2.c",
    ]));

    set("objects", ([
        __DIR__"npc/qinqin.c" : 1,
    ]));

    setup();
}

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "僕人室");
    set("long", @long
房間內地上有個腐爛的木牌，上面寫著「僕人室」，再看看室
內的擺設，除了數張床舖與桌子，並沒有看到其他的擺設，想必這
裡應該是給僕人們休息的地方吧。
long);
    set("exits", ([
        "north" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 7,
                      "y_axis": 13,
                 ]),
        "west" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 5,
                      "y_axis": 15,
                 ]),
    ]));
    set("objects", ([
    __DIR__"npc/zombie.c" : 3,
    ]));
    setup();
}

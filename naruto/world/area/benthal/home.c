#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "海底之家");
    set("long", @LONG
廣大海底的一間小屋子，牆壁都是用海草搭起來的，屋子裡住了
一對魚人夫婦，只見他們愁眉苦臉的樣子似乎遇上了什麼樣的難題無
法解決，幫幫他們吧。
LONG);
    set("exits", ([
        "south" : ([ "filename": __DIR__"sea6.c",
                     "x_axis": 45,
                     "y_axis": 45,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/father.c" : 1,
        __DIR__"npc/mother.c" : 1,
    ]));
    setup();
}

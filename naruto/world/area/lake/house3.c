#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "旁室");
    set("long", @long
室內空間不是很大，大約只容的下六個人一同進入，牆上掛著
一些看起來不是很精美的掛畫，不但表框用的是最普通的，連畫的
內容都像是小孩子隨筆塗鴉，實在讓人搞不懂這間房間的用處到底
在哪裡，好像只是給小孩子掛畫的房間而已。
long);
    set("exits", ([
        "west" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 23,
                      "y_axis": 12,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/ninja4.c" : 1,
    ]));
    set("detail", ([
        "掛畫": "一個自畫像吧？畫的歪七扭八讓人難以看出它是自畫像。",
    ]));
    setup();
}

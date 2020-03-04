#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "歐風房間");
    set("long", @LONG
房間的地板類似歐式的棋盤，房間的擺設也幾乎都是歐式的建材
。房內的四周都是書櫃，櫃子裡放滿了各式各樣的書籍，房內的底端
是一個大壁爐，爐前的椅子上坐著一個鼻子長長的人。
LONG);
    set("exits", ([
        "south" : __DIR__"hall4.c",
    ]));
    set("objects", ([
        __DIR__"npc/ku.c" : 1,
    ]));
    setup();
}
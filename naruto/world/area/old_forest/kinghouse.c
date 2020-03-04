#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","山洞");

    set("long", @long
山洞內的地上鋪滿了樹葉，旁邊的岩石上還掛著一些水果。洞內
傳出一陣陣低沉的吼叫聲與步伐踏在樹葉上的沙沙聲，只見一頭巨大
猿猴正面目猙獰的衝了出來，可能是誤闖牠的地盤了。
long);
    set("exits", ([
        "north" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 13,
                      "y_axis": 17,
                 ]),
    ]));
    set("objects", ([
    __DIR__"npc/monkeyx.c" : 1,
    ]));
    setup();
}

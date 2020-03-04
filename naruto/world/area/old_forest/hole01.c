#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","洞窟內");
    set("long", @long
烏黑的洞窟中，你彷彿聞到了一股刺鼻的臭味，聞起來像是硫磺
之類的東西，難怪在洞窟中沒有任何的火把照明，可能一下子弄不好
就會發生爆炸吧。
long);
    set("exits", ([
        "south" : __DIR__"hole02.c",
        "north" : __DIR__"hole00.c",
    ]));
    set("no_recall", 1);
    setup();
}

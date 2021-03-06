#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", GRN"深山草屋"NOR);
    set("long", @long
小卻非常整齊的房間，房間左側擺了一張單人床，床前床後都堆
滿了各式各樣的藥材，有些是藥房常見的，有些卻是平常不會用來入
藥的東西或是沒看過的藥材。右邊則是幾台長相不同的機器，看著房
中那位男子不停地從一台機器中取出藥材放入另一台機器，又不時的
低頭沉思，可能正在製造某種東西吧。
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"area.c",
                      "x_axis": 58,
                      "y_axis": 4,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/pill.c" : 1,
    ]));
    set("no_fight", 1);
    setup();
}

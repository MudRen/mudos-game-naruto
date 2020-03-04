#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "輝夜本家");
        set("long", @LONG
房間內擺放著一些骨頭做的裝飾品，坐椅桌子櫃子也全都是由骨
頭製成，讓人看了有點毛毛的。一位砍起來年紀不小的輝夜族老人正
坐在眼前的一張骨椅上，他用銳利的眼神盯著四周看，那炯炯有神的
目光讓人了解到他可是輝夜一族中真正的高手。
LONG);
    set("exits", ([
        "west" : ([ "filename" : __DIR__"bone.c",
                       "x_axis" : 16,
                       "y_axis" : 4,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/lon.c" : 1,
    ]));
    setup();
}

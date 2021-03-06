#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "農家");
    set("long", @LONG
老農夫的家，看起來簡單樸實。房間裡有位老農夫，臉上總是堆
滿著笑容，原本他與老伴居住在這片自己的家園，但是數年前老伴先
去了之後剩他獨自一人過的非常辛苦，這時商人等人正好來到此地，
從此便在老農夫的家園蓋了自己的家居住下來，幫老農夫打點農作物
的買賣。現在的老農夫幾乎每天都過的很快樂。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"area.c",
                       "x_axis" : 18,
                       "y_axis" : 18,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/farmer.c" : 1,
    ]));
    setup();
}

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", HIW"阿飛的家"NOR);
    set("long", @LONG
很普通的家，唯一特別的地方就是所有的家具都是白色的，不知
是對白色有特殊僻好還是什麼其他的原因？
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"area.c",
                       "x_axis" : 35,
                       "y_axis" : 17,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/fe.c" : 1,
    ]));
    setup();
}

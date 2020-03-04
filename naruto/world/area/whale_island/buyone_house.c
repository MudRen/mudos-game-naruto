#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "百萬之家");
        set("long", @LONG
王百萬的家，看起來非常豪華....但是四周都堆滿了各家拉麵店
的碗和筷子，一位中年人就在碗堆中繼續努力的吃著拉麵，如果沒有
猜錯他應該就是王百萬了。
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"area.c",
                       "x_axis" : 33,
                       "y_axis" : 33,
                  ]),
    ]));
    set("objects", ([
        _DIR_AREA_"echo/npc/wang.c" : 1,
    ]));
    setup();
}

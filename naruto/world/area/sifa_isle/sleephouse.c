#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "海軍休息室");
    set("long", @LONG
一間非常巨大的休息室，裡面放了兩張床角比你還高，枕頭能把
人壓死的木床，看樣子似乎是給巨人睡的吧...
LONG);
    set("exits", ([
        "south" : ([ "filename": __DIR__"sifa.c",
                     "x_axis": 39,
                     "y_axis": 38,
                  ]),
    ]));
    setup();
}

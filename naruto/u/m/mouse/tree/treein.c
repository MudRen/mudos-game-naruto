#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","百年古森外");

    set("long", @long
放眼望去是整片的巨大古森林，連陽光都幾乎透不進來。在木葉
村中時常謠傳著，說村外有片古老的森林，裡面住著與外人隔絕的土
著，為了守護森林中的一棵千年巨木而禁止外來者進入。
long);
    set("exits", ([
        "south" : __DIR__"tree00.c",
        "north" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 4,
                      "y_axis": 11,
                 ]),
    ]));
    setup();
}

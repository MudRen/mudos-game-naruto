#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
�i�����Τl�A�訫�i�ӴN�D��@�ѫܭ������˨��C�Τl�����G�S
�������󪺨��ơA�����֪������w�g�]��~���h�F�A�u�ѤּƴX����
���i�������٦b��ı�C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"area.c",
                       "x_axis" : 18,
                       "y_axis" : 8,
                  ]),
        "east" : __DIR__"chicken0.c",
        "north" : __DIR__"chicken4.c",
        "west" : __DIR__"chicken8.c",
    ]));
    setup();
}

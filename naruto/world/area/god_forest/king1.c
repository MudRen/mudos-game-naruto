#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "��j�Ŷ�");
    set("long", @long

    �R���۵�L���Ŷ��A�ϩ��Ҩ����@�����O�ۼv�C


long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"dragon_king.c",
                      "x_axis": 10,
                      "y_axis": 2,
                 ]),
        "west" : ([ "filename": __DIR__"dragon_king.c",
                      "x_axis": 9,
                      "y_axis": 1,
                 ]),
        "east" : ([ "filename": __DIR__"dragon_king.c",
                      "x_axis": 11,
                      "y_axis": 1,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/item/statue.c" : 1,
    ]));
    set("no_recall", 1);
    setup();
}

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�@���}��");
        set("long", @LONG
�ݯ}���ɪ��Τl�A�����N�����D������h�F�A�̭���F�@�ǩ_��
�������A�����D�O�ִݯd�U�Ӫ��F��...
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"fight.c",
                       "x_axis" : 10,
                       "y_axis" : 17,
                  ]),
        "west" : ([ "filename" : __DIR__"fight.c",
                       "x_axis" : 9,
                       "y_axis" : 18,
                  ]),
        "southeast" : ([ "filename" : __DIR__"fight.c",
                       "x_axis" : 11,
                       "y_axis" : 19,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/little_ton.c" : 1,
    ]));
    setup();
}

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "���L�V�m��(��)");
    set("long", @LONG
�o���\��F�X�Ӱ��H�A�i�H�b�o�̽m�ޮ氫�ޯ�C
LONG);

    set("exits", ([
        "east" : ([ "filename" : __DIR__"sifa.c",
                    "x_axis" : 33,
                    "y_axis" : 34,
                 ]),
        "north" : __DIR__"prac3",
        "south" : __DIR__"prac9",
        "west" : __DIR__"prac5",
    ]));

    set("objects", ([
        _DIR_NPC_"stake.c": 4,
    ]));
    setup();
}

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "���L�V�m��(��)");
    set("long", @LONG
�o���\��F�X�Ӱ��H�A�i�H�b�o�̽m�ޮ氫�ޯ�C
LONG);

    set("exits", ([
        "east" : __DIR__"prac5",
        "north" : __DIR__"prac1",
        "south" : __DIR__"prac7",
        "west" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 27,
                     "y_axis" : 34,
                 ]),
    ]));

    set("objects", ([
        _DIR_NPC_"stake.c": 4,
    ]));
    setup();
}

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "���L�V�m��(��)");
    set("long", @LONG
�o���\��F�X�Ӱ��H�A�i�H�b�o�̽m�ޮ氫�ޯ�C
LONG);

    set("exits", ([
        "west" : __DIR__"prac1",
        "east" : __DIR__"prac3",
        "south" : __DIR__"prac5",
        "north" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 30,
                     "y_axis" : 31,
                  ]),
        ]));

    set("objects", ([
        _DIR_NPC_"stake.c": 4,
    ]));
    setup();
}

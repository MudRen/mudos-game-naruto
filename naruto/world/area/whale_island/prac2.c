#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�m�߳�(��)");
        set("long", @LONG
�o���\��F�X�Ӱ��H�A�i�H�b�o�̽m�ޮ氫�ޯ�C
LONG);

        set("exits", ([
        "north" : ([ "filename" : __DIR__"area.c",
                     "x_axis" : 25,
                     "y_axis" : 14,
                  ]),           
                "west" : __DIR__"prac1",
                "south" : __DIR__"prac5",
                "east" : __DIR__"prac3",
        ]));

    set("objects", ([
        _DIR_NPC_"stake.c": 4,
    ]));

        setup();
}

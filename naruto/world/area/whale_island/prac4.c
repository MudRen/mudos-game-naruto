
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�m�߳�(��)");
        set("long", @LONG
�o���\��F�X�Ӱ��H�A�i�H�b�o�̽m�ޮ氫�ޯ�C
LONG);

        set("exits", ([
        "west" : ([ "filename" : __DIR__"area.c",
                     "x_axis" : 22,
                     "y_axis" : 17,
                  ]),                           
                "north" : __DIR__"prac1",               
                "east" : __DIR__"prac5",                
                "south" : __DIR__"prac7",               
        ]));

    set("objects", ([
        _DIR_NPC_"stake.c": 4,
    ]));

        setup();
}


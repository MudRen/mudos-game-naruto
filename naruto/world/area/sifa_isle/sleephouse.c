#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "���x�𮧫�");
    set("long", @LONG
�@���D�`���j���𮧫ǡA�̭���F��i�ɨ���A�ٰ��A�E�Y���
�H��������ɡA�ݼˤl���G�O�����H�Ϊ��a...
LONG);
    set("exits", ([
        "south" : ([ "filename": __DIR__"sifa.c",
                     "x_axis": 39,
                     "y_axis": 38,
                  ]),
    ]));
    setup();
}

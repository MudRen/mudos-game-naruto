#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "���H��");
    set("long", @long
�ж����a�W���ӻG�ꪺ��P�A�W���g�ۡu���H�ǡv�A�A�ݬݫ�
�����\�]�A���F�Ʊi���E�P��l�A�èS���ݨ��L���\�]�A�Q���o
�����ӬO�����H�̥𮧪��a��a�C
long);
    set("exits", ([
        "north" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 7,
                      "y_axis": 13,
                 ]),
        "west" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 5,
                      "y_axis": 15,
                 ]),
    ]));
    set("objects", ([
    __DIR__"npc/zombie.c" : 3,
    ]));
    setup();
}

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�C����");
    set("long", @LONG
�@���p�ж��A�̭��u���@�i��l�M�X�ӹ��l�A�������Ӫw������
��C��W�\�F�@�Ǽ��J�P�A�j���O���L�̵L��ɪ��j�ѤG�Ϊ��C
LONG);
    set("exits", ([
        "east" : ([ "filename" : __DIR__"sifa.c",
                    "x_axis" : 31,
                    "y_axis" : 40,
                 ]),
    ]));

    set("objects", ([
        _DIR_ITEM_"big2.c" : 1,
    ]));
    set("no_fight", 1);
    setup();
}

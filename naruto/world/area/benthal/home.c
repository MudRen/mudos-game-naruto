#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�������a");
    set("long", @LONG
�s�j�������@���p�Τl�A������O�ή���f�_�Ӫ��A�Τl�̦�F
�@�ﳽ�H�Ұ��A�u���L�̷T�ܭW�y���ˤl���G�J�W�F����˪����D�L
�k�ѨM�A�����L�̧a�C
LONG);
    set("exits", ([
        "south" : ([ "filename": __DIR__"sea6.c",
                     "x_axis": 45,
                     "y_axis": 45,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/father.c" : 1,
        __DIR__"npc/mother.c" : 1,
    ]));
    setup();
}

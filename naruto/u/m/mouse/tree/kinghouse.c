#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�s�}");

    set("long", @long
�s�}�����a�W�Q���F�𸭡A���䪺���ۤW�ٱ��ۤ@�Ǥ��G�C�}��
�ǥX�@�}�}�C�I���q�s�n�P�B���b�𸭤W���F�F�n�A�u���@�Y���j
��U�����زu�񪺽ĤF�X�ӡA�i��O�~���e���a�L�F�C
long);
    set("exits", ([
        "north" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 13,
                      "y_axis": 17,
                 ]),
    ]));
    set("objects", ([
    __DIR__"npc/monkeyx.c" : 1,
    ]));
    setup();
}

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�j�˪K��");

    set("long", @long
���e���·t���S�X�F�X�ө��G�����I�A�J�Ӭݤ~�o�{�A�~�M�O�S
����ۦ�A���H���I�u���L�̤⮳�Z���ۥs�ۡA�u�O�L�̻����y���M
�@��λy���P�A����ť�����C
long);
    set("exits", ([
        "east" : __DIR__"tree03.c",
        "north" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 1,
                      "y_axis": 12,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/warrior.c" : 1,
    ]));
    setup();
}

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
        "east" : __DIR__"tree08.c",
        "south" : __DIR__"tree14.c",
    ]));
    set("objects", ([
        __DIR__"npc/warrior.c" : 2,
    ]));
    setup();
}

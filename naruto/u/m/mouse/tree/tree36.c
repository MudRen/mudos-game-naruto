#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�g�ۧ�");

    set("long", @long
�o�̦��G�N�O�g�۪����l�F�A���L�]���~�Ӫ̪��J�I�A���F�Ԥh
���~�䤣����k�B�ѤH�M�p�ġC
long);
    set("exits", ([
        "west" : __DIR__"tree35.c",
        "east" : __DIR__"tree37.c",
    ]));
    set("objects", ([
        __DIR__"npc/shooter.c" : 2,
        __DIR__"npc/warrior.c" : 2,
    ]));
    setup();
}

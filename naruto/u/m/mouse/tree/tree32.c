#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�j�ˤW�K");

    set("long", @long
�u�����g�ۥX�{�U�ӷU���Z�A�ݨӧ֨�g�۩Ҧ����l�F�a�A�]
�\�ٯ�@���츭�����Ҷǻ������ʥj�ѥ���C
long);
    set("exits", ([
        "west" : __DIR__"tree31.c",
        "east" : __DIR__"tree33.c",
    ]));
    set("objects", ([
        __DIR__"npc/shooter.c" : 1,
        __DIR__"npc/warrior.c" : 2,
    ]));
    setup();
}

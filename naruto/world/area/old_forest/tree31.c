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
        "north" : __DIR__"tree25.c",
        "west" : __DIR__"tree30.c",
        "east" : __DIR__"tree32.c",
    ]));
    set("objects", ([
        __DIR__"npc/shooter.c" : 1,
        __DIR__"npc/warrior.c" : 1,
    ]));
    setup();
}

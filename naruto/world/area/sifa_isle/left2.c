#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�����G��");
    set("long", @LONG
�ӱ�@�����W����...�Ȯ��٬ݤ��쳻�ݡC
LONG);
    set("exits", ([
        "up" : __DIR__"left3.c",
        "down" : __DIR__"left1.c",
    ]));
    setup();
}

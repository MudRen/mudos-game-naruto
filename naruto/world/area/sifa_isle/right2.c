#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�k���G��");
    set("long", @LONG
�ӱ�@�����W����...�Ȯ��٬ݤ��쳻�ݡC
LONG);
    set("exits", ([
        "up" : __DIR__"right3.c",
        "down" : __DIR__"right1.c",
    ]));
    setup();
}

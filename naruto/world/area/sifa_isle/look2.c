#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�A��x�G��");
    set("long", @LONG
�G�Ӱ��F�@������...�����W���w�g�o�`�F...
LONG);

    set("exits", ([
        "up" : __DIR__"look3.c",
        "down" : __DIR__"look1.c",
    ]));
    setup();
}

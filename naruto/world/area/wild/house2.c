#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�ש�");
    set("long", @LONG
�@���ﺡ�F�ɳD���㪺�p�שСA�ݰ_�Ӭ۷�����
LONG);

    set("exits", ([
        "west" : __DIR__"house.c",
    ]));

    set("objects", ([
        __DIR__"npc/wan.c" : 1,
    ]));

    setup();
}


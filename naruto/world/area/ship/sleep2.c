#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�שЦa�U��");
        set("long", @LONG
�שЦa�U�ǡA��@���٭n�j�ܦh�C�ж����]��ӤW�״I�A������
��l�A�٦����d�M�D�`�h������ϩM�e���ϥΪ��ȡC
LONG);
    set("exits", ([
        "up" : __DIR__"sleep1.c",
    ]));
    set("objects", ([
        __DIR__"npc/nami.c" : 1,
        __DIR__"npc/robin.c" : 1,
    ]));
    setup();
}

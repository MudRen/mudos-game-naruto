#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�s�a�ж�");
    set("long", @LONG
�ж����G�m�����@���s�a�A���L�@�ӫȤH�]�S���C�b�d�x���@��
���j�k�H���b�����ୱ�A�]�\���L���I����Ƨa�C
LONG);
    set("exits", ([
        "south" : __DIR__"hall2.c",
    ]));
    set("objects", ([
        __DIR__"npc/bruno.c" : 1,
    ]));
    setup();
}

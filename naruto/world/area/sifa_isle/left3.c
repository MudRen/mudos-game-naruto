#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�����T��");
    set("long", @LONG
�ӤW���G�����G�A���ӬO�֨쳻�ӤF�C���L�W�Y�@���Ǩө_�Ǫ�
�����n�u������...�v�٬O�p�ߤ@�I�a�C
LONG);
    set("exits", ([
        "up" : __DIR__"left4.c",
        "down" : __DIR__"left2.c",
    ]));
    setup();
}

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�k���T��");
    set("long", @LONG
�ӤW���G�����G�A���ӬO�֨쳻�ӤF�C���L�W�Y�@���Ǩө_�Ǫ�
�s�n�u��z�z...�v�٬O�p�ߤ@�I�a�C
LONG);
    set("exits", ([
        "up" : __DIR__"right4.c",
        "down" : __DIR__"right2.c",
    ]));
    setup();
}

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "���x��");
    set("long", @LONG
�G�ӳ̤j���ж��A���L��l�M�F�o���\�b�ж����k��A����O�@
���ܤj���Ŧa�A���F�a�W��F�@�Ӹˤ��G���x�l���~�A����F��]�S
���C��l�᭱�O�@���������A�i�H�M�����ݨ�q�k�q�~�������p�C
LONG);
    set("exits", ([
        "south" : __DIR__"hall3.c",
    ]));
    set("objects", ([
        __DIR__"npc/si.c" : 1,
    ]));
    set("no_fight", 1);
    setup();
}

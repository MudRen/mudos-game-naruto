#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�p���\�U");
        set("long", @LONG
�@�����O�ܤj���p�СA�̭��o��۳\�h�������M�W�Q������A��
�M�O�p�ЩM�\�U�A�o�Q�������@�Ф��V�A�i���p�v���F��Y�����s�A
������Ҫ��v�T�]�S�������C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"lufi.c",
                       "x_axis" : 10,
                       "y_axis" : 22,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/sanji.c" : 1,
    ]));
    setup();
}

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�޲��");
        set("long", @LONG
�������Q�����޲�ǡA�쥻���ӥu����M��l���ж��A�{�b�o�Q
�諸�����A�]���o�̦P�ɤ]�O�F�H������o�ǡC
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"lufi.c",
                       "x_axis" : 8,
                       "y_axis" : 24,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/usopp.c" : 1,
        __DIR__"npc/chopper.c" : 1,
    ]));
    setup();
}

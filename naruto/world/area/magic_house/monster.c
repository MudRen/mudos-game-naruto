#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�~��");
    set("long", @LONG

���j�K�]�檺�jŢ�l�A�K�]����G�O�ξ����}�Ҫ��A�A�����}�C

LONG);
    set("exits", ([
        "south" : ([ "filename": __DIR__"house.c",
                    "x_axis": 9,
                    "y_axis": 7,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/clemens.c" : 1,
    ]));
    setup();
    set("no_recall", 1);
}
void init()
{
    add_action("do_move", "move");
    add_action("do_move", "sfly");
}
int do_move(string arg)
{
    message_vision("$N���ϭ��W�ѪšA���O����г��S�^�F�U�ӡC\n", this_player());
    return 1;
}

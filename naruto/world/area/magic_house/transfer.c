#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�έ��𮧫�");
    set("long", @LONG
���t���p�ж��A�����e�F�@�ӻP�����αb�O�������������~�P�A
�u���@��ܵ۶¦�潴���H���b�ж������A�L�ڸ̰�ᦳ���A�C��o
���U�Ӥ����ܮɡA�ж����������~�P�N�|�o�X���⪺���~�A���O���~
���j�o�@�I�]�Ӥ��X���~�A���H�P��D�`�޲��C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"house.c",
                       "x_axis" : 28,
                       "y_axis" : 24,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/transfer.c" : 1,
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

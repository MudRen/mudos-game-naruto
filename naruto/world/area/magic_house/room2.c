#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "���");
    set("long", @LONG
�ˤF�ܦh�~�������F��A���F�����Ϊ��ʪ��̤Ѯ�H�N�ɻݭn��
�Ө��x�A���ɰ����Ϊ��ܦh��t�]�|�Ψ�o�̪��~���C�{�b�u���@��
�~�Ѫ������έ��b�̭��q�q�a��z���ơA�ݥL�@��~���A�֤]�Q����
�H�e�L�]���O�F�ʤ@�ɪ������Ω��P�C
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"house.c",
                       "x_axis" : 37,
                       "y_axis" : 24,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/torre.c" : 1,
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

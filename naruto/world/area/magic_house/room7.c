#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�έ��𮧫�");
    set("long", @LONG
�ݦ�²�檺�p�ж��A�o�����@�차���ιέ����n�U�����ǳơA�U
���U�˪��Ƹ˥Ϋ~�@�ˤ]����֡A�٦��B�c���ѹέ��̨ɨ��M�D���N
���C�ж������@�����j����l������έ��T�{�ۤv���ǳƬO�_�w�g��
���A�M��R���۫H�ߥh����ȤH�̡C
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"house.c",
                       "x_axis" : 28,
                       "y_axis" : 24,
                  ]),
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

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��s�s�X�γ���");
        set("long", @LONG
�o�̬O��s�s�X�x�������Ǥ��A�@�Ӧ��G�O�u�������v�H�᪺
�ж��A����W���ۤ@�ǤH���쪺�_���C
LONG);
    set("exits", ([
        "up" : __DIR__"monkey2.c",
        "south" : ([ "filename" : __DIR__"lufi.c",
                       "x_axis" : 24,
                       "y_axis" : 28,
                  ]),
    ]));
    setup();
}

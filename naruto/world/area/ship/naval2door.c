#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���x��޲��");
        set("long", @LONG
�޲�Ǥ������S�ݨ�޲�H���A�ϦӬO�q�T�L���_�a�b�ϥιq��
���٦����r���A�R�E�԰ժ����ӨS���C�@�Ӷ��Ť���������x�N��N
���b����A�]�O�@�y�J�{�M����C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"naval2.c",
                       "x_axis" : 18,
                       "y_axis" : 18,
                  ]),
    ]));
    setup();
}

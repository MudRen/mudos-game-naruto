#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�~��");
        set("long", @LONG
�@���������_�Ӫ��Ŷ��A���O�̭����F�@�ǳ��פ��~�S����L
���F��A���ǳ��צ��G�~���X�ӡA�ݰ_���٫D�`���s�A�C���M���o
�{�즳���_��������A�~�M������������v�����~�d�b�W���A���D�D
���پi�����d���H�u�O�_�Ǫ��ڸs�C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"marsh.c",
                       "x_axis" : 24,
                       "y_axis" : 8,
                  ]),
    ]));
    setup();
}

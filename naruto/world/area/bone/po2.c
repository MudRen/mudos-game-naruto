#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�p��");
        set("long", @LONG
�@���ٺ⧹�㪺�p�ΡA����W�x���F�D�H��������A�]�\�O�]��
�o�Ǧ媺���Y�A�q���Q�n�����Ӵ��a��o���Фl�A�������N���i��
�F�A�p�G�����ܲ����ӯ�b�o�̵y�L�𮧤@�U�C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"fight.c",
                       "x_axis" : 10,
                       "y_axis" : 11,
                  ]),
        "southwest" : ([ "filename" : __DIR__"fight.c",
                       "x_axis" : 9,
                       "y_axis" : 11,
                  ]),
    ]));
    setup();
}

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�s��");
    set("long", @long
��ê��a�U�ǡA�q��Ǫ��\�]�P�a�W�h�د}�����s�~�i�H�q�X
�o�����ӬO�\��@�ǰ��Űs�~���s���C�o�̳Q���Iŧ�D�`���Y���A
�s��ǳ̰����𨤳���ݨ�W�������F��a�A�s�d��O�@�Ӥ��Ѫ�
�����Q�j�����R���F�C
long);
    set("exits", ([
        "up" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 19,
                      "y_axis": 1,
                 ]),
        "west" : __DIR__"wine2.c",
    ]));
    setup();
}

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", GRN"�`�s���"NOR);
    set("long", @long
�p�o�D�`������ж��A�ж������\�F�@�i��H�ɡA�ɫe�ɫ᳣��
���F�U���U�˪��ħ��A���ǬO�ĩб`�����A���ǫo�O���`���|�ΨӤJ
�Ī��F��άO�S�ݹL���ħ��C�k��h�O�X�x���ۤ��P�������A�ݵ۩�
������k�l�����a�q�@�x���������X�ħ���J�t�@�x�����A�S���ɪ�
�C�Y�I��A�i�ॿ�b�s�y�Y�تF��a�C
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"area.c",
                      "x_axis": 58,
                      "y_axis": 4,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/pill.c" : 1,
    ]));
    set("no_fight", 1);
    setup();
}

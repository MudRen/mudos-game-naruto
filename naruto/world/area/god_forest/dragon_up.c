#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIW"�ѱ�"NOR);
    set("long", @long
�o�̬O�@�ӯ�e�ǼƤQ�H���p�}�ޡA�b�}�������Y�O�@�y���j��
�ӱ�A���O�ӱ�f�o�Q�@�������O��ا���һs�@���¦�j���Ҿצ�
���W�e���F�Ƥ��M�����~�ϮסA��A�q�C�ب��ץh�ݡA�ү�ݥX�Ӫ�
���~�ҼˬҤ��ۦP�A�[����~�M���A�߯��A���A�����Q���W�����~��
���~�A����ı���V��h�F�X�B�C
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"god_1.c",
                      "x_axis": 42,
                      "y_axis": 8,
                 ]),
    ]));
    set("detail", ([
        "�j��": "�W���e�F�\�\�h�h�����~�A���A�ݤF�ߥͮ`�ȡC",
        "�ӱ�": "�����D�q����̪��ӱ�A���O�Q�j���צ�F�C",
    ]));
    set("no_recall", 1);
    setup();
}

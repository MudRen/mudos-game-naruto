#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�e��");
    set("long", @long
�@���G�k�D�`�Y�����a�U�p�ΡA�q�G�m�Ӭݦb���i���e���ӬO
�D�`�嶮���ж��C�ж����|�P����W���۳\�\�h�h���W�e�A�C�@�T
���O�ܤ[�H�e����N�@�y�W�v�ҵe�A�i���]���w���w�F�Ӥ[�A�o��
�e���w�g�l�a���������F�A���|���G�a���������M����e���Ҫ�
���@���A���������u�O�ܤ֪������A��L���w�g�G�a�F�C
long);
    set("exits", ([
        "west" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 23,
                      "y_axis": 12,
                 ]),
    ]));
    set("detail", ([
        "�W�e": "�ݵۥ��|���G�a���@���A���ز`�`�Q�e�l�ު��Pı�C",
    ]));
    set("objects", ([
    __DIR__"npc/zombie4.c" : 1,
    ]));
    setup();
}

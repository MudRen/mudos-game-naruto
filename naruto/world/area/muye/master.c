/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "���v�j��");

    set("long", @long
�o�̬O���v�j�Ӥ@�ӷ|���U�A���v�j�ӬO�Ѥ츭���u�q�Ԫ̿��
���a��C�츭�������j�ưȤ]�O�b���v�j�Ӹ̨�ӡC�A�i�H�M������
����v�j�ӫ᭱���۾��A�W�Y��e�F���N�����v�j�H�Y���A�۷���
�Y���t�C
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 33,
                      "y_axis": 16,
                 ]),
    ]));

    set("objects", ([
        __DIR__+"npc/muye.c": 1,
        __DIR__"npc/ying.c": 1,
    ]));

    setup();
}

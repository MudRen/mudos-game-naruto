/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "�츭����");

    set("long", @long
�o�̬O�@���M���c�������Ϋ~���a��A�A�i�H�ݨ��|�g���C�F�\
�\�h�h���ī~�A�ݰ_�Ӻ����۷�����A�B����]�O�Q���X�z�C�A�S��
���j���f�W�豾�ۤ@������⪺���B�A�W�Y�g�ۡu�Ĩ�R���v�A�A��
�T���Y�@��Ө�L�o�n�C
long);

    set("exits", ([
        "north" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 25,
                      "y_axis": 21,
                 ]),
        "south" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 25,
                      "y_axis": 27,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/piller.c": 1,
    ]));

    setup();
}

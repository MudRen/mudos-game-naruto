/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "�H���ľQ");

    set("long", @long
�o�̬O�@���M���c�氷�d�ī~���a��A�A�i�H�ݨ��|�g���C�F�\
�\�h�h���ī~�A�ݰ_�Ӻ����۷�����A�B����]�O�Q���X�z�C�A�S��
���j���f�W�豾�ۤ@���A���⪺���B�A�W�Y�g�ۡu�Ĩ�L�R�v�A�A��
�T���Y�@��A���W�N�����y�A���G���R���ĸɸɨ��l�]����C
long);

    set("exits", ([
        "east" : ([ "filename": __DIR__"area.c",
                      "x_axis": 13,
                      "y_axis": 24,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/piller.c": 1,
    ]));

    setup();
}

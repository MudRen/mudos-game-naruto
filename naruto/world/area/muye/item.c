/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "�츭�Ԩ��E");

    set("long", @long
�o�̬O�츭�����Ԩ��E�F�A�츭���Ҧ��Ԫ̪��Ԩ㳣�O�X�۳o��
�Ԩ��E�v�Ť���A�j�j�p�p���Ԩ㳯�C���Τl�A�A�@�w�i�H�b�o�̧�
��A�ݭn���Ԩ�C�A�i�H�ݨ��Ԩ��E���f���ۤ@���p�l�A�W�Y�O�o��
�l�g�ۡu�Ԫ̧Y���̡A�Ԩ�D����v�A�A���Y�^�h�o�{�v�Ź�A�L�L
�@���A���G�b�t�ܵۧA���Y�٦��@�ǡu�S��v���Ԩ�C
long);

    set("exits", ([
        "east" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 22,
                      "y_axis": 33,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/eqer.c": 1,
        __DIR__"npc/wper.c": 1,
    ]));

    setup();
}

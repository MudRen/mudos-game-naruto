inherit ROOM;

void create()
{
        set("short", "���¨��D");
        set("long", @LONG
�o�̬O���¤U���_�Ӫ����D�A�����F�@�ǰ\�ڤH���b�𮧩�
�O���R�C���¤W�@���ǥX�ä����_���q�n�A�X��\�ڤk�ʴN�o�ˤ���
�����y�W�h�ۺq�C
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 14,
                       "y_axis" : 8,
                  ]),
        "west" : __DIR__"god02.c",
        "east" : __DIR__"god04.c",
        "south" : __DIR__"altar01.c",
    ]));
    setup();
}

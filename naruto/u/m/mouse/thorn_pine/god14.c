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
        "south" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 14,
                       "y_axis" : 16,
                  ]),
        "west" : __DIR__"god13.c",
        "east" : __DIR__"god15.c",
        "north" : __DIR__"altar04.c",
    ]));
    setup();
}

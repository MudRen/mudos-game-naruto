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
        "west" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 9,
                       "y_axis" : 12,
                  ]),
        "north" : __DIR__"god06.c",
        "south" : __DIR__"god10.c",
        "east" : __DIR__"altar02.c",
    ]));
    setup();
}

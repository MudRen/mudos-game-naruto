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
        "east" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 19,
                       "y_axis" : 12,
                  ]),
        "north" : __DIR__"god07.c",
        "south" : __DIR__"god11.c",
        "west" : __DIR__"altar03.c",
    ]));
    setup();
}

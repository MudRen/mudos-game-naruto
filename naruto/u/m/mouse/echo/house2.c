inherit ROOM;

void create()
{
        set("short", "�}�Τl");
        set("long", @LONG
�@���}�Τl�A�ݰ_�ӫD�`����áA�u���@�Ӥ��~�H�Z�o�����b��
���䪺�Ȥl�W�A���L�L�Ⲵ�L���A�n���w�g�S�F��z�A�s��W���o�O
�w�g�N���������D�C
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"tomb.c",
                       "x_axis" : 7,
                       "y_axis" : 17,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/zhang.c" : 1,
    ]));
    setup();
}

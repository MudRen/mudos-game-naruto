inherit ROOM;

void create()
{
        set("short", "�Z����");
        set("long", @LONG
�@�ؼ��x�����D�A�Z�h�B�Ԥh�����D�A�K�������D�C�q��W����
�h��Ƥ��M���Z���A�N�F�Ѭ�����~�����۵P�����ۡu�Z�����v���W
���C�b�o�̪���W�ٱ��F�t�@���P�l�g�ۡu����L�v
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 5,
                       "y_axis" : 6,
                  ]),
        "east" : __DIR__"wp03.c",
        "west" : __DIR__"wp02.c",
    ]));
    set("objects", ([
        __DIR__"npc/kr.c" : 1,
    ]));
    setup();
}

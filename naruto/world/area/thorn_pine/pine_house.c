inherit ROOM;

void create()
{
        set("short", "�Q�L�p��");
        set("long", @LONG
���b�Q��L�����@�ɤp�Τl�A�̭��Ǩӿ@�@���Ĩ��C�|�P�����
�~�l�A�̭��˵ۤ��C���⪺�����W�G��A�@�쨭��զ窺�H�N�@����
���b�~�l�����A�����ٷ|�N��~�˦b�@�_�άO�I���[���A�ݰ_�Ӧn��
�b��������窺�ˤl�C
LONG);
    set("exits", ([
        "west" : ([ "filename" : __DIR__"pine.c",
                       "x_axis" : 15,
                       "y_axis" : 13,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/sz.c" : 1,
    ]));
    setup();
}

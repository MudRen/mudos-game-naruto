inherit ROOM;

void create()
{
        set("short", "���x�ĩ�");
        set("long", @LONG
�~�����۵P�l�g�u�ġv���p�ΡA���L�Τ��ǨӰ}�}�o�������D�M
�D�`�Y�����Ш��A���H���D����D�G����½���F�C�u���@�Ӫ����D�`
�_�Ǫ��H�A����۪��ƽ��b�Τl�̷Ȩӷȥh�A�f�����_����ۡu�ڬO
�˳ǡ�ڬO�Ѣޢ����p�v�ݰ����n���n�ӸJ�q�j�Q�ѡ�v
LONG
);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 60,
                     "y_axis" : 33,
                 ]),
        ]));
    set("objects", ([
        __DIR__"npc/wa.c": 1,
    ]));
    setup();
}

inherit ROOM;

void create()
{
        set("short", "�y��");
        set("long", @LONG
���I�}�ꪺ�p�Τl�A�Τ��I�F�@���o�O�A�@��⮳�y�j���k�ʥ�
�b�O���U�A�I�q�����ۤl�u�˶�A����������i���ݬݥ|�P�A�H�ɳ�
�O����ĵ�٪����A�C
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"tomb.c",
                       "x_axis" : 11,
                       "y_axis" : 17,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/chu.c" : 1,
    ]));
    setup();
}

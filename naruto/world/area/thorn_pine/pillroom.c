inherit ROOM;

void create()
{
    set("short", "�^���l��");
    set("long",@LONG
�@�@���Ĩ��j���b�|�P�A�p�ж��᭱�O���e�����Ŷ��A���֪��\
�H�P���˪��H�̥��b�̭������v���C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 26,
                       "y_axis" : 6,
                  ]),
    ]));
    
    set("objects", ([
        __DIR__"npc/bi.c" : 1,
    ]));
    setup();
}

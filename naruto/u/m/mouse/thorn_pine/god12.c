inherit ROOM;

void create()
{
        set("short", "���¤���");
        set("long", @LONG
�\�H�̳����b�a�W�𮧵ۡA���b��ѡB��ť���¤W�ۺq�B�]����
�w�g�εۤF�A�j�a�ݰ_�ӳ��ܻ��P�A�������`�b���W�ݨ쪺�\�H����
�������^�A�]�\�e�̥u���b�o�̤~��ۦb�����P�߱��a�C
LONG);
    set("exits", ([
        "east" : __DIR__"god13.c",
        "north" : __DIR__"god10.c",
    ]));
    set("objects", ([
        __DIR__"npc/man.c" : 1,
        __DIR__"npc/woman.c" : 1,
        __DIR__"npc/child.c" : 1,
    ]));
    setup();
}

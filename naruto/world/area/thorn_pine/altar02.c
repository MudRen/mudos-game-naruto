inherit ROOM;

void create()
{
        set("short", "���¤W");
        set("long", @LONG
���¤W���X��k�ʰ\�H���b�ۺq�A���A����M�ĤW���¡A�U��
���\�H�P�ۺq���k�\�H�]�S�����A�άO�ޥX�L�b�A�٬O�ӱ`���ۺq��
�R�𮧡C���¤��ߦ��ʤj��A�i�H�L�h�@�@�C
LONG);
    set("exits", ([
        "east" : __DIR__"bigtree.c",
        "west" : __DIR__"god08.c",
    ]));
    set("objects", ([
        __DIR__"npc/singer.c" : 3,
    ]));
    setup();
}

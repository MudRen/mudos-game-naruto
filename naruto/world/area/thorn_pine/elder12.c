inherit ROOM;

void create()
{
        set("short", "�G�Ӥp��");
        set("long", @LONG
���b�Ȥl�W���\�H�w�R�ݵ۵��~�A���G���b�ɨ��o�����P�~����
���R�������C�e���ӴN�O�\�H�ڪ��ڪ��F�A�q�e��W���ˤf�P���몺
����i�H�Q������e���~���\�ڪ��묹�P�^�m�C
LONG);
    set("exits", ([
        "east" : __DIR__"elder11.c",
    ]));
    set("objects", ([
        __DIR__"npc/head.c" : 1,
    ]));
    setup();
}

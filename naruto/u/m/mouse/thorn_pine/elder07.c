inherit ROOM;

void create()
{
        set("short", "�@�Ӥj�U");
        set("long", @LONG
��������W���F�@�T�ܪ����e�A�o�̩ұ��u�O�e�����b���Ӥw�A
�e����ø�O�@�s����ʪ���֪��\�H�A�e�̤�����j����A�n���b�l
���ۤ���F�誺�ˤl�C
LONG);
    set("exits", ([
        "east" : __DIR__"elder08.c",
        "north" : __DIR__"elder04.c",
    ]));
    set("objects", ([
        __DIR__"npc/warrior.c" : 1,
        __DIR__"npc/master.c" : 1,
    ]));
    setup();
}

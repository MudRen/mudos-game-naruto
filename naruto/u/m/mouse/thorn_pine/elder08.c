inherit ROOM;

void create()
{
        set("short", "�@�Ӥj�U");
        set("long", @LONG
��������W���F�@�T�ܪ����e�A�o�̩ұ��u�O�e�����b���Ӥw�A
�e����ø�O�@�쨭�����j���\�H�A�e�⮳�ۤ@����⪺����A���إ�
�c���l�۫e�誺�@�s�j��C
LONG);
    set("exits", ([
        "west" : __DIR__"elder07.c",
        "east" : __DIR__"elder09.c",
        "north" : __DIR__"elder05.c",
    ]));
    set("objects", ([
        __DIR__"npc/man.c" : 1,
        __DIR__"npc/master.c" : 1,
    ]));
    setup();
}

inherit ROOM;

void create()
{
        set("short", "�@�Ӥj�U");
        set("long", @LONG
��������W���F�@�T�ܪ����e�A�o�̩ұ��u�O�e���k�b���Ӥw�A
�e����ø�O�@�j�s�h��b�R���j��A�����_�L�B�������ˤ����B����
�w�g�˦b�b�~�a�a�@���A�@�P�I�N�O�����@�L�ԷN�C
LONG);
    set("exits", ([
        "west" : __DIR__"elder08.c",
        "north" : __DIR__"elder06.c",
    ]));
    set("objects", ([
        __DIR__"npc/warrior.c" : 1,
        __DIR__"npc/woman.c" : 1,
    ]));
    setup();
}

inherit ROOM;

void create()
{
        set("short", "���¤���");
        set("long", @LONG
�\�H�̰������b���諸�|�P���ۻR�A�e�̪�����ֳt���ܴ��ۤ�
�աA�}�B�]�S������A���������k�����ܤƸ`���C�ݰ_�ӴN���O�b�V
�m�ֳt���ʻP�F�����B������A�N�V�m�ĤJ�ͬ������C
LONG);
    set("exits", ([
        "north" : __DIR__"god05.c",
        "south" : __DIR__"god09.c",
    ]));
    set("objects", ([
        __DIR__"npc/man.c" : 1,
        __DIR__"npc/woman.c" : 1,
    ]));
    setup();
}
inherit ROOM;

void create()
{
        set("short", "�@�Ӥj�U");
        set("long", @LONG
�P���\��ۥξ�F�������Ȥl�M��l�A�W���Q�۰ʪ��������o
�Q���ξA�A��l�W�h��ۤ@�Ǿ���C
LONG);
    set("exits", ([
        "west" : __DIR__"elder05.c",
        "north" : __DIR__"elder03.c",
        "south" : __DIR__"elder09.c",
    ]));
    set("objects", ([
        __DIR__"npc/warrior.c" : 1,
        __DIR__"npc/master.c" : 1,
    ]));
    setup();
}
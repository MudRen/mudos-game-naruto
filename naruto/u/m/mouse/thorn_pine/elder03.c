inherit ROOM;

void create()
{
        set("short", "�@�Ӽӱ�");
        set("long", @LONG
�@���q���ӤW���ӱ�A�q�W�������|�ǨӤ��Y�������n���C
LONG);
    set("exits", ([
        "west" : __DIR__"elder01.c",
        "up" : __DIR__"elder10.c",
        "south" : __DIR__"elder06.c",
    ]));
        setup();
}

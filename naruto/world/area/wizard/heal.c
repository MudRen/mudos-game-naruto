inherit ROOM;

void create()
{
    set("short", "�ѤW���U�Ӫ����ĩ�");
    set("long", @LONG
�ѤW�H�������ĩ��A�@�Ӭ۷������a��C
LONG);
    set("exits", ([
        "east" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 5,
                       "y_axis" : 24,
                  ]),
    ]));
    
    set("objects", ([
        __DIR__"npc/piller.c" : 1,
    ]));
    setup();
}
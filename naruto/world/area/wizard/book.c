inherit ROOM;

void create()
{
    set("short", "�ѤW���U�Ӫ����b��");
    set("long", @LONG
�ѤW�H�������b���A�@�Ӭ۷������a��C
LONG);
    set("exits", ([
        "east" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 5,
                       "y_axis" : 20,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/skiller.c" : 1,
    ]));
    setup();
}
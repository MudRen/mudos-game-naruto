inherit ROOM;

void create()
{
	set("short", "�ѤW���U�Ӫ����㩱");
	set("long", @LONG
�ѤW�H�������㩱�A�@�Ӭ۷������a��C
LONG);
    set("exits", ([
        "east" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 5,
                       "y_axis" : 28,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/eqer.c" : 1,
    ]));
	setup();
}
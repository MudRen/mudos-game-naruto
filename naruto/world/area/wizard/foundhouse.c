inherit ROOM;

void create()
{
    set("short", "�M���t");
    set("long", @long
�������ж������쥴�ۨ��K�a���~�A���ƥi�H�ݥL�C
long);
    set("exits", ([
        "east" : ([ "filename": __DIR__"wizard.c",
                      "x_axis": 5,
                      "y_axis": 44,
                 ]),
        "west" : __DIR__"found.c",
    ]));
    set("objects", ([
        __DIR__"npc/founder.c" : 1,
    ]));
    setup();
}

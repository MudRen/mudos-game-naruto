/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "�R�l�a");

    set("long", @long
�o�̬O�츭�����R�l�a�C
long);

    set("exits", ([
        "north" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 11,
                      "y_axis": 20,
                 ]),
        "south" : __DIR__"ai2.c",
    ]));

    set("objects", ([
        __DIR__"npc/ai.c" : 1,
    ]));

    setup();
}

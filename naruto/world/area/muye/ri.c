/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "��V�a");

    set("long", @long
�o�̬O�츭������V�a�C
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 20,
                      "y_axis": 18,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/nightkid.c": 1,
    ]));
    setup();
}

inherit ROOM;

void create()
{
    set("short", "古董商家");

    set("long", @long
總而言之就是古董店了..
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"swanlake.c",
                      "x_axis": 11,
                      "y_axis": 7,
                 ]),
    ]));

    set("objects", ([
        "/world/area/lake/npc/seller" : 1,
    ]));

    setup();
}


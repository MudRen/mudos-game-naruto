inherit ROOM;

void create()
{
    set("short", "�j���Ӯa");

    set("long", @long
�`�Ө����N�O�j�����F..
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


inherit ROOM;

void create()
{
    set("short", "�����~");

    set("long", @long
�����~�`��-��}�l���a...
long);

    set("exits", ([
        "east" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 11,
                      "y_axis": 4,
                 ]),
    ]));

    set("objects", ([
        "/world/area/lake/npc/gin" : 1,
    ]));

    setup();
}

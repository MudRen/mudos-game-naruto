inherit ROOM;

void create()
{
    set("short", "方氏企業");

    set("long", @long
方氏企業總裁-方糖勁的家...
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

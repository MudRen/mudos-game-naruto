inherit ROOM;

void create()
{
    set("short", "捕魚人家");

    set("long", @long
捕魚人家裡擺放了許多的補用魚用具，從漁網到釣竿應有盡有，
甚至外頭還有一艘補魚船。
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"swanlake.c",
                      "x_axis": 6,
                      "y_axis": 7,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/fishing_master.c": 1,
    ]));

    setup();
}

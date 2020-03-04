inherit ROOM;

void create()
{
    set("short", "職業獵人-補習班");

    set("long", @long
這兒是鯨魚島上的一間補習班，專門招收想要考獵人職業的學生。你可以
看到在入口的櫃檯處，已經排了長長要報名保証班的人龍。如果你想要參加本
年度獵人的考試，不仿可以花個錢報個考前衝刺班。
long
);

    set("exits", ([
        "east" : ([ "filename": __DIR__"area.c",
                      "x_axis": 12,
                      "y_axis": 11,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/teacher.c" : 1,
          __DIR__"npc/teacher2.c" : 1,
    ]));

    setup();
}


inherit ROOM;

void create()
{
    set("short", "隔空居");
    set("long", @long
平凡的小屋子，擺設也很普通，門上掛著一個大匾『隔空居』
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"area.c",
                      "x_axis": 22,
                      "y_axis": 30,
                 ]),
    ]));
    set("objects", ([
        "/world/area/old_forest/npc/ying.c" : 1,
    ]));
    setup();
}

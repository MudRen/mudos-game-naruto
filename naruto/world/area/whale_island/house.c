/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "��a");

    set("long", @long
�o�̬O�H���q�W�~���~���ЫΡC
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"area.c",
                      "x_axis": 25,
                      "y_axis": 30,
                 ]),
        "north" : __DIR__"house_back.c",
    ]));

    set("objects", ([
        __DIR__"npc/village.c" : 1,
    ]));

    set("objects", ([
        __DIR__"npc/oldwoman.c" : 1,
    ]));

    setup();
}


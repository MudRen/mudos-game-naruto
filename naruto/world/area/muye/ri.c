/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "日向家");

    set("long", @long
這裡是木葉村的日向家。
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

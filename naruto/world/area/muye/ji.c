/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "吉田家");

    set("long", @long
這裡是木葉村的吉田家，不是吉野家，別搞錯了。
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 11,
                      "y_axis": 18,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/ji.c": 1,
    ]));

    setup();
}

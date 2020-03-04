/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "忍者學校");

    set("long", @long
這裡是木葉村的忍者學校，你所在的位置是忍者學校的正門大廳
，忍者學校是教導學生一些基本的忍術、體術、幻術等等；在忍者學
校畢業後，才能有下忍考試的資格。
long);

    set("exits", ([
        "east" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 10,
                      "y_axis": 37,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/ka.c" : 1,
    ]));

    setup();
}

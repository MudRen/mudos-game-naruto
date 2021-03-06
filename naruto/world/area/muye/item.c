/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "木葉忍具舖");

    set("long", @long
這裡是木葉村的忍具舖了，木葉村所有忍者的忍具都是出自這間
忍具舖師傅之手，大大小小的忍具陳列滿屋子，你一定可以在這裡找
到你需要的忍具。你可以看見忍具舖門口掛著一副聯子，上頭是這樣
子寫著「忍者即仁者，忍具非陽具」，你轉頭回去發現師傅對你微微
一笑，似乎在暗示著你裡頭還有一些「特殊」的忍具。
long);

    set("exits", ([
        "east" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 22,
                      "y_axis": 33,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/eqer.c": 1,
        __DIR__"npc/wper.c": 1,
    ]));

    setup();
}

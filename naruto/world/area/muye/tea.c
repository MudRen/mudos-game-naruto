/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "木葉茶館");

    set("long", @long
這是木葉村遠近馳名的茶館，門口用著茶葉貼成一副聯子，上頭寫
寫「良商不限量，好茶不用泡」，怪不得你眼前來茶館的客人，每個人
猛抓茶葉來吃，果然是不用泡。
long);

    set("exits", ([
        "east" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 12,
                      "y_axis": 30,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/teaer.c": 1,
    ]));

    setup();
}

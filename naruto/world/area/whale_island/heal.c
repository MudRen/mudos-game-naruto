/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "鯨魚藥鋪");

    set("long", @long
這裡是一間專門販賣健康藥品的地方，你可以看見四週陳列了許
許多多的藥品，看起來種類相當齊全，且價格也是十分合理。你又看
見大門口上方掛著一塊鮮紅色的匾額，上頭寫著「藥到無命」，你不
禁心頭一驚，身上冷汗直流，似乎不買些藥補補身子也不行。
long);

    set("exits", ([
        "east" : ([ "filename": __DIR__"area.c",
                      "x_axis": 13,
                      "y_axis": 24,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/piller.c": 1,
    ]));

    setup();
}

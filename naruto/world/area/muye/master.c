/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "火影大樓");

    set("long", @long
這裡是火影大樓一樓會客廳，火影大樓是供木葉村優秀忍者辦事
的地方。木葉村的重大事務也是在火影大樓裡協商。你可以清楚的看
到火影大樓後面的石壁，上頭刻畫了歷代的火影大人頭像，相當的莊
嚴神聖。
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 33,
                      "y_axis": 16,
                 ]),
    ]));

    set("objects", ([
        __DIR__+"npc/muye.c": 1,
        __DIR__"npc/ying.c": 1,
    ]));

    setup();
}

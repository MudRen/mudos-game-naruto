/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "湯");

    set("long", @long
這裡是木葉村特有的溫泉聖地，四週空氣暖烘烘的，你可以看到
附近的溫泉水不時的冒出輕煙，讓你有股衝動想直接跳進去泡。在門口
立著二根長旗，上頭分別寫著「溫泉水裡煮雞蛋，溫泉池裡泡鳥蛋」，
再看看眼前一群男人泡在池子裡邊吃著水煮雞蛋，還真是形容的相當貼
切阿。
long);

    set("exits", ([
        "north" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 14,
                      "y_axis": 41,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/pooler.c": 1,
        __DIR__"npc/poolman.c": 3,
    ]));

    setup();
}

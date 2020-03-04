inherit ROOM;

void create()
{
    set("short", "廢棄物回收店");
    set("long", @long
店裡堆的亂七八糟，只有一條通往門口的路是可以走的，其他位
置都被雜物所堆滿。仔細一瞧，有位穿著簡便的豹人正躺臥在一座疊
地高高的雜物上，讓人不禁害怕他可能稍微一動整堆雜物就垮下來把
你也壓在裡面了。
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"village.c",
                      "x_axis": 16,
                      "y_axis": 6,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/fee.c" : 1,
    ]));
    setup();
}

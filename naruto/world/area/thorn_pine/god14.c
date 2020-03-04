inherit ROOM;

void create()
{
        set("short", "神壇走道");
        set("long", @LONG
這裡是神壇下方圍起來的走道，旁邊圍了一些豹族人正在休息或
是跳舞。神壇上一直傳出永不間斷的歌聲，幾位豹族女性就這樣不停
的輪流上去唱歌。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 14,
                       "y_axis" : 16,
                  ]),
        "west" : __DIR__"god13.c",
        "east" : __DIR__"god15.c",
        "north" : __DIR__"altar04.c",
    ]));
    setup();
}

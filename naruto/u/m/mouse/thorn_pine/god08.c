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
        "west" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 9,
                       "y_axis" : 12,
                  ]),
        "north" : __DIR__"god06.c",
        "south" : __DIR__"god10.c",
        "east" : __DIR__"altar02.c",
    ]));
    setup();
}

inherit ROOM;

void create()
{
        set("short", "神壇上");
        set("long", @LONG
神壇上有幾位女性豹人正在唱歌，對於你的突然衝上神壇，下面
的豹人與唱歌的女豹人也沒有瞪你或是拔出兵刃，還是照常的唱歌跳
舞休息。神壇中心有棵大樹，可以過去瞧瞧。
LONG);
    set("exits", ([
        "west" : __DIR__"bigtree.c",
        "east" : __DIR__"god09.c",
    ]));
    set("objects", ([
        __DIR__"npc/singer.c" : 3,
    ]));
    setup();
}

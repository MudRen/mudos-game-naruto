inherit ROOM;

void create()
{
        set("short", "神壇中心");
        set("long", @LONG
一棵長的歪七扭八的大樹，樹的枝葉茂密，根部幾乎霸佔了整座
的神壇，樹上還結了一些尚未成熟的果實。仔細的看看那些果實，突
然發現果實居然沒有任何一個長的一樣的，不但顏色不同，就連外觀
形狀都不相同，真是好奇為什麼豹人要為這種怪樹設神壇。
LONG);
    set("exits", ([
        "south" : __DIR__"altar04.c",
        "north" : __DIR__"altar01.c",
        "east" : __DIR__"altar03.c",
        "west" : __DIR__"altar02.c",
    ]));
        setup();
}

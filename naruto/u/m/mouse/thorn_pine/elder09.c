inherit ROOM;

void create()
{
        set("short", "一樓大廳");
        set("long", @LONG
正面的牆上掛了一幅很長的畫，這裡所掛只是畫的右半部而已，
畫中所繪是一大群疲於奔命的蜘蛛，有的斷腿、有的受傷不輕、有的
已經倒在半途奄奄一息，共同點就是全都毫無戰意。
LONG);
    set("exits", ([
        "west" : __DIR__"elder08.c",
        "north" : __DIR__"elder06.c",
    ]));
    set("objects", ([
        __DIR__"npc/warrior.c" : 1,
        __DIR__"npc/woman.c" : 1,
    ]));
    setup();
}

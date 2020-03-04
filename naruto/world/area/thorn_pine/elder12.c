inherit ROOM;

void create()
{
        set("short", "二樓小窗");
        set("long", @LONG
坐在椅子上的豹人安靜看著窗外，似乎正在享受這陽光與外面那
美麗的風光。牠應該就是豹人族的族長了，從牠手上的傷口與歲月的
痕跡可以想像的到牠早年為豹族的犧牲與奉獻。
LONG);
    set("exits", ([
        "east" : __DIR__"elder11.c",
    ]));
    set("objects", ([
        __DIR__"npc/head.c" : 1,
    ]));
    setup();
}

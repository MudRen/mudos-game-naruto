inherit ROOM;

void create()
{
        set("short", "一樓大廳");
        set("long", @LONG
周圍擺放著用樹幹做成的椅子和桌子，上面鋪著動物的毛皮顯得
十分舒適，桌子上則放著一些器具。
LONG);
    set("exits", ([
        "east" : __DIR__"elder01.c",
        "south" : __DIR__"elder04.c",
    ]));
        setup();
}

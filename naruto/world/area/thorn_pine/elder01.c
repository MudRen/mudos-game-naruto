inherit ROOM;

void create()
{
        set("short", "一樓大廳");
        set("long", @LONG
以豹人來說是非常氣派的房內佈置了，門口兩旁還有擺放花瓶裝
飾，地上也鋪上了其他動物的毛皮地毯。牆壁上掛了許多動物的頭部
標本，代表著族長以前也是豹村的一代英雄。
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 6,
                       "y_axis" : 18,
                  ]),
        "east" : __DIR__"elder03.c",
        "west" : __DIR__"elder02.c",
        "south" : __DIR__"elder05.c",
    ]));
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;
    if( !me ) return 0;
    if( !userp(me) && dir == "north" ) return 0;
    return ::valid_leave(me, dir);
}

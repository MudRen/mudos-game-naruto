inherit ROOM;

void create()
{
        set("short", "松林小屋");
        set("long", @LONG
躲在松樹林中的一棟小屋子，裡面傳來濃濃的藥味。四周都放著
瓶子，裡面裝著五顏六色的不知名液體，一位身穿白衣的人就一直穿
梭在瓶子之間，偶爾還會將兩瓶倒在一起或是點火加熱，看起來好像
在做什麼實驗的樣子。
LONG);
    set("exits", ([
        "west" : ([ "filename" : __DIR__"pine.c",
                       "x_axis" : 15,
                       "y_axis" : 13,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/sz.c" : 1,
    ]));
    setup();
}

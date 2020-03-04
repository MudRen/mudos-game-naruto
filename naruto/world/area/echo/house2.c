inherit ROOM;

void create()
{
        set("short", "破屋子");
        set("long", @LONG
一間破屋子，看起來非常的凌亂，只有一個中年人頹廢的坐在桌
旁邊的椅子上，不過他兩眼無神，好像已經沒了魂魄，連桌上的油燈
已經燒完都不知道。
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"tomb.c",
                       "x_axis" : 7,
                       "y_axis" : 17,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/zhang.c" : 1,
    ]));
    setup();
}

inherit ROOM;

void create()
{
    set("short", "天上掉下來的醫藥店");
    set("long", @LONG
天上人間的醫藥店，一個相當神秘的地方。
LONG);
    set("exits", ([
        "east" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 5,
                       "y_axis" : 24,
                  ]),
    ]));
    
    set("objects", ([
        __DIR__"npc/piller.c" : 1,
    ]));
    setup();
}
inherit ROOM;

void create()
{
        set("short", "武器王");
        set("long", @LONG
一種熟悉的味道，武士、戰士的味道，鐵器的味道。從牆上角落
多到數不清的武器，就了解為什麼外面的招牌敢打著「武器王」的名
號。在這裡的牆上還掛了另一塊牌子寫著「雙手兵」
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 5,
                       "y_axis" : 6,
                  ]),
        "east" : __DIR__"wp03.c",
        "west" : __DIR__"wp02.c",
    ]));
    set("objects", ([
        __DIR__"npc/kr.c" : 1,
    ]));
    setup();
}

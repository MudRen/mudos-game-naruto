inherit ROOM;

void create()
{
        set("short", "武器王");
        set("long", @LONG
一種熟悉的味道，武士、戰士的味道，鐵器的味道。從牆上角落
多到數不清的武器，就了解為什麼外面的招牌敢打著「武器王」的名
號。在這裡的牆上還掛了另一塊牌子寫著「單手兵」
LONG);
    set("exits", ([
        "east" : __DIR__"wp01.c",
    ]));
    set("objects", ([
        __DIR__"npc/gr.c" : 1,
    ]));
    setup();
}

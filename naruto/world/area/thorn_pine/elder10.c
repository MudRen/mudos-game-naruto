inherit ROOM;

void create()
{
        set("short", "二樓樓梯");
        set("long", @LONG
一條通往樓下的樓梯，可以回到剛才的大廳。
LONG);
    set("exits", ([
        "west" : __DIR__"elder11.c",
        "down" : __DIR__"elder03.c",
    ]));
        setup();
}

inherit ROOM;

void create()
{
        set("short", "房間內");
        set("long", @LONG
一間舒適的房間，你可以在這裡得到充分的休息。
LONG);
    set("exits", ([
        "down" : __DIR__"hometam.c"
    ]));
    setup();
}

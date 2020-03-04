#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "遊戲室(３)");
	set("long", @LONG
這是一間休閒娛樂場所，附近可能擺放一些好玩的東西
LONG);

	set("exits", ([
		"west" : __DIR__"game2",
		"south" : __DIR__"game6",
	]));

    set("objects", ([
    	_DIR_ITEM_"big2.c" : 1,
    ]));

    set("no_fight", 1);
	setup();
}
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "遊戲室(８)");
	set("long", @LONG
這是一間休閒娛樂場所，附近可能擺放一些好玩的東西
LONG);

	set("exits", ([
        "south" : ([ "filename" : __DIR__"wizard.c",
                     "x_axis" : 26,
                     "y_axis" : 39,
                  ]),		
		"north" : __DIR__"game5",		
		"west" : __DIR__"game7",		
		"east" : __DIR__"game9",		
	]));

    set("objects", ([
    	_DIR_ITEM_"big2.c" : 1,
    ]));

    set("no_fight", 1);
	setup();
}
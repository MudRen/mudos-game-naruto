#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�C����(��)");
	set("long", @LONG
�o�O�@���𶢮T�ֳ��ҡA����i���\��@�Ǧn�����F��
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
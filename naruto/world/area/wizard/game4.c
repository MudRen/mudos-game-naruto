#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�C����(��)");
	set("long", @LONG
�o�O�@���𶢮T�ֳ��ҡA����i���\��@�Ǧn�����F��
LONG);

	set("exits", ([
        "west" : ([ "filename" : __DIR__"wizard.c",
                     "x_axis" : 23,
                     "y_axis" : 36,
                  ]),				
		"north" : __DIR__"game1",		
		"east" : __DIR__"game5",		
		"south" : __DIR__"game7",		
	]));

    set("objects", ([
    	_DIR_ITEM_"big2.c" : 1,
    ]));

    set("no_fight", 1);
	setup();
}
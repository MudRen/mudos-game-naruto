#include <room.h>

inherit BANK;

void create()
{
	set("short", "�ѤW���U�Ӫ��Ȧ�");
	set("long", @LONG
�ѤW�H�����Ȧ�A�@�Ӭ۷������a��C
    �s���Gdeposit
    �����Gwithdraw
    �׿��Goutward
    �d�ߡGbalance
LONG);
    set("exits", ([
        "east" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 5,
                       "y_axis" : 36,
                  ]),
    ]));
    set("objects", ([
        _DIR_AREA_"old_forest/npc/test.c": 1,
    ]));
	setup();
}

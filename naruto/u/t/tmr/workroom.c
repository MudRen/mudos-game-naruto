// File: /u/t/tmr/workroom.c
// Updated by tmr (Tue Oct 18 21:20:34 2005)

inherit ROOM;

void create()
{
	  set("short", "八荒六合");
	  set("long", @LONG
一個沒有時間及空間的地方，世間上所有發生的事，在這兒完全沒有意義。
LONG
	  );
	  set("valid_startroom", 1);
	  set("recoverroom", 1);
//          set("no_fight", 1);
	  set("exits", ([ /* 2 element(s) */
	"south" : ([ /* 3 element(s) */
	    "filename" : "/world/area/wizard/wizard.c",
	    "x_axis" : 31,
	    "y_axis" : 15,
	  ]),
	"wizard" : "/world/area/wizard/guildhall.c",
]));

	setup();
    load_object("/daemon/board/tmr");
}

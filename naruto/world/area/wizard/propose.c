inherit ROOM;

void create()
{
	set("short", "白魔法陣");
	set("long", @LONG
在這個房間充滿著一股堅固的白魔法防禦術，你可以在這裡暢所
欲言，絕對不會受到窮兇極惡的蟑螂部隊威脅。
LONG
	);
	set("exits", ([
		"west" : __DIR__"guildhall",
		"east" : ([ "filename" : __DIR__"wizard.c",
					 "x_axis" : 13,
					 "y_axis" : 5,
				  ]),
	]));
    set("objects", ([
        "/obj/stone.c": 1,
    ]));

	setup();
	load_object("/daemon/board/propose");
	replace_program(ROOM);
}

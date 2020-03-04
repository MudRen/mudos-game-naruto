inherit ROOM;

void create()
{
	set("short", "新手學堂");
	set("long", @LONG
這裡是新手教學學堂的大門口，你可以看到來來往往的新手，每
個人臉上都充滿了期待。在新手學堂裡，會教導一些遊戲中的基本常
識和操作方法，並且指導如何在這個世界中闖盪。
LONG
	);
	set("exits", ([
        "west" : ([ "filename" : __DIR__"wizard.c",
                    "x_axis" : 15,
                    "y_axis" : 5,
                  ]),		
	]));

    set("objects", ([
    	__DIR__"npc/zhang.c" : 1,
    ]));

	setup();

	load_object("/daemon/board/newbie");

	replace_program(ROOM);
}

inherit ROOM;

void create()
{
	set("short", "���]�k�}");
	set("long", @LONG
�b�o�өж��R���ۤ@�Ѱ�T�����]�k���m�N�A�A�i�H�b�o�̺Z��
�����A���藍�|����a�����c�����������¯١C
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

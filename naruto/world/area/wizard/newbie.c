inherit ROOM;

void create()
{
	set("short", "�s��ǰ�");
	set("long", @LONG
�o�̬O�s��оǾǰ󪺤j���f�A�A�i�H�ݨ�Өө������s��A�C
�ӤH�y�W���R���F���ݡC�b�s��ǰ�̡A�|�оɤ@�ǹC�������򥻱`
�ѩM�ާ@��k�A�åB���ɦp��b�o�ӥ@�ɤ������C
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

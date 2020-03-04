// File: /u/t/tmr/workroom.c
// Updated by tmr (Tue Oct 18 21:20:34 2005)

inherit ROOM;

void create()
{
	  set("short", "�K��X");
	  set("long", @LONG
�@�ӨS���ɶ��ΪŶ����a��A�@���W�Ҧ��o�ͪ��ơA�b�o�৹���S���N�q�C
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

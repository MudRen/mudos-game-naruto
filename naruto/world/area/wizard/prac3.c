#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�m�߳�(��)");
	set("long", @LONG
�o���\��F�X�Ӱ��H�A�i�H�b�o�̽m�ޮ氫�ޯ�C
LONG);

	set("exits", ([
		"west" : __DIR__"prac2",
		"south" : __DIR__"prac6",
	]));

    set("objects", ([
    	_DIR_NPC_"stake.c": 4,
    ]));

	setup();
}
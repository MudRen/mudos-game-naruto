inherit ROOM;

void create()
{
	set("short", "���]�k�}");
	set("long", @LONG
�o�өж��|�g�G���F�j�j�����]�k�����N�A���G�O���F�ٱ���B
��«���������A�b�A���e���۰�n�p�s���������e�A�i���o���]�k��
���N�۷��ΡC
LONG
	);
	set("exits", ([
		"east" : __DIR__"guildhall",
	]));

	setup();
	load_object("/daemon/board/bug");
	replace_program(ROOM);
}

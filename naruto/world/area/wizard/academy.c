
inherit ROOM;

void create()
{
	set("short", "�Ův�ǰ|");
	set("long", @LONG
�o�̬O�Ův�̬�s�Q�׳o�ӥ@�ɥ��Ӫ����ҡA�A�i�H�ݨ�\�h��
�v��⹺�}�a������׵ۦۤw���Q�k�A�A�]�i�H�@�P�ѻP�L�̪��Q��
�A���o�ӥ@�ɧ���n�C
LONG
	);
	set("exits", ([
		"south" : __DIR__"guildhall",
	]));

	setup();
	load_object("/daemon/board/design");
	replace_program(ROOM);
}
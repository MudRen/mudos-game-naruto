#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�����O");
	set("long", @LONG
�o�өж��s�b�ۤ@�Ǥ��i��ĳ���O�q�A�ǻ����b�o�̬I�i�@�ǯS
���T�ҧųN�A�i�H���ܳo�ӥ@�ɪ��Ҧ��ƪ��A��b�O�Ӥ��i��ĳ�F
�C�b�o�̥R����i����^�A�A���ѱo�Q�������}�C
LONG
	);

	set("exits", ([
		"north" : __DIR__"guildhall",
	]));

	setup();

    load_object("/daemon/board/chat");
}
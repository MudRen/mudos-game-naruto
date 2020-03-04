#include <ansi.h>
#include <room.h>

inherit INN;

/*
void create()
{
	set("short", HIR"Released Workroom "HIY"[Ver 1.0 beta] "NOR);
	set("long", @LONG
    �o�O�@�ӭ觹�����u�@���A�O�ѦU��Ův�@�֥Ϊ��ж��A�Ŷ���
�]��Ӫw����ѡA�ͬ��y���A²���O�Ův�������t�a�A�t�a��������
��C
LONG);
	set("name", query("short"));
	set("x_axis_size", 8);
	set("y_axis_size", 5);
	setup();
}
*/

void init()
{
	object me, room;

	me = this_player();

	if( !me || !objectp(me) ) return;

	seteuid(geteuid(me));

	room = load_object(__DIR__"workarea.c");

	area_move(room, me, 6, 6);
}

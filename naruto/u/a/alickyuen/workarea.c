#include <ansi.h>
#include <room.h>

inherit AREA;

void create()
{
	set("short", HIR"Released Workroom "HIY"[Ver 1.0 beta] "NOR);
	set("long", @LONG
    �o�O�@�ӭ觹�����u�@���A�O�ѦU��Ův�@�֥Ϊ��ж��A�Ŷ���
�]��Ӫw����ѡA�ͬ��y���A²���O�Ův�������t�a�A�t�a��������
��C
LONG);
	set("name", query("short"));
	set("x_axis_size", 3);
	set("y_axis_size", 3);
	setup();
}

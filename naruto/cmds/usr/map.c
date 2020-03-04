/* map.c */

#include <command.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string file, text;
	object area;
	
	if( !(area = environment(me)) ) return 0;
	if( !area->is_area() ) return notify_fail("�o�ӫ��O�u�A�Φb�ϰ����Ҥ��C\n");
	
	// �ϰ�j�A�������B�k�G��������
	if( area->query("x_axis_size") > 49 ) {
		if( me->query("area_info/x_axis") <= 49 ) file = file_name(area) + "_left.ansi";
		else file = file_name(area) + "_right.ansi";
	} else file = file_name(area) + ".ansi";

    if( file_size(file) <= 0 ) return notify_fail("�ثe�o�Ӱϰ�S���a���ɡC\n");
    
    if( !(text = read_file(file)) ) text = "";

    me->start_more(text);

	return 1;
}

int help(object me)
{
    write(@HELP
���O�榡�G map

�o�ӫ��O�i�H���A�d�ݰϰ����Ҫ����ϡA�u�A�Φb�ϰ����Ҥ��A�@��
�ж����ҵL�k�ϥΡC
HELP);
	return 1;
}
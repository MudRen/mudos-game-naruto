/* goto.c */
#include <command.h>

inherit F_CLEAN_UP;

private void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    int x, y;
    string file, out_msg, in_msg;
    object obj;

    SECURED_COMMAND;

    if( !arg ) return notify_fail("�A�n�h���̡S\n");

    if( sscanf(arg, "goto_out_msg %s", out_msg) == 1 ) {
    	me->set("goto_out_msg", color(out_msg));
    	write("Ok.\n");
    	return 1;
    } else if( sscanf(arg, "goto_in_msg %s", in_msg ) == 1 ) {
    	me->set("goto_in_msg", color(in_msg));
    	write("Ok.\n");
    	return 1;
    }

    if( me->query("goto_out_msg") ) out_msg = me->query("goto_out_msg") + "\n";
    else out_msg = "�u���@�}�����L��A$N�����v�w�g�����F�C\n";

    if( me->query("goto_in_msg") ) in_msg = me->query("goto_in_msg") + "\n";
    else in_msg = "�u���@�}�����L��A$N�����v�w�g�Ө�F�o�̡C\n";

    // goto ��ϰ� by -Acme-
    if( sscanf(arg, "%s %d %d", file, x, y) == 3 ) {
        file = resolve_path(me->query("cwd"), file);
        if( !sscanf(file, "%*s.c") ) file += ".c";
        if( file_size(file) >=0 && (obj=load_object(file)) ) {
			if( !obj->is_area() ) return 1;
	    	message_vision(out_msg, me);
			area_move(obj, me, x, y);
		    message_vision(in_msg, me);
		    return 1;
        } else {
        	write("�o�Ӱϰ��ɤ��s�b�C\n");
        	return 1;
        }
        
    // �ۤw���B��Ϫ��y��goto
    } else if( sscanf(arg, "%d %d", x, y) == 2 ) {
    	if( !environment(me)->is_area() ) return 1;
    	message_vision(out_msg, me);
		area_move(environment(me), me, x, y);
	    message_vision(in_msg, me);
   		return 1;
    }

    obj = find_player(arg);
    if( !obj ) obj = find_living(arg);
    if( obj == me ) {
    	write("�A�n����ۤw���ǡH\n");
    	return 1;
    }

    // ����@��ж�
    if( !obj || !obj->visible(me)) {
        arg = resolve_path(me->query("cwd"), arg);
        if( !sscanf(arg, "%*s.c") ) arg += ".c";
        if( file_size(arg) >=0 && (obj=load_object(arg)) ) {
            if( obj->is_area() ) {
            	write("���ʨ�ϰ쪫��A���ݥ[�W�y�Ф~�ಾ�ʡC\n");
            	return 1;
            }
   	        message_vision(out_msg, me);
            me->move(obj);
   	        message_vision(in_msg, me);
    		return 1;
        } else return notify_fail("�S���o�Ӫ��a�B�ͪ��B�Φa��C\n");
    }

    if( !environment(obj) ) return notify_fail("�o�Ӫ���S�����ҥi�H goto�C\n");

    if( environment(obj)->is_area() ) {
    	if( area_environment(obj, me) ) return notify_fail("�A�w�g�b�L���ǤF�C\n");

        message_vision(out_msg, me);
		if( !area_move(environment(obj), me, obj->query("area_info/x_axis"), obj->query("area_info/y_axis")) ) {
            tell_object(me, "�]���Y�زz�ѡA�A�� goto ���ѤF�C\n");
		}
    } else {
        message_vision(out_msg, me);
        if( !me->move(environment(obj)) ) {
            tell_object(me, "�]���Y�زz�ѡA�A�� goto ���ѤF�C\n");
        }
    }

    message_vision(in_msg, me);

    return 1;
}

int help(object me)
{
    write(@HELP
���O�榡 : goto <�ؼ�>
 
�o�ӫ��O�|�N�A�ǰe����w���ؼСC�ؼХi�H�O�@��living �Ωж�
���ɦW�C�p�G�ؼЬOliving�A�A�|�Q����򨺭ӤH�P�˪����ҡC

�A�i�H�ۦ�]�wgoto�����}�T���A�άOgoto���i�ӰT���C
�p�G goto goto_out_msg $HIW$�A�i�Hť��$N�z�������@�n�A���}�F�o�̡C
     goto goto_in_msg  $HIW$�A�i�Hť��$N�z�������@�n�A�Ө�F�o�̡C
�ϥΦ�X�t�Φb�̫�|�۰ʥ[�W$NOR$�ҥH�i�H���ݭn�A�[�@���C
HELP);
    return 1;
}

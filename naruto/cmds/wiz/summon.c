/*  summon.c

    Copyright (C) 1994-2000 Annihilator <annihilator@muds.net>

    This program is a part of ES2 mudlib. Permission is granted to use,
    modify, copy or distribute this program provided this copyright notice
    remains intact and subject to the restriction that this program MAY
    NOT be used in any way for monetary gain.

    Details of terms and conditions is available in the Copyright.ES2 file.
    If you don't receive this file along with this program, write to the
    primary author of ES2 mudlib: Annihilator <annihilator@muds.net>
*/

#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
    object ob;
    int i;

    seteuid(getuid(me));
    if(!str) return notify_fail("���O�榡: summon <�ϥΪ�>\n");
    ob = LOGIN_D->find_body(str);
    if(!ob) return notify_fail("�u�W���ϥΪ̤��S���o�ӤH�C\n");

   if( wiz_level(me) <= wiz_level(ob) ) return notify_fail("�A����o�˰��I\n");
    if( environment(me)->is_area() ) {
    	mapping info;
    	info = me->query("area_info");
    	if( !info ) return 1;

		if( environment(ob)->is_area() )
	   		tell_area(environment(ob), ob->query("area_info/x_axis_old"), ob->query("area_info/y_axis"), "�ѪŤ����X�@���j���"+ ob->name() + "��F�_�ӡM�M�ᤣ���F�C\n", ({ob}));
	    else tell_room(environment(ob), "�ѪŤ����X�@���j���"+ ob->name() + "��F�_�ӡM�M�ᤣ���F�C\n", ob);

	    if( area_move(environment(me), ob, info["x_axis"], info["y_axis"]) ) 
       		tell_area(environment(me), info["x_axis"], info["y_axis"], ob->name() + "��M�X�{�b�A���e�C\n", ({ob,me}));

    } else {
        if( environment(ob)->is_area() )
    		tell_area(environment(me), ob->query("area_info/x_axis"), ob->query("area_info/y_axis"), "�ѪŤ����X�@���j���"+ ob->name() + "��F�_�ӡM�M�ᤣ���F�C\n", ({ob}));
	    else tell_room(environment(ob), "�ѪŤ����X�@���j���"+ ob->name() + "��F�_�ӡM�M�ᤣ���F�C\n", ob);
		if( ob->move(environment(me)) )
			tell_room(environment(ob), ob->name() + "��M�X�{�b�A���e�C\n", ({me,ob}) );
    }

    tell_object(me, "�A��" + ob->name() + "���A�����e�C\n");
    tell_object(ob,"�@�����A��F�_�ӡM�A���e�@�}�� ....\n");
    tell_object(ob,".... ���Ӯɵo�{�O" + me->name() + "��A�˹L�Ӫ��C\n");

    log_file("static/SUMMON", sprintf("%s(%s) summon %s(%s) �� %s%s at %s\n",
				me->name(1),
				geteuid(me),
				ob->name(1),
				geteuid(ob),
				file_name(environment(me)),
		        environment(me)->is_area() ? "(" + me->query("area_info/x_axis") + "," + me->query("area_info/y_axis") + ")" : "",
				ctime(time()) ) );

    // ok ..
    return 1;
}

int help(object me)
{
write(@HELP
���O�榡 : summon <�Y�H>

�����O�i���A(�p)�N�Y�H���A���e�C
HELP
    );
    return 1;
}

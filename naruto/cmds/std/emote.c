// emote.c (Mon  09-04-95)

#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string str)
{
	mapping info;
	
	info = me->query("area_info");
	
    if (!str) {
        write(CYN"�A�ݰ_�Ӫ��״I�C\n"NOR);
        if( environment(me)->is_area() ) 
        	tell_area(environment(me), info["x_axis"], info["y_axis"], CYN+(string)me->name()+"�ݰ_�Ӫ��״I�C\n"+NOR, ({me}));
        else  tell_room(environment(me), CYN+(string)me->name()+"�ݰ_�Ӫ��״I�C\n" +NOR, me);
        return 1;
    }
    write(CYN"�A"+str+"\n"NOR);
    if( environment(me)->is_area() )
      	tell_area(environment(me), info["x_axis"], info["y_axis"], CYN+(string)me->name()+str+"\n"+NOR, ({me}));
    else tell_room(environment(me), CYN+(string)me->name()+ str+"\n"+NOR, me);
    return 1;
}
 
int help(object me)
{
	write(@HELP
���O�榡: emote <�ʧ@��>

�o�ӫ��O�i�H���A��F�@�Өt�ΨS���w�]���ʧ@��, �t�η|�N�A�ҿ�J
����r�[�W�A���m�W����ܵ��Ҧ��b�P�@�Ӧa�誺�ͪ���. ���F�קK�y
���x�Z, ���a�ҿ�J�����y�e���|�[�W -> �H�ѰϧO. (�Ův�h���b��
��.)

�d��: emote ���F�U�ӡC
�A�|�ݨ�: �A���F�U�ӡC
��L�H�|�ݨ�: ->�]�l���F�U�ӡC

�䤤, �]�l�N�O�A���W�r.

�������O: semote
HELP
	);
        return 1;
}

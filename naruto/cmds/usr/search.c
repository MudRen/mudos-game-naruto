// search.c

#include <ansi.h>

inherit F_CLEAN_UP;

int searching(object me, object env);
int find_drug(object me,int drug_num);

int main(object me, string arg)
{
	int i;
    object env;
    string msg="", *exits, *detail;

	if( me->is_fighting() || me->is_busy() )
		return notify_fail("�A���b����, �иյۥ� halt ����Ҧ����ơC\n");

    if( !objectp(env=environment(me)) ) return 0;

        message_vision("$N�S�X�ԷV�������A�}�l�|�B½½���C\n", me);
	me->start_busy(1);

    if( env->is_area() ) {
    	string temp;
        mapping info, detail_a;
        
        info = me->query("area_info");
        
        // �ϰ�W
        msg = "\n" + env->query("name");
        
        // short �y�z
        if( (temp=env->query_data(info["x_axis"], info["y_axis"], "short")) ) 
            msg += " - " + temp + "\n";
        else msg += "\n";

        // long �y�z
        if( (temp=env->query_data(info["x_axis"], info["y_axis"], "long")) ) 
            msg += "    " + temp + "\n";
        else msg += "\n";
        
        // �X�f����
        exits = env->query_exits(info["x_axis"], info["y_axis"]);
        if( (i = sizeof(exits)) ) {
    	    msg += "�o�̩��㪺�X�f�O ";
    	    while( i-- ) msg += HIW+exits[i]+NOR + ( i ? "�B" : "�C\n" );
        } else msg += "  �o�̨S������X�f�C\n";

        // �Ӹ`����
    	detail_a = env->query_area_detail(info["x_axis"], info["y_axis"]);
    	if( (i=sizeof(detail_a)) ) {
    		msg += "\n�s�b��o�̪��ƪ����G\n";
    		detail = keys(detail_a);
    		while(i--) msg += "  " + detail[i] + "\n";
    	}
    } else {
        msg = "\n" + env->query("short") + " -\n";
    	msg += "    " + env->query("long");
        // �X�f����
        if( (i = sizeof(env->query("exits"))) ) {
            exits = keys(env->query("exits"));
    	    msg += "    �o�̩��㪺�X�f�O ";
    	    while( i-- ) msg += HIW+exits[i]+NOR + ( i ? "�B" : "�C\n" );
        } else msg += "  �o�̨S������X�f�C\n";
    	
    	if( (i=sizeof(env->query("detail"))) ) {
    		msg += "\n�s�b��o�̪��ƪ����G\n";
    		detail = keys(env->query("detail"));
    		while(i--) msg += "  " + detail[i] + "\n";    		
    	}
    }

    me->start_more(msg);

	return 1;
}

int help(object me)
{
	write(@HELP
���O�榡�Rsearch

�o�ӫ��O�i�H���A���A�����Ҥ��O�_���S���F��A�\�h�����ȡB�t�СB�S���~
���i�� search ����o�@�Ǻݭ٩δM��N�~���F��C

HELP
	);
	return 1;
}

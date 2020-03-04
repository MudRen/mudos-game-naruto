/* advance */

#include <ansi.h>
#include <attribute.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int add_attribute(object me, string attr, int amount)
{
    if( me->query_point("attribute") < amount ) {
        write("�A���ݩ��I�Ƥ����A�L�k���ɤH���ݩʡC\n");
        return 1;
    }
    
    if( me->query_attr(attr, 1) + amount > ATTRVAL_MAX ) {
        write("�A���ݩ� " + attr + " �L�k���ɳo��h�A�W����"+ chinese_number(ATTRVAL_MAX) +"�C\n");
        return 1;
    }
    
    me->add_point("attribute", -amount);
    me->set_attr(attr, me->query_attr(attr, 1) + amount);
    
    write(HIY"�A���ݩ� " + attr + " ����" + chinese_number(amount) + "�I�F�I\n"NOR);
    
    return 1;
}

int add_state(object me, string state, int amount)
{
    if( me->query_point("score") < amount ) {
        write("�A������I�Ƥ����A�L�k���ɤH�����A�C\n");
        return 1;
    }
    
    if( me->query_stat_maximum(state) + amount > 9999 ) {
        write("�A�����A " + state + " �L�k���ɳo��h�A�W�����E�d�E�ʤE�Q�E�C\n");
        return 1;
    }
    
    me->add_point("score", -amount);
    me->advance_stat(state, amount);
    me->heal_stat(state, amount);

    write(HIY"�A�����A " + state + " ����"+ chinese_number(amount) +"�I�F�I\n"NOR);

    return 1;
}

int add_skill(object me, string skill, int amount)
{
    int i;
    if( me->query_point("skill") < amount ) {
        write("�A���ޯ��I�Ƥ����A�L�k���ɤH���ޯ�W���C\n");
        return 1;
    }

    if( me->query_skill_ability(skill) + amount > 10 ) {
        write("�A���ޯ� " + skill + " �L�k���ɳo��h�A�ޯ���I�̰����Q�I�C\n");
        return 1;
    }
    
    me->add_point("skill", -amount);

    for(i=1;i<=amount;i++) me->add_skill_ability(skill);
    
    write(HIY"�A���ޯ� " + skill + " �W������" + chinese_number(amount*20) + "�ŤF�I\n"NOR);
    
    return 1;
}


void add_level(object me)
{
	if( me->query_level() >= CLASS_D(me->query_class())->getMaxLV() ) {
		write("�A�����Ťw�g�F���¾�~���W���F�C\n");
		return;
	}
	
	if( me->query_point("learn") <  CLASS_D(me->query_class())->getLvUpExp(me) ) {
		write("�A���ǲ��I�Ƥ��� " + CLASS_D(me->query_class())->getLvUpExp(me) + " �L�k���ɵ��šC\n");
		return;
	}
	
    me->add_point("learn", -CLASS_D(me->query_class())->getLvUpExp(me));
    me->add("level",1);
	CLASS_D(me->query_class())->advance_level(me);
    RACE_D(me->query_race())->advance_level(me);
    
	write(HIY"�A�����Ŵ��ɦ� " + me->query_level() + " �šC\n"NOR);
}

int main(object me, string arg)
{
    int amount;

    if( !arg ) return notify_fail("�A�Q���ɤH���������O�H\n");
    
    if( sscanf(arg, "%s for %d", arg, amount) != 2 ) amount = 1;

    if( amount < 0 ) return notify_fail("�A�Q���C�H������O�H\n");

    // ���ɤH������
    if( arg == "level" ) {
    	add_level(me);
    	return 1;
    }
    
    if( arg == "check" )  {
	    if( me->query_level() >= CLASS_D(me->query_class())->getMaxLV() )
		    return notify_fail("�A�����Ťw�g�F���¾�~���W���F�C\n");
		
        write("���Ŵ��ɦ� " + (me->query_level()+1) + " �šA�ݭn " + CLASS_D(me->query_class())->getLvUpExp(me) + " �I�ǲ��I�ơC\n");
    	return 1;
    }
    
    // ���ɤH���ݩ�
    if( arg == "str" || arg == "con" || arg == "dex" || arg == "int" ) {
        add_attribute(me, arg, amount);
        return 1;
    }
    
    // ���ɤH�����A
    if( arg == "ap" || arg == "hp" || arg == "mp" ) {
        add_state(me, arg, amount);
        return 1;
    }
    
    // ���ɤH���ޯ�
    if( me->query_skill(arg, 1) ) {
        add_skill(me, arg, amount);
        return 1;
    }
    
    write("�S�� " + arg + " �o���ݩʡB���A�Χޯ�A�A�L�k���ɥ����O�C\n");

    return 1;
}

int help()
{
    write(@TEXT
���O�榡�G advance <�ݩʡB���A�Χޯ�> [for <�I��>]

�o�ӫ��O�i�H���ɤH������O�C

�ҡG
advance level        ���ɤH��������
advance check        �˵��H�����ɵ��Żݭn���ǲ��I��
advance str          ���ɤH�����O�q�ݩ�1�I�A�ϥΫᦩ���@�I�ݩ��I��
advance con for 3    ���ɤH��������ݩ�3�I�A�ϥΫᦩ���T�I�ݩ��I��
advance dex          ���ɤH�����ӱ��ݩ�1�I�A�ϥΫᦩ���@�I�ݩ��I��
advance int for 2    ���ɤH�������z�ݩ�2�I�A�ϥΫᦩ���G�I�ݩ��I��

advance ap           ���ɤH���믫�Ȫ��A1�I�A�ϥΫᦩ���@�I����I��
advance hp for 50    ���ɤH����O�Ȫ��A50�I�A�ϥΫᦩ�����Q�I����I��
advance mp           ���ɤH���d�J�Ԫ��A1�I�A�ϥΫᦩ���@�I����I��

advance combat      �ޯ�combat��@�I�A�ޯ�W������20��
advance dodge for 3 �ޯ�dodge��T�I�A�ޯ�W������60��
TEXT);
    return 1;
}

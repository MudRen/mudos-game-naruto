// write by -Acme-
#include <ansi.h>

inherit ROOM;
inherit F_SAVE;

int isBuild() { return 1; }

void create()
{
    set("short", "�Ŧa");
    set("long", "�o�O�@������]�S�����Ŧa�C\n");
    setup();
    restore();
}

string query_save_file() { return file_name(this_object()); }

void init()
{
    // ���O�Ův�B���O�֦��̡A�O���঳�ʧ@��
    if( this_object()->query("owner") != this_player()->query_id() && !wizardp(this_player()) )
        return;
    
    // �@��@�Ϋ��O
    add_action("do_set_short", "short");  // �]�w�ж�short
    add_action("do_set_long", "long");    // �]�w�ж�long
    
    if( this_object()->query("_IS_WELL_") ) add_action("do_drink", "drink");
}

int do_set_short(string arg)
{
    object me;
    me = this_player();

    if( !arg ) return notify_fail("�A�n�]����ж��W�١H\n");
    if( strlen(arg) > 10 ) return notify_fail("�ж��W�ٳ̪����Q�Ӧr��(���Ӥ���r)�C\n");
    
    this_object()->set("short", arg);
    this_object()->save();
    
    tell_object(me, "ok.\n");
    
    return 1;
}

int do_set_long(string arg)
{
    object me;
    me = this_player();

    if( !arg ) return notify_fail("�A�n�]����ж��W�١H\n");
    if( strlen(arg) > 100 ) return notify_fail("�ж��ԭz�̪����@�ʭӦr��(���Q�Ӥ���r)�C\n");
    
    this_object()->set("long", arg);
    this_object()->save();
    
    tell_object(me, "ok.\n");
    
    return 1;
}

// for well
int do_drink(string arg)
{
    int old_time, cd_time;
    object me;
    
    me = this_player();
    cd_time = 3600;
    old_time = this_object()->query("_IS_WELL_TIME_");
    
    if( old_time ) {
        int diff, m, s;
        diff = time() - old_time;
        if( diff < cd_time ) {
        	m = (cd_time-diff)/60;
        	s = (cd_time-diff)%60;
            tell_object(me, "�٭n�g�L " + chinese_number(m) + "��" + chinese_number(s) + "�� ���������~�|�A���͡C\n");
            return 1;
        }
    }
	
	// �^�����A
    me->heal_stat("ap", me->query_stat_maximum("ap"));
    me->heal_stat("hp", me->query_stat_maximum("hp"));
    me->heal_stat("mp", me->query_stat_maximum("mp"));
	message_vision(HIW"$N�q�����̯�_�@�j�����A�ƨg�����L����A�{�l�����o�Y�X�ӤF�A��������ܥ��F�I\n"NOR, me);
    tell_object(me, HIY"(�A�����A������_�F�I)\n"NOR);
	
	this_object()->set("_IS_WELL_TIME_", time());
	this_object()->save();
	
	return 1;
}

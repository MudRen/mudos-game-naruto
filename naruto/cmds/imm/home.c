// home.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string id, msg;
	object home;

    id = me->query_id();
    
    if( arg ) {
    	if( !objectp( home = load_object("/u/" + arg[0..0] + "/" + arg + "/workroom.c") ) ) {
    		write(arg + "���u�@�ؿ��U�S��workroom���s�b�A�A�L�k���ʡC\n");
    		return 1;
    	}
		message_vision("$N�V���H������A��" + arg + "�a����l�h�C\n", me);
		if( me->move(home) )
			message("tell_room", "�@�}���ϹL�h��A" + me->name() + "�Ө�F�o�̡C\n", environment(me), me);
		return 1;
    }

	if( !objectp( home = load_object("/u/" + id[0..0] + "/" + id + "/workroom.c") ) ) {
		message_vision("$N�V���H������A�^�a�h�F�C\n", me);
		me->move("/world/area/wizard/guildhall");
		message("tell_room", me->name() + "�^��F�ۤv���a���C\n", environment(me), me);
		return 1;
	}

	if( stringp(msg = me->query("env/msg_home")) )
		message_vision(msg + "\n", me);
	else
		message_vision("$N�V���H������A�^�a�h�F�C\n", me);
	me->move(home);
	message("tell_room", me->name() + "�^��F�ۤv���a���C\n", environment(me), me);
	return 1;
}

int help(object me)
{
  write(@HELP
���O�榡 : home [id]

�Q�Φ��@���O�i�����^��ۤv���u�@�ǩΧO���Ův���u�@�ǡA�Y home directory ��
�L workroom.c �ɡA�h�^�� wiz guild�C�p�G�A workroom.c ���� 'msg_home' �o��
�]�w, �h�b�����H���|�ݨ쨺�ӰT���C
HELP
    );
    return 1;
}

/* train.c �V�m�ޯ���O by -Acme- */

inherit F_CLEAN_UP;

int do_train(object me, object trainer, string skill, int count)
{
	if( !objectp(me) || !objectp(trainer) ) return notify_fail("�o�̨S���o�ӤH�C\n");
	
    // ���O�V�m�v
	if( !trainer->is_trainer() ) return notify_fail("�o�ӤH���G���Q�ЧA�C\n");
	
    // �p�G�O�b�ϰ����Ҥ��A���P�y�СA���|���ʧ@
	if( environment(me)->is_area() )
		if( !area_environment(me, trainer) ) return notify_fail("�o�̨S���o�ӤH�C\n");

    // all: �����Ԫ̧�, �_�h�ݬO�_�ۦP���Ԫ̧�
    if( trainer->query("guild") != "all" &&  trainer->query("guild") != me->query("guild") )
        return notify_fail("�����G���Q�ЧA�C\n");
	
	return trainer->train_skill(me, skill, count);
}

int main(object me, string arg)
{
	int count;
	object trainer;
	string skill, who;
	
	if( !arg ) return notify_fail("�A�Q�V�ְQ�ШðV�m�A���ޯ�H\n");
	
    if( me->query_condition("weak") ) return notify_fail("�A�{�b�����p�L�k�ǲߧޯ�C\n");

	if( sscanf(arg, "%s from %s for %d", skill, who, count) == 3 ) {
        if( !objectp(trainer = present(who, environment(me))) )
            return notify_fail("�A������S���o�ӤH�C\n");
	} else if( sscanf(arg, "%s from %s", skill, who) == 2 ) {
        if( !objectp(trainer = present(who, environment(me))) )
            return notify_fail("�A������S���o�ӤH�C\n");
		count = 1;
	}

    if( count <= 0 ) count = 1;

    return do_train(me, trainer, skill, count);
}

int help()
{
    write(@TEXT
���O�榡�Rtrain <�ޯ�W��> from <�H��> [for <����>]

�o�ӫ��O�i�H�V�Y�H�Q�ШðV�m�A���ޯ�A���L����@���@�N�ЧA�A
�ä��O�A�i�H�M�w���C�@��H�O���|�������оɧO�H�Z�\�A�N��O�@
�N�оɡA�]�q�`���|���n�۱¡C
TEXT);
    return 1;
}

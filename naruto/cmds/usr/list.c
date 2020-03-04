/* sell.c by -Acme-
*/

inherit F_CLEAN_UP;

private void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object who;
	string msg;

	if( !environment(me) ) return notify_fail("�A�{�b�H�b���̳������D�F�C\n");

    if( arg ) {
		if( objectp(who=present(arg, environment(me))) ) {
			if( !stringp(msg = who->do_list()) )
				return notify_fail("�o�ӤH�L�k list ...\n");
		} else if( !stringp(msg = environment(me)->do_list(arg)) )
				return notify_fail("�o�Ӧa��L�k list , �Y�A�O�Q��H���� list �Х[�WID ...\n");
    } else {
    	if( !stringp(msg = environment(me)->do_list()) )
    		return notify_fail("�o�Ӧa��L�k list , �Y�A�O�Q��H���� list �Х[�WID ...\n");
    }

	me->start_more(msg);
	return 1;
}

int help(object me)
{
  write(@HELP
���O�榡 : list [�Y�H/�s��]

�o���O�i�H�C�X�Y�H�ҥ��b�c�檺���~�C��A�άO�Y�H�i�H�V�m����
��C��A�Y�O�b���E�̥u�� list �Y�i�C�X���E�c�檺���~�C��A��
�O�[�W�s���i�H�˵����~����O�C

�������O�G train, sell, buy
HELP);
    return 1;
}

/* buy.c write by -Acme- */

inherit F_CLEAN_UP;

private void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	int amount, number;
	string from;
	object who;
	
	if( !arg ) return notify_fail("�A�Q�n�R����F��H\n");
	
	if( sscanf(arg, "%d %d from %s", amount, number, from) == 3 ) {
		if( !objectp(who=present(from, environment(me))) )
		    return notify_fail("�A����S���o�ӤH�C\n");
	    if( !who->to_sell(me, number, amount) )
	    	return notify_fail("�o�ӤH���G����o�ӪF��C\n");
	} else if( sscanf(arg, "%d from %s", number, from) == 2 ) {
		if( !objectp(who=present(from, environment(me))) )
		    return notify_fail("�A����S���o�ӤH�C\n");
	    if( !who->to_sell(me, number, 1) )
	    	return notify_fail("�o�ӤH���G����o�ӪF��C\n");
	} else if( sscanf(arg, "%d %d", amount, number) == 2 ) {
		if( !environment(me)->to_sell(me, number, amount) )
			return notify_fail("�o�̦��G���O�ө��C\n");
	} else if( sscanf(arg, "%d", number) == 1 ) {
        if( !environment(me)->to_sell(me, number, 1) )
            return notify_fail("�o�̦��G���O�ө��C\n");
	} else return notify_fail("�A�Q�n�R����F��H\n");
	
	return 1;
}

int help(object me)
{
   write(@HELP
���O�榡: buy [�ƶq] �ӫ~�s�� [from �Y�H]

�o���O�i�H���A�q�ө��R�U�Y��ӫ~�A�]�i�q�Y�H���W�R�ӫ~�A��A
�q�ө��R���~�ɡA���O�榡�����ݭn�[�W from �Y�H�C�ҡG

buy 3                �q�ө��R�U�s����3���ӫ~
buy 2 5              �q�ө��R�U�G�ӽs����5���ӫ~
buy 2 from waiter    �qwater���W�R�U�s����2���ӫ~
buy 10 7 from waiter �qwater���W�R�U�Q�ӽs����7���ӫ~

�������O�G list, sell
HELP);
   return 1;
}
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping score;
	string line;
	int i;

	if(!arg) ob = me;

	else {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("�A�n��ݽ֪����A�S\n");
		if (!wizardp(me) && !ob->accept_info(me, "score") )
			return notify_fail("�u���Ův���ݧO�H�����A�C\n");
	}
	score = ob->query("score");
	if( mapp(score) ) {
		string *c;
		int xp;
        line  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
		line += "�x�H���g��                                                              �x\n";
        line += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
		c = sort_array(keys(score), 1);
		for(i = 0; i < sizeof(c); i++)
			if((xp = (int)ob->query_target_score(c[i]) - score[c[i]]) > 0) {
				line += sprintf("  %11s "HIC"%9d %-11s%s"NOR,
					to_chinese(c[i]),
					score[c[i]],
					"[" + xp + "]",
					i%2 ? "\n" : "" );
			} else {
				line += sprintf("  %11s %9d %-11s%s",
					to_chinese(c[i]),
					score[c[i]],
					"",
					i%2 ? "\n" : "" );
			}
		if( i%2==1 ) line += "\n";
        line += " �w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
	}
	write(line);
	return 1;
}
int help(object me)
{
        write(@HELP
���O�榡 : exp
           exp <��H�W��>(�Ův�M��)

�o�ӫ��O�i�H�d�ߤH�����g��C 
 
�������O�Gscore
HELP
    );
    return 1;
}

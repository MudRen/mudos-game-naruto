/* balance.c by -Acme- */

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object who;
        
    if( arg && !wizardp(me) )
        return notify_fail("�u���Ův�~��d�ߧO�H���s�ڡC\n");

    if( !arg ) who = me;
    else if( arg=="ALL") {
        object* ob;
        string msg ;
        int i;

        ob = sort_array( users(), "sort_user" );

        msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        for(i=0;i<sizeof(ob);i++) {
        msg += sprintf("�x%12s%-12s %40s ��Ȥl %30s �I�Ƣx\n",
                       ob[i]->query("name"),
                       "("+ ob[i]->query("id") + ")",
                        chinese_number(ob[i]->query("bank")),
                        chinese_number(ob[i]->query("exchange")),
                      );

        }
        msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        tell_object(me, msg);
        return 1;
    }
    else {
        if( !who ) who = present(arg, environment(me));
        if( !who ) who = find_living(arg);
        if( !who ) return notify_fail("�S�� " + arg + " �o�ӤH���C\n");
        write("[" + who->name() + "] ");
    }
    tell_object(me, "�A�ثe��" + chinese_number(who->query("bank")) + "��Ȥl���s�ڡC\n");
    tell_object(me, "�A�֦�" + chinese_number(who->query("exchange")) + "�I���ӫ~�I���I�ơC\n");
    return 1;
}

int sort_user(object ob1, object ob2)
{
    return ob2->query("bank")- ob1->query("bank");
}

int help()
{
    write(@TEXT
���O�榡�Rbalance [�Y�H|ALL]

�o�ӫ��O�i�H�d�ߧA�Ȧ�ثe���s�ڡC
TEXT);
    return 1;
}

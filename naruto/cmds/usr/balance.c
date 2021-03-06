/* balance.c by -Acme- */

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object who;
        
    if( arg && !wizardp(me) )
        return notify_fail("只有巫師才能查詢別人的存款。\n");

    if( !arg ) who = me;
    else if( arg=="ALL") {
        object* ob;
        string msg ;
        int i;

        ob = sort_array( users(), "sort_user" );

        msg  = "╭──────────────────────────────────────────────────────╮\n";
        for(i=0;i<sizeof(ob);i++) {
        msg += sprintf("│%12s%-12s %40s 兩銀子 %30s 點數│\n",
                       ob[i]->query("name"),
                       "("+ ob[i]->query("id") + ")",
                        chinese_number(ob[i]->query("bank")),
                        chinese_number(ob[i]->query("exchange")),
                      );

        }
        msg += "╰──────────────────────────────────────────────────────╯\n";
        tell_object(me, msg);
        return 1;
    }
    else {
        if( !who ) who = present(arg, environment(me));
        if( !who ) who = find_living(arg);
        if( !who ) return notify_fail("沒有 " + arg + " 這個人物。\n");
        write("[" + who->name() + "] ");
    }
    tell_object(me, "你目前有" + chinese_number(who->query("bank")) + "兩銀子的存款。\n");
    tell_object(me, "你擁有" + chinese_number(who->query("exchange")) + "點的商品兌換點數。\n");
    return 1;
}

int sort_user(object ob1, object ob2)
{
    return ob2->query("bank")- ob1->query("bank");
}

int help()
{
    write(@TEXT
指令格式﹕balance [某人|ALL]

這個指令可以查詢你銀行目前的存款。
TEXT);
    return 1;
}

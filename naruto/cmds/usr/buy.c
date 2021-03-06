/* buy.c write by -Acme- */

inherit F_CLEAN_UP;

private void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	int amount, number;
	string from;
	object who;
	
	if( !arg ) return notify_fail("你想要買什麼東西？\n");
	
	if( sscanf(arg, "%d %d from %s", amount, number, from) == 3 ) {
		if( !objectp(who=present(from, environment(me))) )
		    return notify_fail("你附近沒有這個人。\n");
	    if( !who->to_sell(me, number, amount) )
	    	return notify_fail("這個人似乎不賣這個東西。\n");
	} else if( sscanf(arg, "%d from %s", number, from) == 2 ) {
		if( !objectp(who=present(from, environment(me))) )
		    return notify_fail("你附近沒有這個人。\n");
	    if( !who->to_sell(me, number, 1) )
	    	return notify_fail("這個人似乎不賣這個東西。\n");
	} else if( sscanf(arg, "%d %d", amount, number) == 2 ) {
		if( !environment(me)->to_sell(me, number, amount) )
			return notify_fail("這裡似乎不是商店。\n");
	} else if( sscanf(arg, "%d", number) == 1 ) {
        if( !environment(me)->to_sell(me, number, 1) )
            return notify_fail("這裡似乎不是商店。\n");
	} else return notify_fail("你想要買什麼東西？\n");
	
	return 1;
}

int help(object me)
{
   write(@HELP
指令格式: buy [數量] 商品編號 [from 某人]

這指令可以讓你從商店買下某件商品，也可從某人身上買商品，當你
從商店買物品時，指令格式中不需要加上 from 某人。例：

buy 3                從商店買下編號為3的商品
buy 2 5              從商店買下二個編號為5的商品
buy 2 from waiter    從water身上買下編號為2的商品
buy 10 7 from waiter 從water身上買下十個編號為7的商品

相關指令： list, sell
HELP);
   return 1;
}
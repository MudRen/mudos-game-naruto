#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

private void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    int value;
    object ob;
    seteuid(geteuid(this_player(1)));

    if( me->is_busy() ) return notify_fail("你現在沒空！\n");

    if( !arg || arg=="" ) return notify_fail("你要貢獻什麼？\n");

    ob = present(arg, me);
    if( !ob ) ob = present(arg, environment(me));
    if( !ob ) return notify_fail("這附近沒有這樣東西...\n");
    if( ob->is_corpse() && ob->query("userp") ) return notify_fail("你不能貢獻玩家的屍體。\n");
    if( ob->is_character() && !ob->is_corpse() ) return notify_fail("你只能貢獻「東西」。\n");
    if( ob->query("no_sac") ) return notify_fail("這樣東西無法貢獻...\n");
    if( ob->query("money_id") ) return notify_fail("這樣東西無法貢獻...\n");
    if( ob->query("no_get") ) return notify_fail("這樣東西無法貢獻...\n");
    if( ob->query("equipped") ) return notify_fail("要貢獻這樣東西，請先卸除裝備...\n");
    if( ob->query("keep_this") ) return notify_fail("這樣東西已經keep，請先解除keep才能貢獻。\n");
    if( (!ob->query("value") || ob->query("value") == 0) && !ob->is_corpse() ) return notify_fail("這東西太破舊了，無法貢獻。\n");

    message_vision(YEL"$N睜開眼睛，嘴裡輕誦流影(Acme)的名號，慢慢地$n"+YEL"被一陣黑煙包住消失了。\n"NOR, me, ob);
 
    destruct(ob);
    if( ob ) {
        write("你無法將這個物件強制摧毀。\n");
        return 1;
    } 

    value = random(10)+1;
    write("你銀行增加了" + chinese_number(value) + "銀兩。\n");
    me->add("bank",value);

    return 1;
}

int help()
{
    write(@TEXT
指令格式：sac <物品>

這個指令讓你將沒有用的東西貢獻給大地，並獲得一些銀兩。

TEXT
    );
    return 1;
}

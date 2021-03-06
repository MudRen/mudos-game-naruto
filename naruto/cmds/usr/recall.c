/* recall.c */

#include <ansi.h>
#include <login.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    int pay = 0;
    if( !objectp(me) ) return 0;

    if( me->is_fighting() )
        return notify_fail("你還在戰鬥中，無法使用 recall 指令。\n");

    if( me->is_busy() ) 
        return notify_fail("你正忙著，無法使用 recall 指令。\n");

    if( environment(me) && environment(me)->query("no_recall") )
        return notify_fail("你所在的地方無法使用 recall 指令。\n");

    if( me->query_temp("no_recall") )
        return notify_fail("你現在無法使用 recall 指令。\n");

	if( me->query_level() <= 20 ) pay = 0;
	else pay = me->query_level() * (me->query_level()/10);

    if( !wizardp(me) && me->query("bank") < pay )
        return notify_fail("你的銀行裡不足 " + pay + " 兩銀子，無法向天神求助。\n");
    me->add("bank", -pay);
    message_vision(HIM"$N閉上眼睛，嘴裡輕誦蔡小林(Jolin)的名號，慢慢地被一陣七彩雲霧包住了。\n"NOR, me);

    me->start_busy(1);

    call_out("do_move", 2, me, arg);

    return 1;
}

int do_move(object me, string arg)
{
    string tmp;
    object room;

    if( arg == "start" ) tmp = START_ROOM;
    else {
    	if( !(tmp = me->query("recoverroom")) ) tmp = START_ROOM;
    }

    if( !objectp(room=load_object(tmp)) ) 
        if( !objectp(room=load_object(START_ROOM)) )
            tell_object(me, "突然時空發生一陣錯亂！你無法移動！\n");

    message_vision(HIG"只見$N"HIG"的身體化成片片雪花，消失在半空了....\n"NOR,me);

    me->move(room);

    message_vision(HIW"一陣清風吹來陣陣白霧，$N的身影漸漸凝結成型﹗\n"NOR,me);

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式﹕ recall [start]

這個指令可以讓你迅速返回重生點。若加參數 start 則會回到巫師神殿。
使用這個指令一次必須貢獻一些銀兩給天神才行。

LV01 ~ LV20    不需要貢獻
LV21 ~         依照公式 LV * (LV/10) 來貢獻銀兩

例：LV30   30*(30/10) = 30*3 = 90(銀兩)
    LV55   55*(55/10) = 55*5 = 275(銀兩)
HELP);
    return 1;
}

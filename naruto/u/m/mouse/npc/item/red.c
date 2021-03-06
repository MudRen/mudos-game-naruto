#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIY"新年"HIR"紅包袋"NOR, ({ "Red Cash Gift", "red", "cash", "gift" }));

    if( !clonep() ) {
        set("base_unit", "份");
        set("base_value", 1);
        set("base_weight", 1);
        set("long", "恭喜發財，紅包拿來，試看看"HIG"(use red)"NOR"手氣如何吧！" );
    }
    setup();
}
int do_use(object me, string arg)
{
    int i;
    if( !objectp(me) ) return 0;
    message_vision("$N"HIW"帶著緊張的心情打開手上的"NOR"$n"HIW"。\n"NOR, me, this_object());

    i = random(4999)+1;
    if( i < 100 ){
        tell_object(me, HIY"新年"HIR"紅包袋"HIW"中居然有 "HIY"500000"HIW" 元支票！真是賺到了！\n"NOR);
        tell_object(me, HIG"(錢已經存在銀行中了。)\n"NOR);
        me->add("bank", 500000);
    } else if( i < 500){
        tell_object(me, HIY"新年"HIR"紅包袋"HIW"中居然有 "HIY"50000"HIW" 元支票！手氣真好！\n"NOR);
        tell_object(me, HIG"(錢已經存在銀行中了。)\n"NOR);
        me->add("bank", 50000);
    } else if( i < 1000){
        tell_object(me, HIY"新年"HIR"紅包袋"HIW"放了 "HIY"5000"HIW" 元支票！\n"NOR);
        tell_object(me, HIG"(錢已經存在銀行中了。)\n"NOR);
        me->add("bank", 5000);
    } else if( i < 2000){
        tell_object(me, HIY"新年"HIR"紅包袋"HIW"裡面只有 "HIY"125"HIW" 元，真是太摳了。\n"NOR);
        tell_object(me, HIG"(錢已經存在銀行中了。)\n"NOR);
        me->add("bank", 125);
    } else {
        message_vision("$n"HIW"裡面的 "HIY"10"HIW" 元硬幣掉了出來...滾到水溝裡去啦。\n"NOR, me, this_object());
    }
    // 個數減少
    destruct(this_object());
    return 1;
}

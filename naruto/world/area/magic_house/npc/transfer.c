#include <ansi.h>
#include <npc.h>

void create()
{
    set_name("傳送師", ({ "transfer" }) );
    set_race("human");
    set_level(20);
    set("nickname",BMAG+HIW"指定傳送"NOR);
    set("gender", "female");
    set("no_fight", 1);
    set("age", 15);
    set("long", "魔術馬戲團的專屬傳送師，通常是在遊客親自上臺的危險表演時事先\n"
                "將遊客傳到安全的地方再傳回原位，不過當事人與觀眾沒人知道就是\n"
                "平常在馬戲團裡沒什麼工作，所以偶爾也會為外人服務。\n"
                "如果有意願傳送到豹人部落，可以向他尋問(say 傳送)\n");

    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "say 想要傳送到豹族部落嗎？問我「傳送」就對了..." :),
    }));
    setup();
}
private void goin(string arg, object me)
{
    if( arg != "" ) {
        if( arg[0] == 'y' || arg[0] == 'Y' ) {
            if( this_player()->query("bank") < 500 ) {
                tell_object(me, HIM"\n傳送師無奈的搖搖手指著右邊的牌子，上面寫著「雙腳萬能」\n"NOR);
                return;
            }
            this_player()->delete_temp("gomagic");
            tell_object(me, HIY"\n(銀行匯了五百兩銀子到傳送師的戶頭中)\n"NOR);
            tell_object(me, HIM"傳送師點點頭用兩手觸碰你，你「咻」地一聲飛到了豹族部落神壇上。\n\n"NOR);
            this_player()->move("/world/area/thorn_pine/altar02.c");
            this_player()->add("bank", -500);
            return;
        } else if( arg[0] == 'N' || arg[0] == 'n' ) {
            tell_object(me, HIW"\n你想了想還是覺得太貴了，決定自己走過去。\n"NOR);
            return;
        }
    }
    tell_object(me, "傳送師說道："HIG"去豹族部落傳送一次要五百兩銀子..."HIW"要去嗎？(Y/n)"NOR);
    input_to("goin", me);
    return;
}
// 當char用say指令時，此mob的回應
int relay_say(object me, string arg)
{
    object test;

    if( arg == "傳送" ) {
        if( !userp(me) ) return 0;
        tell_object(me, "傳送師說道："HIG"去豹族部落傳送一次要五百兩銀子..."HIW"要去嗎？(Y/n)"NOR);
        input_to("goin", me);
        return notify_fail("");
    }
    return 1;
}

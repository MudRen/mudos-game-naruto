#include <npc.h>
#include <ansi.h>

object query_helper()
{
    if( objectp(query("helper")) ) return query("helper");
    else return 0;
}
void create()
{
    set_name("少女", ({ "girl" }) );
    set_race("human");
    set("gender", "female");
    set("age", 15);
    set_level(15);
    set("long", "一位年輕的女性，被綁在木頭上，身上畫滿了奇怪的文字。\n");
    set("title","活祭品");
    set("chat_chance", 5);
    set("chat_msg", ({
        CYN"少女身子微微發抖，害怕的說不出話來。\n"NOR,
    }) );
    setup();
    set_temp("apply/attack", -100);
    set_temp("apply/armor", 50);
}
void relay_say(object ob, string arg)
{
    if( arg == "老張" && !query("helper") ) {
        if( this_player()->query_temp("quest/help_girl") != 1) {
            message_vision(CYN"$N害怕的說不出話來。\n"NOR, this_object());
            return;
        } else
        this_player()->add_temp("quest/help_girl", 1);
        do_chat( ({
            (: command, "wa" :),
            (: command, "say 爸爸沒死！是他要你來救我的嗎？" :),
        }) );
        return;
    }
    if( arg == "是" || arg == "救你" && !query("helper") ) {
        if( this_player()->query_temp("quest/help_girl") != 2) {
            message_vision(CYN"$N害怕的說不出話來。\n"NOR, this_object());
            return;
        }
        this_object()->set("helper", this_player());
        this_player()->delete_temp("quest/help_girl");
        set_name("老張的女兒", ({ "daughter", "_HELP_GIRL_" }) );
        set("title",HIM"滿懷回家的心"NOR);
        set("long", "一位年輕的女性，雖然憔悴臉上卻帶著笑容。\n");
        set("chat_chance", 5);
        set("chat_msg", ({
            CYN"老張的女兒加緊腳步跟上你的行動。\n"NOR,
        }) );
        do_chat( ({
            (: command, "cry" :),
            (: command, "say 太好了！" :),
            (: command, "follow " + this_player()->query("id") :),
            (: command, "guard " + this_player()->query("id") :),
            (: command, "say 麻煩你帶我回去我父親那吧！" :),
        }) );
        return;
    }
    if( arg == "不是" && !query("helper") ) {
        if( this_player()->query_temp("quest/help_girl") < 1) {
            message_vision(CYN"$N害怕的說不出話來。\n"NOR, this_object());
            return;
        }
        this_player()->delete_temp("quest/help_girl");
        do_chat((: command, "say ...." :));
        return;
    }
}
void die()
{
    object helper;
    message_vision(HIR"\n$N失血過多，終於還是逃不過死亡的命運。\n"NOR, this_object(), this_player());
    if( objectp(helper = query_helper()) ) helper->delete_temp("quest/help_girl");
    ::die();
}

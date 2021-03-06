#include <npc.h>
#include <ansi.h>

object query_helper()
{
    if( objectp(query("helper")) ) return query("helper");
    else return 0;
}
void create()
{
    set_name("幼狐熊", ({ "baby fox bear", "bear", "_HELP_BEAR_" }) );
    set_race("beast");
    set_level(5);
    set("long", "幼小的狐熊，看起來很可愛。\n");
    set("title","被抓的");
    set("limbs", ({ "熊頭", "身體", "腹部", "熊腿", "尾巴" }) );
    set("verbs", ({ "bite" }) );
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "say 阿嗚∼阿嗚∼" :),
        CYN"幼狐熊嗚嗚的叫著，希望有人能「搭救」牠。\n"NOR,
    }) );
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "搭救" && !query("helper") )  {
        do_chat( ({ 
            (: command, "lick " + this_player()->query("id") :),
            (: command, "follow " + this_player()->query("id") :),
            (: command, "guard " + this_player()->query("id") :),
        }) );
        this_object()->set("helper", this_player());
        this_player()->add_temp("quest/helpbear", 1);
        return;
    }
}
void die()
{
    object helper;
    message_vision(HIR"\n$N「嗷」了一聲慢慢倒向一旁死去了。"NOR, this_object(), this_player());
    if( objectp(helper = query_helper()) ) helper->delete_temp("quest/helpbear");
    ::die();
}

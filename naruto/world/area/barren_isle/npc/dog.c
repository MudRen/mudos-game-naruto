#include <ansi.h>
#include <npc.h>

void do_check()
{
    object ob, me;
    me = this_object();
    ob = present("_CORSAIR_", environment(me));

    if( !ob ) {
        message_vision("\n$N因為找不到主人，難過的跑了。\n"NOR, me);
        destruct(me);
        return;
    }
}
void create()
{
    set_name("犬", ({ "animal", "_ANIMAL_" }) );
    set_race("beast");
    set_level(20);
    set("long", "猛獸使所養的寵物，看起來威風凜凜。\n");
    set("limbs", ({ "獸頭", "身體", "腹部", "獸腿", "尾巴" }) );
    set("verbs", ({ "bite" }) );
    set("chat_chance", 100);
    set("chat_msg", ({
        (: do_check :),
    }) );
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: command, "dog" :),
    }) );
    setup();
}
void unconcious()
{
    this_object()->die();
    return;
}
void die()
{
    message_vision("\n$N似乎感到害怕，驚慌地跑掉了。\n"NOR, this_object());
    destruct(this_object());
    return;
}

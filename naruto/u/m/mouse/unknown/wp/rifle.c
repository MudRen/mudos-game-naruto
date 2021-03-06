#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;
int i;
int do_fire(object obj);

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void create()
{
    set_name(HIY"來福槍"NOR, ({ "rifle"}));
    set_weight(7000);
    setup_weapon(20, 30, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 2525);
        set("long", "獵人使用的獵槍，裡面似乎還有子彈可以發射(firegun fire mob)。\n" );
    }
    setup();
}
void init()
{
    add_action("do_wield", "wield");
    add_action("do_unwield", "unwield");
    add_action("do_firegun", "firegun");
}
int do_wield(string arg)
{
    if( arg == "rifle as twohanded" ) {
    this_player()->add_temp("quest/rifle", 1);
    }
}
int do_unwield(string arg)
{
    if( arg == "rifle" ) {
    this_player()->delete_temp("quest/rifle");
    }
}
int do_firegun(string arg)
{
    string func,target;
    object ob;

    if ( !arg || sscanf(arg, "%s %s", func, target)!=2 )
           return notify_fail("你想射誰阿？\n");

    if ( !objectp(ob = present(target, environment(this_player()))) )
            return notify_fail("你想射誰阿？\n");

    if ( !ob
    ||      !ob->is_character()
    ||      ob->is_corpse()
    ||      ob==this_player() )
            return notify_fail("你想射誰阿？\n");

    if( func == "fire") {  do_fire(ob); }
    return 1;
}
int do_fire(object ob)
{
    object me;
    int damage;
    me = this_player();
    if( !me->is_fighting() ) {
        write("你沒在戰鬥，不能用槍。\n");
        return 1;
    }
    if( me->query_temp("quest/rifle") < 1) {
        write("你沒拿槍怎麼用。\n");
        return 1;
    }
    if( i < 9) {
        message_vision("$N拿起"HIY"來福槍"NOR"對準$n發射！\n", me, ob);
        i = i+1;
        damage = random(81) + 20;
        if( random(me->query_ability("evade")) - random(ob->query_ability("evade"))) {
            ob->damage_stat("hp", damage, ob);
            message_vision("        $n被子彈打中了！痛的哇哇大叫。("+damage+")"+report_status(ob)+"", me, ob);
            return 1;
        }
        message_vision("        $n早就跑的遠遠的，浪費一顆子彈(0)"+report_status(ob)+"", me, ob);
        return 1;
    }
    message_vision("$N拿起"HIY"來福槍"NOR"按了幾下，才發現子彈已經用光了。\n", me, ob);
    set("long", "獵人使用的獵槍，但子彈已經用光了。");
    set("base_value", 1010);
    return 1;
}

#include <ansi.h>

inherit NPC;

#define LIFE 50000

void create()
{
    set_name(HIK"奴隸"NOR, ({ "slave", "_OBJ_STAKE_" }) );
    set("title", HIW"沙包"NOR);
    set_race("human");
    set("stake_life", LIFE);

    set("long", "滿臉癡呆的奴隸，是香波地群島人口販子....不對！職業介紹所的產\n"
                "物！可以用來當沙包，或是當做替死鬼也可以，想要練功或是被強敵\n"
                "追殺時最好用的產品！"HIW"(沙包，可以[say 回來]讓他回歸身上)\n"NOR);
    setup();

    set_attr("str", 1);
    set_attr("con", 1);
    set_attr("dex", 1);
    set_attr("int", 1);
    delete_stat("hp");

    set("no_combat", 1); // 不能攻擊
    set("no_defend", 1); // 不能防禦
    set("no_evade", 1);  // 不能迴避
}

// 不是主人不能攻擊
int accept_fight(object ob)
{
    if( query("master_name") != ob->query("id") ) {
        message_vision("$N說道："HIG"我不是給$n用的沙包。\n"NOR, this_object(), ob);
        return 0;
    }
    else return 1;
}

varargs int receive_damage(int damage, object from, object attacker)
{
    return damage;
}

int relay_say(object me, string arg)
{
    object scap;

    if( arg == "回來" ) {
        if( query("master_name") != me->query("id") ) {
            message_vision("$N無奈地看著說道："HIG"$n不是我的主人。\n"NOR, this_object(), me);
            return 0;
        } else {
            scap = new("/world/item/scap.c");
            if( sizeof(all_inventory(me)) >= 40 || me->query_encumbrance() >= me->query_ability("carriage") - 1 ) {
                message_vision("$N哭喪著臉說道﹕"HIG"主人身上太重了，我背不動 Ｔ__Ｔ。\n"NOR, this_object(), me);
                return 1;
            }
            if( !scap->move(me) ) {
                tell_object(me, HIY"(因為你身上太重，奴隸便歡天喜地的逃走了)\n"NOR);
                destruct(scap);
                destruct(this_object());
                return 1;
            }
            message_vision("$N"CYN"將裝備收一收回到$n背後了。\n"NOR, this_object(), me);
            destruct(this_object());
        }
        return 1;
    }
}

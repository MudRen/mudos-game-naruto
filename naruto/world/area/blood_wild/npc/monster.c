#include <npc.h>
#include <ansi.h>

int i = random(100);

void create()
{
    if( i == 50 || i == 0 ) {
        set_name(HIY"���]�H"NOR, ({ "golden monster", "monster" }) );
        set_level(60);
        set("set_drop", ({ ([ "type":"obj", "id":28, "amount":5, "p1":100, "p2":100 ]), }) );
    } else if( i > 45 && i < 56) {
        set_name(HIW"���]�H"NOR, ({ "silver monster", "monster" }) );
        set_level(35);
        set("set_drop", ({ ([ "type":"obj", "id":29, "amount":300+random(501), "p1":100, "p2":100 ]), }) );
    } else if( i < 46 ) {
        set_name(RED"�K�]�H"NOR, ({ "iron monster", "monster" }) );
        set_level(15);
        set("set_drop", ({ ([ "type":"obj", "id":124, "amount":1+random(3), "p1":80, "p2":100 ]), }) );
    } else {
        set_name(YEL"���]�H"NOR, ({ "copper monster", "monster" }) );
        set_level(15);
        set("set_drop", ({ ([ "type":"obj", "id":123, "amount":1+random(3), "p1":80, "p2":100 ]), }) );
    }
    set_race("beast");
    set("age", 200+random(10000));
    set("limbs", ({ "�Y��", "�y��", "�w��", "�L��", "�}��", "�ӥ�" }) );
    set("long", "�������۵w�Ҫ��]�H�A�]�����Ū����P�Ӿ֦����P�{�ת��w�ҡC\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :)
    }));
    setup();
    add_temp("apply/hp", query_level()*50);
    do_heal();
}
void die()
{
    object enemy;
    int i;
    enemy = this_object()->last_damage_giver();
    if( !enemy ) {
        ::die();
        return;
    }
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) {
            ::die();
            return;
        } else
        if( environment(enemy) != environment(this_object()) ) {
            ::die();
            return;
        }
    }
    i = query_level()*5 - random(query_level());
    if( enemy->query_point("learn") > 1000000 ) {
        i = i*-2;
        tell_object(enemy,HIR"\n�]������"NOR+this_object()->query("name")+HIR"�A�Q�����F"HIY"["HIK+chinese_number(i)+HIY"]"HIR"�I���I�C\n\n"NOR);
    } else {
        tell_object(enemy,"\n�]������"NOR+this_object()->query("name")+"�A�B�~��o�F"HIM"["HIC+chinese_number(i)+HIM"]"NOR"�I���I�C\n\n"NOR);
    }
    enemy->add_point("learn", i);
    ::die();
    return;
}


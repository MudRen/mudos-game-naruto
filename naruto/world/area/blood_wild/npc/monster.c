#include <npc.h>
#include <ansi.h>

int i = random(100);

void create()
{
    if( i == 50 || i == 0 ) {
        set_name(HIY"金魔人"NOR, ({ "golden monster", "monster" }) );
        set_level(60);
        set("set_drop", ({ ([ "type":"obj", "id":28, "amount":5, "p1":100, "p2":100 ]), }) );
    } else if( i > 45 && i < 56) {
        set_name(HIW"銀魔人"NOR, ({ "silver monster", "monster" }) );
        set_level(35);
        set("set_drop", ({ ([ "type":"obj", "id":29, "amount":300+random(501), "p1":100, "p2":100 ]), }) );
    } else if( i < 46 ) {
        set_name(RED"鐵魔人"NOR, ({ "iron monster", "monster" }) );
        set_level(15);
        set("set_drop", ({ ([ "type":"obj", "id":124, "amount":1+random(3), "p1":80, "p2":100 ]), }) );
    } else {
        set_name(YEL"銅魔人"NOR, ({ "copper monster", "monster" }) );
        set_level(15);
        set("set_drop", ({ ([ "type":"obj", "id":123, "amount":1+random(3), "p1":80, "p2":100 ]), }) );
    }
    set_race("beast");
    set("age", 200+random(10000));
    set("limbs", ({ "頭部", "尖角", "硬甲", "腿甲", "腳部", "肩甲" }) );
    set("long", "全身附著硬甲的魔人，因為等級的不同而擁有不同程度的硬甲。\n");
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
        tell_object(enemy,HIR"\n因為殺死"NOR+this_object()->query("name")+HIR"你被扣除了"HIY"["HIK+chinese_number(i)+HIY"]"HIR"點學點。\n\n"NOR);
    } else {
        tell_object(enemy,"\n因為殺死"NOR+this_object()->query("name")+"你額外獲得了"HIM"["HIC+chinese_number(i)+HIM"]"NOR"點學點。\n\n"NOR);
    }
    enemy->add_point("learn", i);
    ::die();
    return;
}


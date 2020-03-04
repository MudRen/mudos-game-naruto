#include <npc.h>
#include <ansi.h>

void do_fight()
{
    int damage;
    object enemy;
    string msg;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("\n$N"HIK"�i�j�L�ڦR�X�@��"HIM"����r�G"HIK"�I\n"NOR, this_object(), enemy);
    damage = random(11)+10;
    if( !COMBAT_D->isHit(this_object(), enemy) ) {
        message_vision("$n������@���׶}�F�����C\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    enemy->damage_stat("hp", damage, this_object());
    message_vision( sprintf("�u�F��v�a�@�n�A���G�G�k�F$n������I(%d) %s\n\n"NOR, damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    enemy->start_busy(2);
    return;
}
void create()
{
    set_name("�h�A�r��", ({ "marsh fish", "fish" }) );
    set_level(20);
    set_race("beast");
    set("age", 100+random(501));
    set("long", "���������F�_�Ǫ��׽F�A�f���������y�X����G��C\n");
    set("attitude", "aggressive");
    set("chat_chance", 20);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
}

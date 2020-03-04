#include <npc.h>
#include <ansi.h>

void do_fight()
{
    int damage, raiseDamage;
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("\n$N"HIY"���X���l�@�ڴx���V"NOR"$n"HIY"�I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->isHit(this_object(), enemy) ) {
        message_vision("$n���l�ۧC�׶}�F�����C\n\n", this_object(), enemy);
        return;
    }
    raiseDamage = 60;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    if( damage <= 60 ) damage = 40 + random(20);

    // �ˮ`�ާl��
    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
    enemy->damage_stat("hp", damage, this_object());
    message_vision( sprintf("�u�ԡv�a�@�n�A����$n���ѥ�����, �n��S�b��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    return;
}
void create()
{
    set_name("û��", ({ "sin bear", "bear", "_SIN_BEAR_" }) );
    set_race("beast");
    set_level(28+random(3));
    set("age", 10+random(51));
    set("limbs", ({ "���Y", "����", "���}", "�ݤf", "�L��", "���x" }) );
    set("title",HIY"���~"NOR);
    set("long", "�Y�W���F�Ⱖ�Ǩ������j�����A�O�D���M�h���y�M�C\n");
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":23, "amount":1, "p1":50, "p2":100 ]),   // ����
        ([ "type":"food", "id":21, "amount":1, "p1":5, "p2":100 ]),   // ���x
        ([ "type":"eq", "id":65, "amount":1, "p1":5, "p2":100 ]),     // ���j��
    }) );
    setup();
}
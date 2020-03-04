#include <ansi.h>
#include <npc.h>

inherit F_SEASOLDIER;

void do_fight()
{
    int damage, raiseDamage;
    object enemy;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("\n$N�b�۵ۮ��_"HIW"�K��"NOR"�˷�$n�A�u�I�v�a�@�n�g�X�l�u�C\n", this_object(), enemy);
    if( !COMBAT_D->isHit(this_object(), enemy) ) {
        message_vision("���O�l�u�g���F�A�S����$n�C\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    raiseDamage = 50;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/twohanded"));
    add_temp("apply/attack", -raiseDamage);

    // �ˮ`�ާl��
    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
    enemy->damage_stat("hp", damage, this_object());
    message_vision( sprintf("$n�Q�K�u�����F�A�n������F�@�Ƕˮ`(%d) %s\n\n"NOR, damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    return;
}
void create()
{
    set_name("���x�h�L", ({ "soldier" }) );
    set_race("human");
    set_level(25);
    set("title",HIC"�q�k�q"NOR);
    set("gender", "male");
    set("class","soldier_sea");
    set("camp", "police");
    set("age", 10+random(71));
    set("long", "��ۥ����A�˪����x�h�L�A����j��O��ĵ�١C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":30+random(171), "p1":60, "p2":100 ]),  // �Ȥl
        ([ "type":"obj", "id":100, "amount":1, "p1":30, "p2":100 ]),              // �u��
        ([ "type":"wp", "id":56, "amount":1, "p1":1, "p2":100 ]),                 // ���x��K��
        ([ "type":"eq", "id":97, "amount":1, "p1":1, "p2":100 ]),                 // ���x�u�S���m
    }) );
    setup();
    carry_object(_DIR_AREA_"sifa_isle/npc/wp/gun.c")->wield("twohanded");
}
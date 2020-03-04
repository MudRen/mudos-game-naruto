#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

void do_fight()
{
    int damage, raiseDamage, exact, evade;
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
    exact = COMBAT_D->intimidate(this_object(), 1);
    evade = COMBAT_D->wittiness(enemy, 1);

    this_object()->damage_stat("mp", 10, this_object());
    message_vision("\n$N�q�y�����X�@��äl�}�l�j���A�|�P�ǥX�u�����۫�...\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("���O$n���@���b�N���֡A�~�����$N�A$N�]�u�n���_�äl�C\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    raiseDamage = 250;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    if( damage < 50 ) damage = 20 + random(30);

    // �ˮ`�ާl��
    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
    enemy->receive_damage(damage, this_object());
    message_vision( sprintf("����$n���K�b���֤��ɡA���֩��M�@�ӧí��A�@�`�j�w�g���F$n(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    return;
}
void create()
{
    set_name("�����Ԫ�", ({ "ninja" }));
    set_race("human");
    set_level(27);
    set("gender", "male");
    set("nickname",HIB"�U��"NOR);
    set("age", 10+random(51));
    set("camp", "music");
    set("long", "���������U�ԡA���b�o�̹�ܬr�j��P�V�m�C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: command, "say ���I�N�r�j��M���I" :),
        (: command, "say ���������j�D�Y�j�H���w�����ȡI" :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":5, "amount":1, "p1":10, "p2":100 ]),              // �W�L
        ([ "type":"obj", "id":29, "amount":50+random(50), "p1":60, "p2":100 ]),// �Ȥl
        ([ "type":"food", "id":51, "amount":1, "p1":3, "p2":100 ]),            // �N��
        ([ "type":"food", "id":10, "amount":1, "p1":2, "p2":100 ]),            // �b��
        ([ "type":"food", "id":11, "amount":1, "p1":1, "p2":100 ]),            // ���o
        ([ "type":"eq", "id":90, "amount":1, "p1":1, "p2":600 ]),              // �@�B
    }) );
    setup();
    // �W�j
    add_temp("apply/armor", 20);
}

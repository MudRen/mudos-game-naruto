#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

void do_fight()
{
    int damage, raiseDamage, exact, evade;
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
    exact = COMBAT_D->intimidate(this_object(), 1)*1.1;
    evade = COMBAT_D->wittiness(enemy, 1);

    this_object()->damage_stat("mp", 20, this_object());
    message_vision("\n$N"HIY"�o�X�L�L�s�n�A�u���a�����d�g���G����@��Ӻ������_�I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$n���G�S���n�������N��A�u���d�g�S�������F�^�h�C\n\n"NOR, enemy, this_object());
        this_object()->start_busy(2);
    } else {
        raiseDamage = 600;

        add_temp("apply/attack", raiseDamage); 
        damage = COMBAT_D->isDamage(this_object(), enemy, 0);
        add_temp("apply/attack", -raiseDamage);

        if( damage < 200 ) damage = 100 + random(100);

        enemy->receive_damage(damage, this_object());
        message_vision( sprintf("$N�ұ���d���A�����R�E�԰զa�����b$n���W�A���L�ܷ�(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
        this_object()->start_busy(2);
    }
    return;
}
void create()
{
    set_name("�W�O", ({ "god monster pig", "pig" }));
    set_level(50);
    set_race("beast");
    set("limbs", ({ "���Y", "�ާ�", "�޳b", "�ަ�", "�޸}", "�ި{" }) );
    set("long", "�ު��~�A�}�ᦳ��_�A�n���N�����s�C���ӬO���ޤg����C\n");

    set("nickname",HIM"�ު��~"NOR);
    set("set_drop", ({

    }) );
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":58, "amount":1, "p1":5, "p2":100 ]),     // �믫���
        ([ "type":"obj", "id":65, "amount":1, "p1":5, "p2":100 ]),     // ��O���
        ([ "type":"obj", "id":66, "amount":1, "p1":5, "p2":100 ]),     // ���d���
    }) );
    setup();
}
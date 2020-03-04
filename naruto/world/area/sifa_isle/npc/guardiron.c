#include <ansi.h>
#include <npc.h>

inherit F_SEASOLDIER;

void do_fight()
{
    int damage, raiseDamage;
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
    message_vision(CYN"\n$N�N�K��ֳt���ϰ�...�u���K�y�Q��V�Ť�...\n"NOR, this_object(), enemy);
    if( !COMBAT_D->isHit(this_object(), enemy) ) {
        message_vision("$N�ΤO��$n�@���K��A�u���K�y���h�A�b�a�W�{�X�@�Ӥj�}\n\n", this_object(), enemy);
        this_object()->start_busy(3);
        return;
    }
    raiseDamage = 200;
    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/twohanded"));
    add_temp("apply/attack", -raiseDamage);

    if( damage < 100 ) damage = 50 + random(50);

    enemy->damage_stat("hp", damage, this_object());
    message_vision( sprintf("$N�ΤO��$n�@���K��A�u���K�y���h�A����$n�ݤf(%d) %s\n\n"NOR, damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    this_object()->start_busy(1);
    return;
}
void create()
{
    set_name("�u��", ({ "guard" }) );
    set_race("human");
    set_level(30);
    set("title",HIC"�q�k�q"NOR);
    set("nickname",HIK"�K�y����"NOR);
    set("class", "guard_sea");
    set("camp", "police");
    set("age", 10+random(71));
    set("long", "�������Ӫ��h�L�A��W���K���ۤ@����H�٤j���K�y�C\n");
    set("chat_chance", 15);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":100, "amount":1, "p1":60, "p2":100 ]),              // �u��
        ([ "type":"obj", "id":102, "amount":1, "p1":40, "p2":100 ]),              // ��÷
        ([ "type":"wp", "id":61, "amount":1, "p1":1, "p2":400 ]),                 // �K�y����
        ([ "type":"wp", "id":60, "amount":1, "p1":50, "p2":100 ]),                // �K�y
    }) );
    setup();
    carry_object(__DIR__"wp/ball.c")->wield("twohanded");
}
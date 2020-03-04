#include <npc.h>
#include <ansi.h>

void do_fight()
{
    int damage;
    object enemy;
    mapping cnd = ([]);

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // �w�g���r�N����F
    if( enemy->query_condition("scorpion_poison", 1) != 0) return;

    message_vision("\n$N"HIM"�N�������$n�A���M���F�L�Ӭ������@���I\n"NOR, this_object(), enemy);
    if( random(500) < random(300) ) {
        message_vision("���O�ȧ��u�O�뤤�F$N����A�A�èS���˨�$N�C\n\n", enemy, this_object());
        this_object()->start_busy(1);
        return;
    }
    enemy->damage_stat("hp", damage, this_object());
    message_vision("\t$N����@�n�A�Ȭr�C�C���y�i$N���餺�A��$N�h�W�����C\n\n", enemy, this_object());
    enemy->start_busy(1);

    cnd["name"] = MAG+"�Ȭr"+NOR;
    cnd["duration"] = 3;
    cnd["from"] = this_object();

    enemy->set_condition("scorpion_poison", cnd);

    return;
}

void create()
{
    set_name("�r��", ({ "scorpion" }) );
    set_level(30);
    set_race("beast");
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("age", 11+random(21));
    set("limbs", ({ "���Y", "���g", "�ȧ�", "�{�l", "�Ȩ�" }) );
    set("long", "�ͬ��b�F�ަa�����@�r�ͪ��A�{�b���G�Q�F�s�ҹ}�i�C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
       ([ "type":"eq", "id":110, "amount":1, "p1":1, "p2":800 ]),              // �r�����g
        ([ "type":"obj", "id":113, "amount":1+random(2), "p1":30, "p2":100 ]), // �r�Ȧ�M
    }) );
    setup();
    add_temp("apply/hp", 500);
    add_temp("apply/attack", 50);
    // ���վ�L ap, hp, mp ���n do_heal(), �~�������A�ɺ�
    do_heal();
}

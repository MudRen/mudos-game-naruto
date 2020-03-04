#include <npc.h>
#include <ansi.h>

void do_fight()
{
    int exact, evade;
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
    if( enemy->query_condition("firelotus", 1) != 0) return;

    message_vision("\n$NĲ��½��u�F���v�@�n��X�@��"HIM"���⪺���V"NOR"�I\n"NOR, this_object(), enemy);

    exact = COMBAT_D->exact(this_object(), enemy, 1);
    evade = COMBAT_D->exact(enemy, this_object(), 1);

    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("���V�b�����o�X�u�y�v�a�@�n�A�ܦ��Ӥp�ߵ��Q���y�Ĩ��F�C\n\n", enemy, this_object());
        this_object()->start_busy(2);
        return;
    }
    message_vision("���V�u�S�S�S�v�a���b$N���W�Q�X����몺����A$n�ݪ���R���СC\n\n", enemy, this_object());
    enemy->start_busy(1);
    this_object()->start_busy(1);

    cnd["name"] = HIM+"���V"+NOR;
    cnd["duration"] = 3;
    cnd["from"] = this_object();

    enemy->set_condition("firelotus", cnd);
    return;
}

void create()
{
    set_name(HIR"���V����"NOR, ({ "medusa" }) );
    set_level(25);
    set_race("beast");
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("age", 100+random(200));
    set("limbs", ({ "Ĳ��", "ĲŽ", "�Y��", "������", "�n��" }) );
    set("long", "�����o���������A���b�����Pı�D�`�S�O�C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
       ([ "type":"food", "id":65, "amount":1, "p1":1, "p2":10 ]),       // �F��
       ([ "type":"food", "id":74, "amount":1, "p1":1, "p2":15 ]),       // ���x
       ([ "type":"food", "id":66, "amount":1, "p1":1, "p2":20 ]),       // �Q��
    }) );
    setup();
}

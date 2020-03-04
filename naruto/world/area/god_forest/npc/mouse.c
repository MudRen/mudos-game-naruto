#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

void do_fight()
{
    mapping cnd = ([]);
    object enemy;
    int exact, evade;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( enemy->query_condition("firedamage") != 0 ) return;
    exact = COMBAT_D->wittiness(this_object(), 1)*1.5;
    evade = COMBAT_D->intimidate(enemy, 1);

    message_vision("\n$N"HIR"�Pı�ͩR����¯١A������v�ݪ��A�٤��ɼQ�X���V�I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$N��B�F����{�A�`��O�S���������`�̡I\n\n"NOR, enemy, this_object());
    } else {
        cnd["name"] = GRN"�N��"NOR;
        cnd["duration"] = 10;

        this_object()->damage_stat("mp", 20, this_object());
        enemy->set_condition("firedamage", cnd);
        message_vision("���ާֳt�a«�V$N�A�~�@�|��N�N$N�Ҧb����m�N���@���G�ɡC\n\n"NOR, enemy, this_object());
    }
    return;
}
void create()
{
    set_name("����", ({ "god monster mouse", "mouse" }));
    set_level(50);
    set_race("beast");
    set("limbs", ({ "�Y��", "����", "����", "����", "��l", "�|��" }) );
    set("long", "�ͬ��b���s���A���ʤ�A�������@�̡A�Ӧp���A�����Y���C�Υ���\n"
                "��N�i�s���u���J���v\n");

    set("nickname",RED"�����~"NOR);
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
        ([ "type":"food", "id":81, "amount":1, "p1":10, "p2":100 ]),     // ���S�G
        ([ "type":"food", "id":20, "amount":1, "p1":20, "p2":100 ]),     // �j�]�O�Y
        ([ "type":"food", "id":19, "amount":1, "p1":30, "p2":100 ]),     // �]�O�Y
    }) );
    setup();
}
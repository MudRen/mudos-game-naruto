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
    if( enemy->query_condition("vp") != 0 ) return;
    exact = COMBAT_D->intimidate(this_object(), 1)*1.5;
    evade = COMBAT_D->wittiness(enemy, 1);

    message_vision("\n$N"YEL"�S�X���ѤW���y�w�A��F�X�U�ͻH�ֳt��V$n���n�`�I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
       message_vision("���G$N�����F��V�A�����S���I��$n�I\n\n"NOR, enemy, this_object());
    } else {
        cnd["name"] = GRN"���r"NOR;
        cnd["duration"] = 20;

        this_object()->damage_stat("mp", 20, this_object());
        enemy->set_condition("vp", cnd);
        message_vision("$N���[�@�n�G�s�A��ӬO�Q$n�h��F�C\n\n"NOR, enemy, this_object());
    }
    return;
}
void create()
{
    set_name("�ȸ�", ({ "god monster bee", "bee" }));
    set_level(50);
    set_race("beast");
    set("limbs", ({ "���Y", "����", "�Χ�", "����", "ĲŽ", "�{�l" }) );
    set("long", "���N�O�����A���j�p���A�h�H�A���r�A����H�C \n");
    set("nickname",YEL"����"NOR);
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
        ([ "type":"food", "id":79, "amount":1, "p1":10, "p2":100 ]),     // ���P�G
        ([ "type":"food", "id":16, "amount":1, "p1":20, "p2":100 ]),     // �j��O�Y
        ([ "type":"food", "id":15, "amount":1, "p1":30, "p2":100 ]),     // ��O�Y
    }) );
    setup();
}
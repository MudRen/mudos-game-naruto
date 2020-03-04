#include <npc.h>
#include <ansi.h>

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_fight()
{
    int damage;
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
    message_vision("$N"HIY"���X���l�@�ڴx���V"NOR"$n"HIY"�I\n"NOR, this_object(), enemy);
    damage = 20+random(36);
    if( random(enemy->query_ability("evade")) > 100) {
        message_vision("        $n���l�ۧC�׶}�F�����C(0)"+report_status(enemy)+"", this_object(), enemy);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        �u�ԡv�a�@�n�A����$n���ѥ�����, �n��S�b���C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
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

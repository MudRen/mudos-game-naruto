#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

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
    message_vision("$N�µ�$n�g�X�@�⭸�w�I\n"NOR, this_object(), enemy);
    damage = 10+random(51);
    if( random(enemy->query_ability("evade")) > 200) {
        message_vision("        $n�ֳt���q����u�F�}�ӡC(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n�u�P�v���@�n�Q���w�g���C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
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
    set("attitude", "aggressive");
    set("long", "���������U�ԡA���b�o�̹�ܬr�j��P�V�m�C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 40);
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
}

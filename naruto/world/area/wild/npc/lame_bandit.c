#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

void do_fight()
{
    mapping cnd = ([]);

    if( this_object()->query_condition("body_strength_cond") != 0 ) return;

    message_vision(CYN"\n$N�ֳt���L�A�o��M�n�n�Y�I�i������¦�u"HIY"�m"NOR+CYN"�v...\n"NOR, this_object());

    cnd["name"] = HIY"�m"NOR;
    cnd["duration"] = 300;
    cnd["attack"] = 0;
    cnd["armor"] = 50;

    this_object()->damage_stat("mp", 10, this_object());
    this_object()->set_condition("body_strength_cond", cnd);
    message_vision("$N������O���_�ֿn�A�y�L�����F���m�O�C\n\n"NOR, this_object());
    return;
}
void create()
{
    set_name("�_���s", ({ "lame bandit", "bandit" }));
    set_class("middle");
    set_level(30);
    set("camp", "hole_bandit");
    set("long", "�a�F�@���}���j�s�A���ܧV�O���׽m���O����¦�u�|�j��v\n");
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":250+random(100), "p1":50, "p2":100 ]), // �Ȥl
        ([ "type":"obj", "id":22, "amount":1, "p1":5, "p2":100 ]),                // ������
        ([ "type":"wp", "id":16, "amount":1, "p1":1, "p2":1400 ]),                // ����C
        ([ "type":"eq", "id":66, "amount":1, "p1":1, "p2":150 ]),                 // �s�D�c
        ([ "type":"eq", "id":67, "amount":1, "p1":1, "p2":100 ]),                 // �C���@��
    }) );
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();

    // �W�j
    add_temp("apply/attack", 60);
    add_temp("apply/armor", 30);
    add_temp("apply/exact", 10);
    add_temp("apply/evade", 10);
    add_temp("apply/intimidate", 5);
    add_temp("apply/wittiness", 5);
    add_temp("apply/int", 5);
    add_temp("apply/con", 5);
    add_temp("apply/str", 5);
    add_temp("apply/dex", 5);
}

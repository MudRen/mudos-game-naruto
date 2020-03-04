#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

void create()
{
    set_name("�µs", ({ "black bandit", "bandit" }));
    set_class("middle");
    set_level(33);
    set("nickname", HIK"�¥ը�D"NOR);
    set("long", "�Q�¹D�Ҭ����ӨӪ��H���A�]���¹D�̷Q�x�l�@�������y�P�󪺵L�W\n"
                "����A�o�̪��y���Ԫ̥��n�O�̨ΥؼСA�]���ߨ謣��U�ӳo�����C\n");
    set("camp", "hole_bandit");
    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":1, "p1":10, "p2":100 ]),       // ����
        ([ "type":"wp", "id":16, "amount":1, "p1":1, "p2":700 ]),         // ����C
        ([ "type":"wp", "id":70, "amount":1, "p1":1, "p2":1500 ]),        // �s�p�C
        ([ "type":"eq", "id":66, "amount":1, "p1":5, "p2":100 ]),         // �s�D�c
        ([ "type":"eq", "id":67, "amount":1, "p1":1, "p2":100 ]),         // �C���@��
    }) );
    // �H������
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    setup();
    carry_object(_DIR_AREA_"wild/npc/wp/gao_sword.c")->wield("righthand");

    // �W�j
    add_temp("apply/attack", 100);
    add_temp("apply/armor", 60);
    add_temp("apply/exact", 20);
    add_temp("apply/evade", 20);
    add_temp("apply/intimidate", 10);
    add_temp("apply/wittiness", 10);
    add_temp("apply/int", 7);
    add_temp("apply/con", 7);
    add_temp("apply/str", 7);
    add_temp("apply/dex", 7);
}

#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("����", ({ "cow" }) );
    set_race("beast");
    set_level(15);
    set("age", 5 + random(11));
    set("limbs", ({ "���Y", "����", "���Y", "�I��", "����", "�L��" }) );
    set("long", "���`�i�H�������ܡA�����]����@���Y�Y���סA�u�O�@�|��o�C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
        CYN"�����s�D�G�N����N���\n"NOR,
    }));
    set("set_drop", ({
        ([ "type":"food", "id":77, "amount":1, "p1":40, "p2":100 ]),   // ����
    }) );
    setup();
}

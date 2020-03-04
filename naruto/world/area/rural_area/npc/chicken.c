#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("����", ({ "chicken" }) );
    set_race("beast");
    set_level(15);
    set("age", 5 + random(11));
    set("limbs", ({ "���a", "���L", "����", "���L", "����", "���}", "������" }) );
    set("long", "�����U�J�A��i�n�Y�A�ٯ�Y���סA�u�O�@�|��o�C\n");
    set("chat_chance", 15);
    set("chat_msg", ({
        (: random_move :),
        CYN"�����s�D�G�B�B�B��B�I��B�B�B��\n"NOR,
    }));
    set("set_drop", ({
        ([ "type":"food", "id":78, "amount":1, "p1":40, "p2":100 ]),   // ����
    }) );
    setup();
}

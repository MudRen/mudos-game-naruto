#include <npc.h>

inherit F_BANDIT;

void create()
{
    set_name("�K�ұN�x", ({ "iron jiang jun", "iron", "jiang", "jun" }) );
    set("unit", "��");
    set("gender", "male");
    set_level(40);
    set("age", 18+random(60));
    set("long", "���g�ʾԪ��K�ұN�x�A���W���K�Ҥ]�˲��ֲ֡C\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        "�K�ұN�x�ݵۧA���G�Q�n�g�L�o�̡A�N�q�ڪ������L�h\n",
       
    }));

    // �u�ۥX�f
    set("guard_exit", ({ "west" }));

    setup();
}

int do_guard_exit(int x, int y, string exit)
{
    message_vision("$n�N$N�צ�C\n", this_player(), this_object());
    return 1;
}


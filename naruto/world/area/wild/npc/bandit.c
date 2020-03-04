#include <npc.h>

inherit F_BANDIT;

void create()
{
    set_name("�d���j�s", ({ "road rage bandit", "bandit" }) );
    set("unit", "��");
    set("gender", "male");
    set_level(20);
    set("age", 18+random(60));
    set("long", "�@�y�N����L�X�Q�U�@�ˡA�ݰ_�Ӥ��n�S�C\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        "�d���j�s�������u�A�I�v�a�@�n�����Y�n�ۧA�r�@...\n",
        "�d���j�s�u��v�a�@�n...\n",
    }));

    // �u�ۥX�f
    set("guard_exit", ({ "east", "west" }));

    setup();
}

int do_guard_exit(int x, int y, string exit)
{
    message_vision("$n�N$N�צ�C\n", this_player(), this_object());
    return 1;
}
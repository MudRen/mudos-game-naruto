#include <npc.h>

void create()
{
    set_name("�b�b", ({ "pig" }) );
    set_race("beast");
    set_level(1);

    set("long", "����Ҿi���p�ޡC");

    set("limbs", ({ "���Y", "����", "�޸�", "�޻L", "�ޤ�" }) );
    set("verbs", ({ "bite" }) );

    // �H������
    set("chat_chance", 1);
    set("chat_msg", ({
        (: random_move :),
    }));

    setup();
    
    // �d�z
        set_temp("apply/attack", -10);
        set_temp("apply/defend", -10);
}


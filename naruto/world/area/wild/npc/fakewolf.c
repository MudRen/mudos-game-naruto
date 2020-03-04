#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIW"�ܵۦϥ֪��T"NOR, ({ "fake wolf", "wolf" }) );
    set_race("beast");
    set_level(30);

    set("long", "�@�������ܳ��I���T�A�٩ܵۦϥַQé�V�L�h�C\n");

    set("limbs", ({ "�T�Y", "����", "����", "�T�L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    // �u�ۥX�f
    set("guard_exit", ({ "west", "east", "south" }));

    set("set_drop", ({
        ([ "type":"food", "id":32, "amount":1, "p1":80, "p2":100 ]),   // �T��
        ([ "type":"food", "id":33, "amount":1, "p1":80, "p2":100 ]),   // �T��
        ([ "type":"eq", "id":57, "amount":1, "p1":20, "p2":100 ]),   // �T�}
        ([ "type":"eq", "id":58, "amount":1, "p1":18, "p2":100 ]),   // �T��
        ([ "type":"eq", "id":59, "amount":1, "p1":20, "p2":100 ]),   // �T�}
        ([ "type":"eq", "id":60, "amount":1, "p1":20, "p2":100 ]),   // �T�Y
        ([ "type":"eq", "id":61, "amount":1, "p1":25, "p2":100 ]),  // �T��
        ([ "type":"wp", "id":13, "amount":1, "p1":60, "p2":100 ]),  // �T��
    }) );

    setup();
}

int do_guard_exit(int x, int y, string exit)
{
    message_vision("$n�N$N�צ�C\n", this_player(), this_object());
    return 1;
}
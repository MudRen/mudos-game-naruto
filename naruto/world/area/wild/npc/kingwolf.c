#include <npc.h>

void create()
{
    set_name("�T��", ({ "king of wolf", "wolf" }) );
    set_race("beast");
    set_level(25);

    set("long", "�s�T�̪��T���A�ݰ_�ӫܱj���A���G���Ӧn�S�C\n");

    set("limbs", ({ "�T�Y", "����", "����", "�T�L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"food", "id":32, "amount":1, "p1":80, "p2":100 ]),   // �T��
        ([ "type":"food", "id":33, "amount":1, "p1":80, "p2":100 ]),   // �T��
        ([ "type":"eq", "id":57, "amount":1, "p1":20, "p2":100 ]),   // �T�}
        ([ "type":"eq", "id":58, "amount":1, "p1":18, "p2":100 ]),   // �T��
        ([ "type":"eq", "id":59, "amount":1, "p1":20, "p2":100 ]),   // �T�}
        ([ "type":"eq", "id":60, "amount":1, "p1":20, "p2":100 ]),   // �T�Y
        ([ "type":"eq", "id":61, "amount":1, "p1":25, "p2":100 ]),   // �T��
    }) );

    setup();

    carry_object(__DIR__"wp/wolf_claw.c")->wield("righthand");
    carry_object(__DIR__"wp/wolf_claw.c")->wield("lefthand");
}
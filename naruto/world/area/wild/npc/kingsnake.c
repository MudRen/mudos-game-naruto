#include <npc.h>

void create()
{
    set_name("�j�D��", ({ "the king of snake", "snake" }) );
    set_race("beast");
    set_level(22);

    set("long", "�@���D�������A�ݰ_�ӴN�O���n�S�C\n");

    set("limbs", ({ "�D�Y", "�D��", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"food", "id":29, "amount":1, "p1":35, "p2":100 ]),   // �D�J
        ([ "type":"food", "id":30, "amount":1, "p1":25, "p2":100 ]),   // �D�x
        ([ "type":"obj", "id":24, "amount":1, "p1":25, "p2":100 ]),   // �D��
    }) );

    setup();

    if( random(100) > 70 ) carry_object(__DIR__"wp/snake_tooth.c")->wield("righthand");
}

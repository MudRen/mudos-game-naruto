#include <npc.h>

void create()
{
    set_name("�H��", ({ "monther" }) );
    set_race("beast");
    set_level(8);

    set("long", "�����n�n�����G��A���o�X���ߪ�����C\n");

    set("limbs", ({ "�G���Y", "�G�ᨭ", "�G���", "�G�Ჴ" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
    //  ([ "type":"food", "id":??, "amount":1, "p1":40, "p2":100 ]),   // �G��
    //  ([ "type":"eq", "id":??, "amount":1, "p1":10, "p2":100 ]),     // �G��U
    }) );
    setup();
}

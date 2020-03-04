#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("���U", ({ "big monkey", "monkey" }));
    set_race("beast");
    set_level(15);
    set("age", 20+random(60));
    set("long", "��@��U�l�ٰ�����Y�����j�U�l�C\n");
    set("limbs", ({ "�U�Y", "����", "�{�l", "�U�u", "����", "�U�I", "����" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("set_drop", ({
        ([ "type":"obj", "id":37, "amount":1+random(2), "p1":100, "p2":100 ]),  // �U��
        ([ "type":"obj", "id":38, "amount":1+random(11), "p1":80, "p2":100 ]),  // �U��
        ([ "type":"eq", "id":73, "amount":1, "p1":60, "p2":100 ]),              // �U��
        ([ "type":"food", "id":43, "amount":1+random(1), "p1":50, "p2":100 ]),  // �U�x
        ([ "type":"food", "id":42, "amount":1, "p1":20, "p2":100 ]),            // �U��
        ([ "type":"eq", "id":72, "amount":1, "p1":5, "p2":100 ]),               // �U�u
    }) );
    setup();
    // �[�j
    set_temp("apply/armor", 4);            // ���m�O�q
    set_temp("apply/attack", 20);         // �����O�q
    set_temp("apply/intimidate", 20);     // ������O
}

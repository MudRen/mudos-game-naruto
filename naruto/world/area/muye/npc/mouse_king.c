#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIK"����"NOR, ({ "the king of mouse", "mouse", "king" }) );
    set_race("beast");
    set_level(21);
    set("title", "�a�ѹ�");
    set("long", "�@��ż���������ܥ��j�ѹ��A�ݰ_�ӻP�O���ѹ����P�C\n");
    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("set_drop", ({
        ([ "type":"food", "id":35, "amount":1, "p1":80, "p2":100 ]),   // ����
        ([ "type":"food", "id":36, "amount":1, "p1":80, "p2":100 ]),   // ���}
        ([ "type":"food", "id":37, "amount":1, "p1":80, "p2":100 ]),   // ����
        ([ "type":"eq", "id":53, "amount":1, "p1":80, "p2":100 ]),     // ���Y
        ([ "type":"eq", "id":54, "amount":1, "p1":3, "p2":100 ]),      // �j�ɤ�
    }) );
    setup();
    add_temp("apply/attack", 20);
    set_skill("combat", 110);
    set_skill("dodge", 110);
    set_skill("parry", 110);
    set_skill("savage hit", 110);
    set_skill("heavy hit", 110);
    set_skill("continual hit", 110);
}

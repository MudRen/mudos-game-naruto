#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIK"���ܹ���"NOR, ({ "the king of mouse", "mouse", "king" }) );
    set_race("beast");
    set_level(70);

    set("title", "�G�������a�ѹ�");
    set("long", "�@��ż���������ܥ��j�ѹ��A�ݰ_�ӻP�O���ѹ����P�C\n");

    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"obj", "id":12, "amount":1, "p1":80, "p2":100 ]),   // ����
        ([ "type":"obj", "id":13, "amount":1, "p1":80, "p2":100 ]),   // ���}
        ([ "type":"obj", "id":14, "amount":1, "p1":80, "p2":100 ]),   // ����
        ([ "type":"eq", "id":53, "amount":1, "p1":80, "p2":100 ]),   // ���Y
        ([ "type":"eq", "id":54, "amount":1, "p1":3, "p2":100 ]),   // �j�ɤ�
    }) );

    setup();

    set_skill("combat", 200);
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("savage hit", 200);
    set_skill("heavy hit", 200);
    set_skill("continual hit", 200);
    set_temp("apply/attack", 20);
}



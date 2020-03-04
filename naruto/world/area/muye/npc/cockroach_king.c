#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(YEL"����"NOR, ({ "the king of cockroach", "cockroach", "king" }) );
    set_race("beast");
    set_level(20);
    set("title", "�a����");
    set("long", "�@�����ߪ����ܥ��j�����A�ݰ_�ӻP�O���������P�C\n");
    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("set_drop", ({
        ([ "type":"obj", "id":25, "amount":1, "p1":80, "p2":100 ]),   // ����Ĳ��
        ([ "type":"food", "id":34, "amount":1, "p1":60, "p2":100 ]),  // �����Z
        ([ "type":"obj", "id":26, "amount":1, "p1":80, "p2":100 ]),   // �����}
        ([ "type":"eq", "id":47, "amount":1, "p1":3, "p2":100 ]),     // ����
    }) );
    setup();
    add_temp("apply/attack", 20);
    set_skill("combat", 100);
    set_skill("dodge", 100);
    set_skill("parry", 100);
    set_skill("savage hit", 100);
    set_skill("heavy hit", 100);
    set_skill("continual hit", 100);
}

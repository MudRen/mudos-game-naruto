#include <npc.h>
#include <ansi.h>

void create()
{
    set_name( HIK"���ܬr��" NOR, ({ "mutation spider", "spider" }) );
    set_race("beast");
    set_level(22);

    set("long", "�@�����������ܼ@�r�j��A�����D�`���ߡA�ٵo�X�D�`���ߪ����D�A���H�ݤF�u�Q�@�áC\n");
    set("title","���v�_��");

    set("limbs", ({ "���Y", "����", "����", "��L" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":2, "p1":80, "p2":100 ]),   // �j��L
        ([ "type":"obj", "id":53, "amount":1, "p1":80, "p2":100 ]),   // �j�ﲴ��
        ([ "type":"wp", "id":24, "amount":1, "p1":1, "p2":100 ]),     // �j�j��L
        ([ "type":"eq", "id":80, "amount":1, "p1":1, "p2":650 ]),     // �����M
        ([ "type":"obj", "id":54, "amount":1, "p1":2, "p2":100 ]),    // �r�G
        ([ "type":"obj", "id":55, "amount":1, "p1":1, "p2":300 ]),    // �j��G�U
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

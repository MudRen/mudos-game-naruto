#include <npc.h>
#include <ansi.h>

void create()
{
    set_name( HIK"���ܼ@�r�j��" NOR, ({ "mutation spider", "spider" }) );
    set_race("beast");
    set_level(24);

    set("long", "�@�����������ܼ@�r�j��A�����D�`���ߡA�ٵo�X�D�`���ߪ����D�A���H�ݤF�u�Q�@�áC\n");
    set("title","���v�_��");

    set("limbs", ({ "���Y", "����", "����", "��L" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":2, "p1":80, "p2":100 ]),   // �j��L
        ([ "type":"obj", "id":53, "amount":1, "p1":80, "p2":100 ]),   // �j�ﲴ��
        ([ "type":"wp", "id":24, "amount":1, "p1":3, "p2":100 ]),     // �j�j��L
        ([ "type":"eq", "id":80, "amount":1, "p1":1, "p2":500 ]),     // �����M
        ([ "type":"obj", "id":54, "amount":1, "p1":3, "p2":100 ]),    // �r�G
        ([ "type":"obj", "id":55, "amount":1, "p1":1, "p2":300 ]),    // �j��G�U
        ([ "type":"food", "id":15, "amount":1, "p1":5, "p2":100 ]),   // ��O�Y
    }) );
    setup();
    add_temp("apply/attack", 20);
    set_skill("combat", 116);
    set_skill("dodge", 116);
    set_skill("parry", 116);
    set_skill("savage hit", 116);
    set_skill("heavy hit", 116);
    set_skill("continual hit", 116);
}

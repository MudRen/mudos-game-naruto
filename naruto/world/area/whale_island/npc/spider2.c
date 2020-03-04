#include <npc.h>
#include <ansi.h>

void create()
{
    set_name( HIK"�j���r��" NOR, ({ "big spider", "spider" }) );
    set_race("beast");
    set_level(15);

    set("long", "�@���j�����@�r�j��A��A����x�i�}�٭n�j�A�����D�`���ߡA���H�ݤF�u�Q�@�áC\n");
    set("title","���v�_��");

    set("limbs", ({ "���Y", "����", "����", "��L" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":1, "p1":80, "p2":100 ]),   // �j��L
        ([ "type":"obj", "id":53, "amount":1, "p1":50, "p2":100 ]),   // �j�ﲴ��
        ([ "type":"wp", "id":24, "amount":1, "p1":1, "p2":200 ]),     // �j�j��L
    }) );
    setup();
    add_temp("apply/attack", 20);
}

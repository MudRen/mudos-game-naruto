#include <npc.h>
#include <ansi.h>

void create()
{
    set_name( HIK"�p�r��" NOR, ({ "spider", "spider" }) );
    set_race("beast");
    set_level(10);

    set("long", "�@���@�r���j��A�����D�`���ߡA���H�ݤF�u�Q�@�áC\n");
    set("title","���v�_��");

    set("limbs", ({ "���Y", "����", "����", "��L" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":1, "p1":80, "p2":100 ]),   // �j��L
        ([ "type":"obj", "id":53, "amount":1, "p1":50, "p2":100 ]),   // �j�ﲴ��
    }) );

    setup();
    add_temp("apply/attack", 10);
}


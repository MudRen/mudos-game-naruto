#include <npc.h>
#include <ansi.h>

void create()
{
    set_name( HIK"�����r��" NOR, ({ "hug spider", "spider" }) );
    set_race("beast");
    set_level(20);

    set("long", "�@���������@�r�j��A�X�G�֭n��@���Ѫ�@�ˤj���F�A�����D�`���ߡA���H�ݤF�u�Q�@�áC\n");
    set("title","���v�_��");

    set("limbs", ({ "���Y", "����", "����", "��L" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":2, "p1":80, "p2":100 ]),   // �j��L
        ([ "type":"obj", "id":53, "amount":1, "p1":80, "p2":100 ]),   // �j�ﲴ��
        ([ "type":"wp", "id":24, "amount":1, "p1":1, "p2":150 ]),     // �j�j��L
        ([ "type":"eq", "id":80, "amount":1, "p1":1, "p2":800 ]),     // �����M
        ([ "type":"obj", "id":54, "amount":1, "p1":1, "p2":100 ]),    // �r�G
    }) );
    setup();
    add_temp("apply/attack", 20);
}

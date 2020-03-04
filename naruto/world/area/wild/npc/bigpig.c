#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIK"�j�½�"NOR, ({ "big black pig", "pig" }) );
    set_race("beast");
    set_level(12);

    set("long", "�@���δ������j�½ޡA�ݰ_�ӫ­������C\n");

    set("limbs", ({ "���Y", "����", "����", "�޻L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"food", "id":31, "amount":1, "p1":80, "p2":100 ]),   // �޸z
        ([ "type":"eq", "id":55, "amount":1, "p1":60, "p2":100 ]),   // �½ޥ�
        ([ "type":"eq", "id":56, "amount":1, "p1":50, "p2":100 ]),   // �½��Y
    }) );

    setup();
}
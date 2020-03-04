#include <ansi.h>
#include <npc.h>

void create()
{
    set_name(HIK"���Y�j��"NOR, ({ "mouse spider", "spider", "mouse" }) );
    set_race("beast");
    set("title","���v�_��");
    set_level(25);

    set("long", "�@�����ܪ����ߤj�j��A�Q������ۤ@�Ӧѹ����Y�A����o�O�K���}���j��C\n");

    set("limbs", ({ "���Y", "����", "����", "��L" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":2, "p1":80, "p2":100 ]),     // �j��L
        ([ "type":"obj", "id":54, "amount":1, "p1":5, "p2":100 ]),      // �r�G
        ([ "type":"obj", "id":55, "amount":1, "p1":1, "p2":200 ]),      // �j��G�U
        ([ "type":"food", "id":19, "amount":1, "p1":1, "p2":100 ]),     // �d�J�ԤY
        ([ "type":"eq", "id":81, "amount":1, "p1":1, "p2":500 ]),       // �L�_����
        ([ "type":"food", "id":17, "amount":1, "p1":1, "p2":100 ]),     // ��O�Y
    }) );
    setup();
    add_temp("apply/attack", 30);
    set_skill("combat", 120);
    set_skill("dodge", 120);
    set_skill("parry", 120);
    set_skill("savage hit", 120);
    set_skill("heavy hit", 120);
    set_skill("continual hit", 120);
}

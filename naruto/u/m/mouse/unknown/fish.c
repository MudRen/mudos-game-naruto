#include <npc.h>

void create()
{
    set_name("�h�A����", ({ "fish" }) );
    set_race("beast");
    set_level(30);

    set("long", "���j���h�A���ǡA�j�j���O�q�N��T�ӤH�]�����_�ӡC\n");

    set("limbs", ({ "���Y", "����", "����", "����", "���_" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
    //  ([ "type":"food", "id":??, "amount":1, "p1":40, "p2":100 ]),   // ����
    //  ([ "type":"food", "id":??, "amount":1, "p1":30, "p2":100 ]),   // ����
    //  ([ "type":"food", "id":??, "amount":1, "p1":20, "p2":100 ]),   // ���l
    //  ([ "type":"food", "id":??, "amount":1, "p1":10, "p2":100 ]),   // ���뤧��
    }) );
    setup();
}

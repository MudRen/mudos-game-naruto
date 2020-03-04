#include <npc.h>

void create()
{
    set_name("�p�ޥJ", ({ "baby pig", "pig" }) );
    set_race("beast");
    set_level(1);

    set("long", "�@���X�ͤ��L�X�Ӥ몺�p�ޥJ�A�ݰ_�ӫܥi�R�C\n");

    set("limbs", ({ "���Y", "����", "����", "�޻L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"food", "id":31, "amount":1, "p1":80, "p2":100 ]),   // �޸z
        ([ "type":"eq", "id":55, "amount":1, "p1":30, "p2":100 ]),   // �½ޥ�
        ([ "type":"eq", "id":56, "amount":1, "p1":20, "p2":100 ]),   // �½��Y
    }) );

    setup();
}
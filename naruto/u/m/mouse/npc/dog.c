// write by -Mouse-

#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("�ƪ�", ({ "dog" }));
    set_race("beast");
    set_level(5);
    set("age", 6+random(10));
    set("long", "�o�F�g���f�������A�L�������y�ۤf���C\n");
    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) ); //��������
    set("verbs", ({ "bite" }) );                                 //�����覡
    // �]�w���������c�G (���l/����) �O�������v
    // ({ ([ "type":���O, "id":�s��, "amount":�ƶq, "p1":���l, "p2":���� ]),
    //    ([ ... ]), ([ ... ]), ... })
    set("set_drop", ({
        ([ "type":"eq", "id":5, "amount":1, "p1":20, "p2":100 ]),     // ÷�l
    }) );
    set("attitude", "aggressive");         // �D�ʧ���
    setup();

    // �d�z
    set_attr("str", 15);
    set_attr("con", 10);
    set_attr("dex", 10);
    set_attr("int", 10);
    set_temp("apply/attack", -5);         // �����O�q
    set_temp("apply/defend", -5);         // ���m�O�q
    set_temp("apply/exact", -5);          // �R���v
    set_temp("apply/evade", -5);          // �j�ײv
    set_temp("apply/intimidate", -5);     // ������O
    set_temp("apply/wittiness", -5);      // ���m��O
}

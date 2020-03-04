#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIR"�U"HIY"��"NOR, ({ "monkey king", "monkey", "king" }));
    set_race("beast");
    set_level(25);
    set("age", 150);
    set("title", "�j����");
    set("long", "�髬�����V�V�맧�Ӫ��j�U�l�A��W���˲����O�e�������̪��ҩ��C\n");
    set("limbs", ({ "�U�Y", "����", "�{�l", "�U�u", "����", "�U�I", "����" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("set_drop", ({
        ([ "type":"eq", "id":73, "amount":1, "p1":90, "p2":100 ]),              // �U��
        ([ "type":"food", "id":43, "amount":1+random(1), "p1":80, "p2":100 ]),  // �U�x
        ([ "type":"food", "id":42, "amount":1, "p1":50, "p2":100 ]),            // �U��
        ([ "type":"eq", "id":72, "amount":1, "p1":30, "p2":100 ]),              // �U�u
        ([ "type":"eq", "id":69, "amount":1, "p1":10, "p2":100 ]),              // �����u
    }) );
    setup();
    // �[�j
    set_attr("str", 3);
    set_skill("combat", 100);             // �氫
    set_attr("str", 48);                   // �]�w�O�q
    set_skill("parry", 100);              // ���
    set_skill("savage hit", 100);         // ����
    set_skill("heavy hit", 100);          // ����
    set_skill("continual hit", 80);       // �s��
    set_temp("apply/armor", 2);           // ���m�O�q
    set_temp("apply/attack", 20);         // �����O�q
    set_temp("apply/defend", 20);         // ���m�O�q
    set_temp("apply/exact", 10);          // �R���v
    set_temp("apply/intimidate", 10);     // ������O
    set_temp("apply/wittiness", 10);      // ���m��O
    set_stat_current("hp", 1500);         // ��O
    set_stat_maximum("hp", 1500);         // �̤j��
}


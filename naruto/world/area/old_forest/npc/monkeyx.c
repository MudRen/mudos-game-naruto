#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(YEL"�U��"NOR, ({ "monkey king", "monkey", "king" }));
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
    add_temp("apply/hp", 500);
    add_temp("apply/armor", 100);
    add_temp("apply/attack", 100);
    add_temp("apply/intimidate", 20);

    // ���վ�L ap, hp, mp ���n do_heal(), �~�������A�ɺ�
    do_heal();
}

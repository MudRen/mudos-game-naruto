#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

void create()
{
    set_name("�g�ۮg��", ({ "aborigines shooter", "shooter" }));
    set_race("human");
    set("gender", "female");
    set("age", 10+random(40));
    set_level(10);
    set("long", "�g�۪��O�þԤh�A����}�b�X�v�~�H�i�J�C\n");
    set("attitude", "aggressive");
    set("set_drop", ({
        ([ "type":"food", "id":40, "amount":1+random(5), "p1":50, "p2":100 ]),  // ���G
        ([ "type":"food", "id":38, "amount":1+random(2), "p1":30, "p2":100 ]),  // ��G
        ([ "type":"food", "id":39, "amount":1+random(1), "p1":15, "p2":100 ]),  // ���G
        ([ "type":"eq", "id":71, "amount":1, "p1":10, "p2":100 ]),              // ��
        ([ "type":"wp", "id":19, "amount":1, "p1":5, "p2":100 ]),               // �}
        ([ "type":"wp", "id":18, "amount":1, "p1":5, "p2":100 ]),               // �b
    }) );
    setup();
    // �W�j
    set_temp("apply/attack", 255);           // �����O�q
    set_temp("apply/armor", 50);            // ���m�O�q
    set_temp("apply/exact", 60);            // �R���v
    set_temp("apply/evade", 10);            // �j�ײv
    set_temp("apply/armor", 51);            // ���m�O�q
    set_skill("combat", 50);             // �氫
    set_skill("dodge", 50);              // �{��
    set_skill("continual hit", 50);      // �s��
    set_stat_current("hp", 700);         // ��O
    set_stat_maximum("hp", 700);         // �̤j��
}

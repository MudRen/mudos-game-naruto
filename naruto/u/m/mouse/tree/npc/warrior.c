#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

void create()
{
    set_name("�g�۾Ԥh", ({ "aborigines warrior", "warrior" }));
    set_race("human");
    set("gender", "male");
    set("age", 10+random(50));
    set_level(10);
    set("long", "�g�۪��O�þԤh�A�����j�X�v�~�H�i�J�C\n");
    set("attitude", "aggressive");
    set("set_drop", ({
        ([ "type":"food", "id":40, "amount":1+random(5), "p1":50, "p2":100 ]),  // ���G
        ([ "type":"food", "id":38, "amount":1+random(2), "p1":30, "p2":100 ]),  // ��G
        ([ "type":"food", "id":39, "amount":1+random(1), "p1":15, "p2":100 ]),  // ���G
        ([ "type":"food", "id":41, "amount":1, "p1":5, "p2":100 ]),             // ���G��
        ([ "type":"eq", "id":71, "amount":1, "p1":10, "p2":100 ]),              // ��
        ([ "type":"wp", "id":20, "amount":1, "p1":1, "p2":200 ]),               // ��j
    }) );
    setup();
    // �W�j
    set_temp("apply/attack", 240);          // �����O�q
    set_temp("apply/armor", 30);            // ���m�O�q
    set_attr("str", 32);
    set_attr("dex", 31);
    set_temp("apply/exact", 50);            // �R���v
    set_temp("apply/armor", 31);            // ���m�O�q
    set_temp("apply/intimidate", 10);       // ������O
    set_temp("apply/wittiness", 10);        // ���m��O
    set_temp("apply/intimidate", 20);       // ������O
    set_skill("dodge", 50);              // �{��
    set_skill("savage hit", 50);         // ����
    set_stat_current("hp", 750);         // ��O
    set_stat_maximum("hp", 750);         // �̤j��

}


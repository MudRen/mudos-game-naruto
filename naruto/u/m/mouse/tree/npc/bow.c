#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

void create()
{
    set_name("�g�ۮg��", ({ "aborigines shooter", "shooter" }));
    set_race("human");
    set("gender", "female");
    set("age", 10+random(40));
    set_level(26);
    set("long", "�g�۪��O�þԤh�A����}�b�X�v�~�H�i�J�C\n");
    set("attitude", "aggressive");
    set("set_drop", ({
        ([ "type":"food", "id":40, "amount":1+random(5), "p1":50, "p2":100 ]),  // ���G
        ([ "type":"food", "id":38, "amount":1+random(2), "p1":30, "p2":100 ]),  // ��G
        ([ "type":"food", "id":39, "amount":1+random(1), "p1":20, "p2":100 ]),  // ���G
        ([ "type":"eq", "id":71, "amount":1, "p1":30, "p2":100 ]),              // ��
        ([ "type":"wp", "id":19, "amount":1, "p1":10, "p2":100 ]),              // �}
        ([ "type":"wp", "id":18, "amount":1, "p1":10, "p2":100 ]),              // �b
    }) );
    setup();
    // ��z�ӱ� �{��, �W�[�j�q����, �W�[���m, �W�j��O   �N�O�֫p���h���|�{.
    set_attr("dex", 25);
    set_skill("dodge", 35);              // �{��
    set_temp("apply/attack", 120);           // �����O�q
    set_temp("apply/armor", 50);            // ���m�O�q
    set_stat_current("hp", 1400);
    set_stat_maximum("hp", 1400);
}

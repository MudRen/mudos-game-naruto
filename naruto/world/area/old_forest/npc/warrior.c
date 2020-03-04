#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

void create()
{
    set_name("�g�۾Ԥh", ({ "aborigines warrior", "warrior" }));
    set_race("human");
    set("gender", "male");
    set("age", 10+random(50));
    set_level(26);
    set("long", "�g�۪��O�þԤh�A�����j�X�v�~�H�i�J�C\n");
    set("attitude", "aggressive");
    set("set_drop", ({
        ([ "type":"food", "id":40, "amount":1+random(5), "p1":50, "p2":100 ]),  // ���G
        ([ "type":"food", "id":38, "amount":1+random(2), "p1":30, "p2":100 ]),  // ��G
        ([ "type":"food", "id":39, "amount":1+random(1), "p1":20, "p2":100 ]),  // ���G
        ([ "type":"food", "id":41, "amount":1, "p1":10, "p2":100 ]),            // ���G��
        ([ "type":"eq", "id":71, "amount":1, "p1":30, "p2":100 ]),              // ��
        ([ "type":"wp", "id":20, "amount":1, "p1":5, "p2":200 ]),               // ��j
    }) );
    setup();

    // ��z�{��, �W�[�����B���m, �W�j��O  �N�O�֫p���h���|�{.
    delete_skill("dodge");
    add_temp("apply/hp", 1500);
    add_temp("apply/armor", 40);
    add_temp("apply/attack", 60);
    add_temp("apply/intimidate", 20);
    
    // ���վ�L ap, hp, mp ���n do_heal(), �~�������A�ɺ�
    do_heal();
}

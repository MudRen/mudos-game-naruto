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
        ([ "type":"food", "id":38, "amount":1+random(2), "p1":20, "p2":100 ]),  // ��G
        ([ "type":"food", "id":39, "amount":1+random(1), "p1":30, "p2":100 ]),  // ���G
        ([ "type":"food", "id":41, "amount":1, "p1":10, "p2":100 ]),            // ���G��
        ([ "type":"eq", "id":71, "amount":1, "p1":30, "p2":100 ]),              // ��
        ([ "type":"wp", "id":19, "amount":1, "p1":10, "p2":100 ]),              // �}
        ([ "type":"wp", "id":18, "amount":1, "p1":10, "p2":100 ]),              // �b
    }) );
    setup();

    // ����`���{�����g�ۡA���٬O�֦����j����O�M�ֳ\���ʧ�����O
    set_skill("dodge", 140);
    add_temp("apply/hp", 1000);
    add_temp("apply/attack", 20);
    add_temp("apply/intimidate", 20);

    // ���վ�L ap, hp, mp ���n do_heal(), �~�������A�ɺ�
    do_heal();
}

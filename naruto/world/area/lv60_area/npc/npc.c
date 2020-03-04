#include <npc.h>
#include <ansi.h>
#include "skill.h"

string *name = ({ "���", "�u�\�H", "�G��", "�e��", "�_�u��", "�L�Y��", "�L��", "�\��" });

void create()
{
    set("skill_list", random(6));
    set_level(45);
    set_race("human");

    switch( query("skill_list") ) {
        case 1:
            set_name(RED"�d��"NOR+name[random(sizeof(name))], ({ "wu skeleton", "skeleton" }) );
            set("set_drop", ({
                ([ "type":"eq", "id":2, "amount":1, "p1":50, "p2":100 ]),     // �K�ݥ�
                ([ "type":"eq", "id":16, "amount":1, "p1":80, "p2":100 ]),    // ��c
                ([ "type":"obj", "id":129, "amount":1, "p1":30, "p2":100 ]),  // ���
                ([ "type":"wp", "id":76, "amount":1, "p1":1, "p2":600 ]),     // �d�󧯪���
            }) );
            break;
        case 2:
            set_name(CYN"�Q��"NOR+name[random(sizeof(name))], ({ "wei skeleton", "skeleton" }) );
            set("set_drop", ({
                ([ "type":"eq", "id":2, "amount":1, "p1":50, "p2":100 ]),     // �K�ݥ�
                ([ "type":"eq", "id":16, "amount":1, "p1":80, "p2":100 ]),    // ��c
                ([ "type":"obj", "id":129, "amount":1, "p1":30, "p2":100 ]),  // ���
                ([ "type":"wp", "id":80, "amount":1, "p1":1, "p2":600 ]),     // �Q�����B�C
            }) );
            break;
        case 3:
            set_name(HIM"��Q�a"NOR+name[random(sizeof(name))], ({ "mouri skeleton", "skeleton" }) );
            set("set_drop", ({
                ([ "type":"eq", "id":2, "amount":1, "p1":50, "p2":100 ]),     // �K�ݥ�
                ([ "type":"eq", "id":16, "amount":1, "p1":80, "p2":100 ]),    // ��c
                ([ "type":"obj", "id":129, "amount":1, "p1":30, "p2":100 ]),  // ���
                ([ "type":"wp", "id":75, "amount":1, "p1":1, "p2":800 ]),     // ��Q���}
            }) );
            break;
        case 4:
            set_name(HIG"�W���a"NOR+name[random(sizeof(name))], ({ "uesugi skeleton", "skeleton" }) );
            set("set_drop", ({
                ([ "type":"eq", "id":2, "amount":1, "p1":50, "p2":100 ]),     // �K�ݥ�
                ([ "type":"eq", "id":16, "amount":1, "p1":80, "p2":100 ]),    // ��c
                ([ "type":"obj", "id":129, "amount":1, "p1":30, "p2":100 ]),  // ���
                ([ "type":"wp", "id":78, "amount":1, "p1":1, "p2":900 ]),     // �����Z�h�M
            }) );
            break;
        case 5:
            set_name(HIW"´�Юa"NOR+name[random(sizeof(name))], ({ "oda skeleton", "skeleton" }) );
            set("set_drop", ({
                ([ "type":"eq", "id":2, "amount":1, "p1":50, "p2":100 ]),     // �K�ݥ�
                ([ "type":"eq", "id":16, "amount":1, "p1":80, "p2":100 ]),    // ��c
                ([ "type":"obj", "id":129, "amount":1, "p1":30, "p2":100 ]),  // ���
                ([ "type":"wp", "id":77, "amount":1, "p1":1, "p2":900 ]),     // �ؤl�q�K��
            }) );
            break;
        default: 
            set_name(HIR"�Z�Юa"NOR+name[random(sizeof(name))], ({ "takeda skeleton", "skeleton" }) );
            set("set_drop", ({
                ([ "type":"eq", "id":2, "amount":1, "p1":50, "p2":100 ]),     // �K�ݥ�
                ([ "type":"eq", "id":16, "amount":1, "p1":80, "p2":100 ]),    // ��c
                ([ "type":"obj", "id":129, "amount":1, "p1":30, "p2":100 ]),  // ���
                ([ "type":"wp", "id":79, "amount":1, "p1":1, "p2":900 ]),     // �Z�а��W�j
            }) );
            break;
    }
    if( random(2) == 1) set("gender", "male");
    else set("gender", "female");

    set("age", 200 + random(2000));
    set("long",@LONG
�H�����H�A���������A�����|����סA�����o�u�Ѭ\���A�q���̩Ү�
���Z���M�ϥΪ��Z�N�i�H�ݥX�Ҧ����u���v�ä��O�P�@�ӱڸs���ͪ�
�A���O�G�ꪺ�{�׸��t�p�����j�A���H�����D�p��P�_���̬O�ݩ��
�Ӧ~�N���ͪ��A���L����֩w���O�A�o�̤@�w���g�o�͹L�ܤj���Ԫ�
�A�~�|�ϳo��h���U��������E�b���A��d�U�F�L�ƪ����e�`�͡C
LONG);
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
    add_temp("apply/attack", -250);
    if( query("skill_list") == 1 ) {
        carry_object(__DIR__"wp/finger.c")->wield("twohanded");
    } else if( query("skill_list") == 2 ) {
        carry_object(__DIR__"wp/sword.c")->wield();
    } else if( query("skill_list") == 3 ) {
        carry_object(__DIR__"wp/bow.c")->wield("twohanded");
    } else if( query("skill_list") == 4 ) {
        carry_object(__DIR__"wp/katana.c")->wield();
    } else if( query("skill_list") == 5 ) {
        carry_object(__DIR__"wp/gun.c")->wield("twohanded");
    } else {
        carry_object(__DIR__"wp/lance.c")->wield();
    }
}

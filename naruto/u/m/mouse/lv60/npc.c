#include <npc.h>
#include <ansi.h>
#include "skill.h"

string *name = ({ "���", "�u�\�H", "�G��", "�e��", "�_�u��", "�L�Y��", "�L��", "�\��" });

void create()
{
    set("skill_list", random(6));
    set_level(45);
    set_race("human");

    if( query("skill_list") == 1 ) {
        set_name(RED"�d��"NOR+name[random(sizeof(name))], ({ "wu skeleton", "skeleton" }) );
    } else if( query("skill_list") == 2 ) {
        set_name(CYN"�Q��"NOR+name[random(sizeof(name))], ({ "wei skeleton", "skeleton" }) );
    } else if( query("skill_list") == 3 ) {
        set_name(HIM"��Q�a"NOR+name[random(sizeof(name))], ({ "mouri skeleton", "skeleton" }) );
    } else if( query("skill_list") == 4 ) {
        set_name(HIG"�W���a"NOR+name[random(sizeof(name))], ({ "uesugi skeleton", "skeleton" }) );
    } else if( query("skill_list") == 5 ) {
        set_name(HIW"´�Юa"NOR+name[random(sizeof(name))], ({ "oda skeleton", "skeleton" }) );
    } else {
        set_name(HIR"�Z�Юa"NOR+name[random(sizeof(name))], ({ "takeda skeleton", "skeleton" }) );
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
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":100+random(200), "p1":60, "p2":100 ]), // �Ȥl
        ([ "type":"food", "id":16, "amount":1, "p1":3, "p2":100 ]),      // �j��O�Y
        ([ "type":"food", "id":18, "amount":1, "p1":5, "p2":100 ]),      // �j��O�Y
        ([ "type":"food", "id":20, "amount":1, "p1":3, "p2":100 ]),      // �j�d�J�Y
    }) );
    setup();
    add_temp("apply/attack", -250);
    if( query("skill_list") == 1 ) {
        carry_object(__DIR__"finger.c")->wield("twohanded");
    } else if( query("skill_list") == 2 ) {
        carry_object(__DIR__"sword.c")->wield();
    } else if( query("skill_list") == 3 ) {
        carry_object(__DIR__"bow.c")->wield("twohanded");
    } else if( query("skill_list") == 4 ) {
        carry_object(__DIR__"katana.c")->wield();
    } else if( query("skill_list") == 5 ) {
        carry_object(__DIR__"gun.c")->wield("twohanded");
    } else {
        carry_object(__DIR__"lance.c")->wield();
    }
}

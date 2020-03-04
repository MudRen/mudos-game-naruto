#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_VENDOR;

void do_say()
{
    do_chat( ({ 
        (: command, "say �F�H�������Z���ܴγ�I" :),
        (: command, "say �R�����Q�X�����@���I���G�s�ڨӽ��F�H�������Z���I" :),
        (: command, "say �����򤣬O�o�ۤv�ӽ�I" :),
        (: command, "cry" :),
    }) );
}

void create()
{
    set_name("���", ({ "chopper" }) );
    set_race("human");
    set_level(40);
    set_class("thief_sea");  // ����
    set("age", 10);
    set("no_fight", 1);
    set("title", HIM"����"NOR);
    set("long", "�Ŧ��l�����ߡA����I�O�����I�]���Y�F�c�]�G��[�W�Ŧ⪺��\n"
                "�l�A�����Q�����P���X���H���]�����ǥL�C��ӵo�ͤF�Y�ǨƦӥ[\n"
                "�J��U����Φ�������C\n");

    set("chat_chance", 3);
    set("chat_msg", ({
        (: do_say :),
    }) );

    // �]�w�ӤH�ҳc�檺���~
    // set_goods(�N�X, ����, �s��, �ƶq, ���)
    // �ӤH��c�檺�F��u��� query ���O�̬d eq, wp, food ��d�X�Ӫ����~
    // �p set_goods(1, "food", 1, 10, -1) ��ܳc�� query ���O�d�X�Ӫ�food�s����1�����~�Q��
    // �Y�ƶq�]�w -1 ��ܵL���q����
    // �Y����]�� -1 ��ܻ����O�ϥθӪ���]�w��value
    // �N�X�O�Ω� buy ���O�W�A�p buy 1 �h�|�V�ӤH�R�U�N�X��1���ӫ~

    set_goods(1, "wp", 62, -1, -1);
    set_goods(2, "wp", 64, -1, -1);
    set_goods(3, "food", 76, -1, -1);
set_goods(4, "food", 10, -1, -1);
    set_goods(5, "food", 11, 50, -1);


    setup();
    set_skill("combat", 200);
    set_skill("dodge", 170);
    set_skill("parry", 150);
    set_skill("heavy hit", 150);
    set_skill("savage hit", 150);
    set_skill("continual hit", 150);
}

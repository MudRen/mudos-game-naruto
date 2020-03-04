#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    object enemy;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // �}�a��
    command("perform destory fist.attack on " + enemy->query_id() );
}
void create()
{
    set_name("�ŭ}�j��", ({ "johnson" }) );
    set_race("human");
    set_level(60);
    set_class("hxh_star");  // �@�P�y�H
    set("age", 45);
    set("camp", "hunter");
    set("nickname", HIB"����"NOR);
    set("long", "���Y����`�H�����j�٦רk�A�]�����W��ۺ򨭦��{�X��������\n"
                "���A�쥻�O�@��b�u�a�̪��u�H�A��ӳQ�]�N�����Ϊ��H���o����\n"
                "�[�J�A��t���ج��������͡C�i�H�Q��train ���O�Ӿǲߧޯ�C��\n"
                "�� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n");

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    // �u�о��y�H
    set("guild", "hunter");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 200, "hunter", 0);            // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 120, "hunter", -2);            // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 140, "hunter", -2);            // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 200, "hunter", 0);         // �������N
    set_train_with_camp("savage hit", 1, 5, 140, "hunter", -2);       // �������N
    set_train_with_camp("continual hit", 1, 5, 160, "hunter", -2);    // �s�����N
    set_train_with_camp("strength", 1, 10, 200, "hunter", -1);        // �j�ƨt�{��
    set_train_with_camp("body strength", 0, 15, 160, "hunter", -1);   // ����j��
    set_train_with_camp("powerup", 1, 21, 200, "hunter", 0);          // ��O
    set_train_with_camp("destory fist", 0, 20, 140, "hunter", 0);     // �}�a��

    setup();
    set_skill("combat", 180);
    set_skill("dodge", 120);
    set_skill("parry", 120);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 140);
    set_skill("continual hit", 160);
    set_skill("strength", 200);
    set_skill("body strength", 200);
    set_skill("powerup", 200);
    set_skill("destory fist", 200);
}
int accept_kill(object me, string arg)
{
    if( this_object()->query_condition("body_strength_cond", 1) == 0) {
        do_chat( ({
            (: command, "perform body strength.powerup" :),
            (: command, "say �ݬݧa�I�o�������٦סI" :),
        }) );
    } else {
        do_chat( ({
            (: command, "say �����ॢ�h�o���u�@�I" :),
        }) );
    }
}
int accept_fight(object me, string arg)
{
    return 0;
}

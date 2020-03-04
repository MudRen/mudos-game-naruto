#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    object enemy, sword, item;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( !objectp(sword = present("_CREATION_SWORD_", this_object())) ) {
        item = new("/daemon/skill/hxh/concrete/obj/sword_obj.c");
        item->move(this_object());
    }
    if( this_object()->query_condition("firewall") == 0 ) {
        command("perform fire wall.fire");
    } else {
        command("perform frost closed ball.ball on " + enemy->query_id() );
    }
    return;
}

void create()
{
    set_name("���p����", ({ "yan feng", "feng", "yan" }) );
    set_race("human");
    set_level(70);
    set_class("hxh_star2");  // �G�P�y�H
    set("age", 46);
    set("camp", "hunter");
    set("nickname", HIM"�]�N�v"NOR);
    set("long", "�����H���O��Ƭ���q����O�A�]���ѥ[�@���W���t�M�Ԫ����C��\n"
                "�Ө�B�j����L�ѥ[�̱����A�ٳп�u�]�N�����Ρv�N�ۤv������\n"
                "�O���˦��]�N��B��t�A�䤤���ֹέ��������D�L�u�����ت��C\n"
                "�i�H�Q��train ���O�Ӿǲߧޯ�C\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n");

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
    set_train_with_camp("combat", 1, 1, 160, "hunter", -2);              // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 140, "hunter", -2);               // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 160, "hunter", -2);               // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 160, "hunter", -2);           // �������N
    set_train_with_camp("savage hit", 1, 5, 140, "hunter", -2);          // �������N
    set_train_with_camp("continual hit", 1, 5, 180, "hunter", -2);       // �s�����N
    set_train_with_camp("variation", 1, 10, 200, "hunter", -2);          // �ܤƨt�{��
    set_train_with_camp("fire variation", 0, 15, 160, "hunter", -1);     // �����O�ܤ�
    set_train_with_camp("ice variation", 0, 15, 160, "hunter", -1);      // �B���O�ܤ�
    set_train_with_camp("electric variation", 0, 15, 160, "hunter", -1); // �q���O�ܤ�
    set_train_with_camp("frost closed ball", 0, 21, 140, "hunter", 0);   // �B�ʲy
    set_train_with_camp("chain lighting", 0, 21, 140, "hunter", 0);      // �s��{�q
    set_train_with_camp("fire wall", 1, 21, 140, "hunter", 0);           // ����

    setup();
    set_skill("combat", 160);
    set_skill("dodge", 140);
    set_skill("parry", 160);
    set_skill("heavy hit", 160);
    set_skill("savage hit", 140);
    set_skill("continual hit", 180);
    set_skill("variation", 200);
    set_skill("ice variation", 200);
    set_skill("frost closed ball", 200);
    set_skill("fire wall", 200);
}
int accept_fight(object me, string arg)
{
    return 0;
}

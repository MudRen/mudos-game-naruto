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
    if( this_object()->query_condition("diabo_busy") != 0 ) {
        message_vision(HIW"$N�o��$N���O�A�h�������]�_���N�o�ɶ��F�C\n"NOR, this_object());
        this_object()->delete_condition("diabo_busy");
    }
    command("perform almighty creation.rain on " + enemy->query_id() );
    return;
}

void do_sword()
{
    object sword;
    if( !objectp(sword = present("_CREATION_SWORD_", this_object())) ) {
        command("perform almighty creation.gz" );
    }
    return;
}

void create()
{
    set_name("��[����", ({ "gilgamesh" }) );
    set_race("human");
    set_level(80);
    set_class("hxh_star2");  // �G�P�y�H
    set("age", 24);
    set("camp", "hunter");
    set("nickname", HIY"�^����"NOR);
    set("long", "���ܤ������̡A�֦��L�H����O�L�H�i�ǼġA�ߦn�����U�ئU����\n"
                "�M�C�L���A�b����Q�t�M�l�ꦨ���^�F�A����o�F����l���U���U\n"
                "�˪Z������O�C�L�O�Q�]�N�����Ϊ��l��ӨӪ��C�i�H�Q��train \n"
                "���O�Ӿǲߧޯ�C�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n");

    set("chat_chance", 20);
    set("chat_msg", ({
        (: do_sword :),
    }) );

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
    set_train_with_camp("combat", 1, 1, 180, "hunter", -2);             // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 140, "hunter", -2);              // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 180, "hunter", -2);              // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 200, "hunter", 0);          // �������N
    set_train_with_camp("savage hit", 1, 5, 140, "hunter", -2);         // �������N
    set_train_with_camp("continual hit", 1, 5, 160, "hunter", -2);      // �s�����N
    set_train_with_camp("concrete", 1, 10, 200, "hunter", -1);          // ��{�ƨt�{��
    set_train_with_camp("eaves family", 0, 15, 160, "hunter", -1);      // ��ò�U���@�a�H
    set_train_with_camp("chamber fish", 0, 21, 140, "hunter", 0);       // �K�ǩ���
    set_train_with_camp("almighty creation", 0, 20, 120, "hunter", 0);  // �L�����C�s

    setup();
    set_skill("combat", 140);
    set_skill("dodge", 160);
    set_skill("parry", 180);
    set_skill("heavy hit", 140);
    set_skill("savage hit", 160);
    set_skill("continual hit", 160);
    set_skill("concrete", 200);
    set_skill("eaves family", 200);
    set_skill("chamber fish", 200);
    set_skill("almighty creation", 200);
}
int accept_fight(object me, string arg)
{
    return 0;
}

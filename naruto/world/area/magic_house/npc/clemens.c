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
    switch( random(4) ) {
        case 0: this_object()->delete_temp("ticket_card");
                this_object()->set_temp("ticket_card/music", 1);
                command("perform lending ticket.guard" );
                break;
        case 1: this_object()->delete_temp("ticket_card");
                this_object()->set_temp("ticket_card/bow", 1);
                command("perform lending ticket.guard" );
                break;
        case 2: this_object()->delete_temp("ticket_card");
                this_object()->set_temp("ticket_card/ton", 1);
                command("perform lending ticket.attack on " + enemy->query_id() );
                break;
        case 3: this_object()->delete_temp("ticket_card");
                this_object()->set_temp("ticket_card/wheya", 1);
                command("perform lending ticket.attack on " + enemy->query_id() );
                break;
    }
}

void do_change()
{
    if( this_object()->query_condition("ticket", 1) != 0 && !this_object()->is_fighting() ) {
        this_object()->delete_condition("ticket");
    }
    if( this_object()->query_condition("ghost_change1", 1) != 0 ) return;
    command("perform change ability.change dex");
}

void create()
{
    set_name("�J�ܪ���", ({ "clemens" }) );
    set_race("human");
    set_level(60);
    set_class("hxh_star");  // �@�P�y�H
    set("age", 45);
    set("camp", "hunter");
    set("nickname", HIR"���b�H"NOR);
    set("long", "�b�]�N�����Τ��H��̩������P�A���F�~��T���l�ޤ��ְ��k�e��\n"
                "�[�ݡA�L�����H�޳N��O�X���J�ơA�U���Ť���t�u�n�w�����K��\n"
                "���A�o����b�H���٩I�A��t���ج��Ť����H�C�i�H�Q��train ��\n"
                "�O�Ӿǲߧޯ�C�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n");

    set("chat_chance", 50);
    set("chat_msg", ({
        (: do_change :),
    }) );
    set("chat_chance_combat", 15);
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
    set_train_with_camp("combat", 1, 1, 120, "hunter", -2);           // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 200, "hunter", 0);             // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 140, "hunter", -2);            // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 140, "hunter", -2);        // �������N
    set_train_with_camp("savage hit", 1, 5, 160, "hunter", -2);       // �������N
    set_train_with_camp("continual hit", 1, 5, 200, "hunter", -2);    // �s�����N
    set_train_with_camp("special", 1, 10, 200, "hunter", -2);         // �S��t�{��
    set_train_with_camp("holy hand", 0, 15, 140, "hunter", -1);       // �t������
    set_train_with_camp("change ability", 0, 20, 120, "hunter", 0);   // �����ഫ
    set_train_with_camp("lending ticket", 1, 21, 140, "hunter", 0);   // �ɶU��

    setup();
    set_skill("combat", 120);
    set_skill("dodge", 200);
    set_skill("parry", 140);
    set_skill("heavy hit", 140);
    set_skill("savage hit", 160);
    set_skill("continual hit", 200);
    set_skill("special", 200);
    set_skill("holy hand", 200);
    set_skill("change ability", 200);
    set_skill("lending ticket", 200);
}
int accept_kill(object me, string arg)
{
    mapping cnd = ([]);

    if( this_object()->query_condition("ticket", 1) == 0) {

        cnd["name"] = HIW+"�Ť����H"+NOR;
        cnd["duration"] = 900;
        cnd["from"] = this_object();
        this_object()->set_condition("ticket", cnd);

        do_chat( ({
            (: command, "say �_���̡I�o�N�s�Ť����H�I" :),
        }) );
    } else {
        do_chat( ({
            (: command, "say ���D���b�Ť����Pı�ܡI" :),
        }) );
    }
}
int accept_fight(object me, string arg)
{
    return 0;
}

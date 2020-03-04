#include <npc.h>
#include <ansi.h>

inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    object enemy;
    object* targets;
    int i, ntar;

    // �S���ĤH
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();
    ntar = sizeof(targets);

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( ntar > 0 ) enemy = targets[random(ntar)];
    else enemy = this_object()->query_opponent();

    if( !enemy->query_condition("rain") ) {
        command("perform drench.assoil on " + enemy->query_id() );
    } else if( !query_condition("thunderbolt") ) {
        command("perform thunderbolt lance.compo");
    } else if( ntar > 1 ) {
        command("perform powerful thunderbolt.jet on " + enemy->query_id());
    } else {
        command("perform thunderbolt lance.back on " + enemy->query_id());
    }
    return;
}
void create()
{
    set_name("�R��", ({ "nami", "_NAMI_" }) );
    set_race("human");
    set_level(40);
    set_class("thief_sea");         // ����
    set("classify", "strengthen");  // �j��
    set("age", 18);
    set("gender", "female");
    set("title", HIC"����h"NOR);
    set("long", "�]���U����Ϊ������ҽT�{���ưȡA�{�b�]�������p���A\n"
                "�R���]���ۦb�e�۹ڷQ�������ϡC�]���Y�ǭ�]����D�`�����ۡA\n"
                "�u�n��W���N�����ܭӤH�F�C\n"
                "����M���x�ޯ�i���۾ǲߡA�Q�� train ���O�ӦV�R���ǲߧޯ�C\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    set("chat_chance", 30);
    set("chat_msg", ({
        (: do_heal :),
    }) );
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    // �����L�R�����оǫK�[�J���������
    // �ܩ��h���x�٬O����èS���v�T
    set("guild", "piece");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 120, "robber", -2);                  // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 160, "robber", -2);                   // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 160, "robber", -2);                   // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 170, "robber", -2);               // �������N
    set_train_with_camp("savage hit", 1, 5, 150, "robber", -2);              // �������N
    set_train_with_camp("continual hit", 1, 5, 180, "robber", -2);           // �s�����N
    set_train_with_camp("activity", 1, 10, 160, "robber", -2);               // �S���¦
    set_train_with_camp("anemometer", 1, 15, 160, "robber", -1);             // �S��G���t�p
    set_train_with_camp("drench", 1, 21, 140, "robber", -1);                 // �S��G���b�j�B
    set_train_with_camp("chimera fay", 0, 20, 120, "robber", 0);             // �S��G�۷Q����
    set_train_with_camp("powerful thunderbolt", 0, 30, 100, "robber", 2);    // �S��G�p�^�U�v
    set_train_with_camp("thunderbolt lance", 0, 40, 80, "robber", 2);       // �S��G�p���j

    set("set_drop", ({
        ([ "type":"wp", "id":67, "amount":1, "p1":1, "p2":500 ]),                 // �ѭԴ�
        ([ "type":"wp", "id":62, "amount":1, "p1":80, "p2":100 ]),                // ��t�ΤѭԴ�
        ([ "type":"obj", "id":28, "amount":30+random(120), "p1":100, "p2":100 ]), // ����
    }) );

    setup();
    set_skill("combat", 160);
    set_skill("dodge", 160);
    set_skill("parry", 200);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 200);
    set_skill("continual hit", 160);
    set_skill("activity", 200);
    set_skill("anemometer", 200);
    set_skill("drench", 200);
    set_skill("chimera fay", 200);
    set_skill("powerful thunderbolt", 200);
    set_skill("thunderbolt lance", 200);

    add_temp("apply/evade", 250);       // �j��
    add_temp("apply/int", 20);
    add_temp("apply/dex", 10);

    carry_object(__DIR__"wp/sky_stick.c")->wield("twohanded");
}

int accept_kill(object me, string arg)
{
    object ob;
    if( ob = present("_ROBIN_", environment(this_object())) ) {
        ob->dismiss_team();
        ob->set_team(0);
        message_vision("ù�����D�G"HIG"����h�p�j�O�ڭ̭��n�����C\n\n"NOR, ob);
        ob->set_team(this_object());
        ob->add_team_member(this_object());
        ob->kill_ob(me);
        if( function_exists("accept_kill", me) && !me->is_killing(ob) && me->accept_kill(ob) ) return 1;
        me->kill_ob(ob);
    }
    if( !query_condition("elf") ) {
        do_chat( ({(: command, "perform chimera fay.assoil" :)}) );
    }
}

int accept_fight(object me, string arg)
{
    do_chat( ({
        (: command, "angry" :),
        (: command, "say ���n���Z�ڵe���ϡC" :),
    }) );
    return 0;
}

void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 10 + random(6);

    if( !enemy ) {
        destruct(this_object());  // �䤣����A��������
        return;
    }
    // �d��������D�H��
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = "\n\n"HIC"�@�}�j���N��W�����ϥ����j���A���V���j����D�U�B...\n\n"HIW"���O���Ϫ��D�H�A�]�L�k�w�����V�Ѯ�...�]�L�k�~��e���ϤF...\n\n"NOR;
    msg += HIR"�i���|�s�D�j"HIY"�u�p��ߡv"HIR+this_object()->query("name")+"("+this_object()->query("id")+")�Q�c�W�L�����a�J"+enemy->query("name")+"("+enemy->query("id")+")�����F�I\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A�����R����o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

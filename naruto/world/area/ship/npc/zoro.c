#include <npc.h>
#include <ansi.h>

inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    object enemy;
    object* targets;
    int i, j;

    // �S���ĤH
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();

    if( query_stat_current("hp") < query_stat_maximum("hp")/4 ) i = 6;
    else i = random(5) + 1;

    if( !enemy ) return;
    if( query_temp("asuri", 1) ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( i ) {
        case 1: // �N����
            command("perform fire ghost chop.attack on " + enemy->query_id() );
            break;

        case 2: // �G��
            command("perform chop two.attack on " + enemy->query_id() );
            break;

        case 3: // �T�Q���дo��
            command("perform age agonize.attack on " + enemy->query_id() );
            break;

        case 4: // ��l���q
            command("perform dirge lion.attack on " + enemy->query_id() );
            break;

        case 5: // �T�d�@��
            message_vision("\n$N"HIR"�N�G��Z�����b��W�}�l����....�|�P���Ů���G���I����...\n"NOR,this_object(), enemy);
            message_vision("\n"HIW"��"NOR"$n"HIW"�o�ʧ����ɥu��"NOR"$N"HIW"���a���F"NOR"$n"HIW"���}��A�ϥX��������"HIY"�y"HIR+BLINK"�T�d�@��"NOR+HIY"�z\n"NOR, this_object(), enemy);
            message_vision("$N"HIW"�uı�o�N�ө��M�D�������A���e�@�դ���]�����D�F...\n"NOR, enemy);
            remove_killer(enemy);
            enemy->remove_killer(this_object());
            enemy->unconcious();
            break;
        case 6:
            set_temp("asuri", 1);
            message_vision(HIK"\n$N���W�o���X�i�Ȫ��]��A�~�M�ƨ����T�Y���u���]��"NOR+MAG"�y����E�E�M�y�z\n"NOR,this_object(), enemy);
            call_out("asuri",5, this_object());
            // ���F��O�^�_ 1/3 ��L�������ɨ캡
            heal_stat("ap", query_stat_maximum("ap"));
            heal_stat("hp", query_stat_maximum("hp")/3);
            heal_stat("mp", query_stat_maximum("mp"));
            for(j=0;j<sizeof(targets);j++) {
                tell_object(targets[j], HIR"�A�Q��������թҾ_�A�@�ɶ��L�k��ʡI\n\n"NOR);
                targets[j]->start_busy(4);
            }
            start_busy(2);
    }
}
void asuri(object ob)
{
    object enemy;
    int damage, raiseDamage;

    enemy = this_object()->query_opponent();

    // �ĤH�����F
    if( !enemy ) {
        do_heal();
        delete_temp("asuri");
        return;
    }
    // �ĤH�b���P��m
    if( environment(ob)->is_area() ) {
        if( !area_environment(ob, enemy) ) {
            delete_temp("asuri");
            return;
        }
    } else {
        if( environment(enemy) != environment(ob) ) {
            delete_temp("asuri");
            return;
        }
    }
    raiseDamage = 4000;
    message_vision(HIK"\n$N�ε۰����몺�^�n���D�G\n\n�y"NOR+MAG"�W���⤰��...\n\n\t�ڥ��N�O���b"NOR+HIR"��ù���D"NOR+MAG"�W���k�H�I"HIK"�z\n\n\n"NOR+RED"�T�Y���u���]��q�|���K�����"NOR"$n"RED"�A�O"NOR"$n"RED"�ڥ��L�q�{�סI"NOR"\n\n�@�@�@�@�@�y "BRED"����ù"NOR"�@�@"HIC+BLINK"��"HIK"�E"NOR+BLINK+YEL"��"HIK"�E"HIW"��"NOR" �z\n\n"NOR, ob, enemy);
    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(ob, enemy, query_temp("weapon/righthand"));
    add_temp("apply/attack", -raiseDamage);
    enemy->receive_damage(damage, ob);
    enemy->damage_stat("ap", damage/2, ob);
    enemy->start_busy(2);
    message_vision( sprintf("$n"HIK"��"NOR+RED"�A��"HIK"����u��a�x�V�Ť��A�q�b�|�P�P$N�����W"NOR"(%d)%s\n"HIR"�Q��P�]���Ţ�n��$N�A�ݰ_�ӴN���n�N"NOR"$n"HIR"�a�J��ù�ɪ��]��...\n\n"NOR, damage, COMBAT_D->report_status(enemy) ), ob, enemy);
    delete_temp("asuri");
    return;
}

void create()
{
    set_name("����", ({ "zoro" }) );
    set_race("human");
    set_level(60);
    set_class("reward_sea");        // �a�����
    set("classify", "strengthen");  // �j��
    set("age", 19);
    set("title", HIG"�����y�H"NOR);
    set("long", "���W�a�ۤT��M���C�ȡA�L�N�O�ۦW�������y�H�wùù�ըȡE����\n"
                "�A���L�]���Y�ǭ�]�{�b���L�w�g������U����Ϊ��@���A�ٳQ�@\n"
                "�ɬF�������a��C\n"
                "����M���x�ޯ�i���۾ǲߡA�Q�� train ���O�ӦV�����ǲߧޯ�C\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    set("chat_chance", 30);
    set("chat_msg", ({
        (: do_heal :),
    }) );
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    // �����L�������оǫK�[�J���������
    // �ܩ��h���x�٬O����èS���v�T
    set("guild", "piece");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 160, "robber", -2);           // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 140, "robber", -2);            // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 180, "robber", -2);            // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 140, "robber", -2);        // �������N
    set_train_with_camp("savage hit", 1, 5, 200, "robber", -2);       // �������N
    set_train_with_camp("continual hit", 1, 5, 120, "robber", -2);    // �s�����N
    set_train_with_camp("blade", 1, 10, 200, "robber", -2);           // �M�N��¦
    set_train_with_camp("ghost chop", 1, 15, 160, "robber", -1);      // �M�N�G����
    set_train_with_camp("chivy tiger", 1, 15, 160, "robber", -1);     // �M�N�G��E���y
    set_train_with_camp("fire ghost chop", 0, 20, 140, "robber", 0);  // �M�N�G�N����
    set_train_with_camp("wolf blade", 1, 21, 120, "robber", -1);      // �M�N�G�M�T�y
    set_train_with_camp("chop two", 0, 30, 100, "robber", 1);         // �M�N�G�G��
    set_train_with_camp("age agonize", 0, 40, 80, "robber", 2);       // �M�N�G�T�Q���дo��
    set_train_with_camp("dirge lion", 0, 40, 100, "robber", 2);       // �M�N�G��l���q

    set("set_drop", ({
        ([ "type":"wp", "id":2, "amount":1, "p1":80, "p2":100 ]),        // �j�M
        ([ "type":"wp", "id":30, "amount":1, "p1":60, "p2":100 ]),       // �����ԤM
        ([ "type":"wp", "id":82, "amount":1, "p1":1, "p2":900 ]),        // ����
        ([ "type":"wp", "id":83, "amount":1, "p1":1, "p2":800 ]),        // �T�N����
        ([ "type":"wp", "id":84, "amount":1, "p1":1, "p2":1500 ]),       // �M�D�@��r
    }) );

    setup();
    set_skill("combat", 180);
    set_skill("dodge", 180);
    set_skill("parry", 180);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 200);
    set_skill("continual hit", 160);
    set_skill("blade", 200);
    set_skill("wolf blade", 200);
    set_skill("ghost chop", 200);
    set_skill("chivy tiger", 200);
    set_skill("fire ghost chop", 200);
    set_skill("chop two", 200);
    set_skill("age agonize", 200);
    set_skill("dirge lion", 200);

    add_temp("apply/exact", 100);       // �R��
    add_temp("apply/evade", 100);       // �j��
    add_temp("apply/intimidate", 150);  // ������O
    add_temp("apply/wittiness", 150);   // ���m��O
    add_temp("apply/con", 15);
    add_temp("apply/str", 15);

    carry_object(__DIR__"wp/zoro1.c")->wield();
    carry_object(__DIR__"wp/zoro2.c")->wield("lefthand");
    carry_object(__DIR__"wp/zoro3.c");
}
int accept_kill(object me, string arg)
{
    if( this_object()->query_condition("bladewolf", 1) == 0) {
        message_vision("$N���D�R"HIG"���ڸդM�ܡH���N��C\n"NOR, this_object());
        command("perform wolf blade.flow");
        message_vision(CYN"$N�y�W�S�X���c�����e�M�����D���̷Q�n�F�C\n"NOR, this_object());
    } else {
        message_vision("$N���D�R"HIG"�ڵ����L�|�ҵ������C\n"NOR, this_object());
    }
}
int accept_fight(object me, string arg)
{
    do_chat( ({
        (: command, "shake" :),
        (: command, "say ���F�����@�ɲĤ@���j�C�ȡA�S���ɶ���"+me->query("name")+"���R�C" :),
    }) );
    return 0;
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 80 + random(21);

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
    msg = "\n\n"GRN"�����N���W���Z�������̤@��A��L���l�����"NOR+enemy->query("name")+"\n\n\t"HIR"�y�J�M�n�����Ĥ@�A�ڦ��w�N�ͦ��m���ץ~�I\n\n\t\t�I�ᤤ�C�O�C�h�����d�A�]�O�ɭԸ����}�F�C�z\n\n"HIW+enemy->query("name")+"�H�Y���ʤ⤤���Z���A�N"NOR+GRN"�u�����y�H�v"NOR"����"HIW"���ͩR�F���F..."NOR"\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����������o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

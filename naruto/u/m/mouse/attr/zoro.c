#include <npc.h>
#include <ansi.h>

inherit F_TRAINER;    // �V�m�ɮv

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$N" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$N" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$N" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_fight()
{
    object enemy;
    int i;

    // �S���ĤH
    enemy = this_object()->query_opponent();
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
            message_vision("\n"HIW"��"NOR"$N"HIW"�o�ʧ����ɥu��"NOR"$n"HIW"���a���F"NOR"$N"HIW"���}��A�ϥX��������"HIY"�y"HIR+BLINK"�T�d�@��"NOR+HIY"�z\n"NOR, enemy, this_object());
            message_vision("$N"HIW"�uı�o�N�ө��M�D�������A���e�@�դ���]�����D�F...\n"NOR, enemy, this_object());
            remove_all_killer();
            do_heal();
            enemy->unconcious();
            break;
        case 6:
            set_temp("asuri", 1);
            message_vision(HIK"\n$N���W�o���X�i�Ȫ��]��A�~�M�ƨ����T�Y���u���]��"NOR+MAG"�y����E�E�M�y�z\n"NOR,this_object(), enemy);
            call_out("asuri",5, this_object(), enemy);
            tell_object(enemy, HIR"�A�Q��������թҾ_�A�@�ɶ��L�k��ʡI\n"NOR);
            enemy->start_busy(3);
            start_busy(2);
    }
}
void asuri(object ob, object enemy)
{
    int damage = ob->query_ability("attack")*2 + ob->query_ability("defend")*2 + random(1000);
    message_vision(HIK"\n$N�ε۰����몺�^�n���D�G\n\n�y"NOR+MAG"�W���⤰��...\n\n\t�ڥ��N�O���b"NOR+HIR"��ù���D"NOR+MAG"�W���k�H�I"HIK"�z\n\n\n"NOR+RED"�T�Y���u���]��q�|���K�����"NOR"$n"RED"�A�O"NOR"$n"RED"�ڥ��L�q�{�סI"NOR"\n\n�@�@�@�@�@�y "BRED"����ù"NOR"�@�@"HIC+BLINK"��"HIK"�E"NOR+BLINK+YEL"��"HIK"�E"HIW"��"NOR" �z\n\n"NOR, ob, enemy);
    enemy->receive_damage(damage, ob);
    enemy->damage_stat("ap", damage/5, ob);
    enemy->start_busy(2);
    message_vision("$N"HIK"��"NOR+RED"�A��"HIK"����u��a�x�V�Ť��A�q�b�|�P�P$n�����W"NOR"("+damage+")"+report_status(enemy)+""HIR"�Q��P�]���Ţ�n��$n�A�ݰ_�ӴN���n�N"NOR"$N"HIR"�a�J��ù�ɪ��]��...\n"NOR, enemy, this_object());
    do_heal();
    delete_temp("asuri");
    return;
}

void create()
{
    set_name("����", ({ "zoro" }) );
    set_race("human");
    set_level(60);
    set_class("reward_sea");  // �a�����
    set("age", 19);
    set("title", HIG"�����y�H"NOR);
    set("long", "���W�a�ۤT��M���C�ȡA�L�N�O�ۦW�������y�H�wùù�ըȡE����\n"
                "�A���L�]���Y�ǭ�]�{�b���L�w�g������U����Ϊ��@���A�ٳQ�@\n"
                "�ɬF�������a��C\n"
                "����M���x�ޯ�i���۾ǲߡA�Q�� train ���O�ӦV�����ǲߧޯ�C\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    set("chat_chance_combat", 100);
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
    set_train_with_camp("wolf blade", 1, 15, 140, "robber", -1);      // �M�N�G�M�T�y
    set_train_with_camp("ghost chop", 1, 15, 160, "robber", -1);      // �M�N�G����
    set_train_with_camp("chivy tiger", 1, 15, 160, "robber", -1);     // �M�N�G��E���y
    set_train_with_camp("fire ghost chop", 0, 20, 140, "robber", 0);  // �M�N�G�N����
    set_train_with_camp("chop two", 0, 30, 140, "robber", 1);         // �M�N�G�G��
    set_train_with_camp("age agonize", 0, 40, 120, "robber", 2);      // �M�N�G�T�Q���дo��
    set_train_with_camp("dirge lion", 0, 40, 120, "robber", 2);       // �M�N�G��l���q

    set("set_drop", ({
        ([ "type":"wp", "id":66, "amount":1, "p1":1, "p2":500 ]),        // �T�N����
        ([ "type":"wp", "id":68, "amount":1, "p1":1, "p2":500 ]),        // ����
        ([ "type":"wp", "id":63, "amount":1, "p1":1, "p2":800 ]),        // �M�D�@��r
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
//  carry_object(__DIR__"wp/snow_blade.c")->wield();
//  carry_object(__DIR__"wp/ghost_blade.c")->wield("lefthand");
//  carry_object(__DIR__"wp/beta_blade.c");
    add_temp("apply/exact", 100);       // �R��
    add_temp("apply/evade", 100);       // �j��
    add_temp("apply/intimidate", 150);  // ������O
    add_temp("apply/wittiness", 150);   // ���m��O
    add_temp("apply/con", 15);
    add_temp("apply/str", 15);
}
int accept_kill(object me, string arg)
{
    if( this_object()->query_condition("bladewolf", 1) == 0) {
        message_vision("�������D�R"HIG"���ڸդM�ܡH���N��C\n"NOR, this_object());
        message_vision(CYN"�����y�W�S�X���c�����e�M�����D���̷Q�n�F�C\n"NOR, this_object());
        do_chat( ({
            (: command, "perform wolf blade.flow" :),
        }) );
    } else {
        message_vision("�������D�R"HIG"�ڵ����L�|�ҵ������C\n"NOR, this_object());
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

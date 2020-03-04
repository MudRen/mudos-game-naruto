#include <npc.h>
#include <ansi.h>

inherit F_TRAINER;         // �V�m�Ԫ�

void do_fight()
{
    int x, y, hit, damage, raiseDamage;
    object enemy, pet, ob, yaa;
    string msg;
    mapping cnd = ([]);

    // �S���ĤH
    enemy = this_object()->query_opponent();
    pet = this_object()->query_temp("pet");
    x = this_object()->query("area_info/x_axis");
    y = this_object()->query("area_info/y_axis");

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( !query_condition("four_foot") ) {
        command("perform four foot.beast");
        return;
    } else if( !query_condition("fang_cd") ) {
        switch( random(2) ) {
            case 0:  // ���q��
                if( !present("_PET_YAA_", environment(this_object())) ) {
                    command("perform double fang.atwirl on " + enemy->query_id() );
                    break;
                }
            case 1:  // �~�H�����A�p�G�w�g�����L�N�Τ��T��
                if( pet ) {
                    destruct(pet);
                    yaa = new(__DIR__"yaa.c");
                    yaa->set_name(HIR"[��]"NOR"�����", ({ "quan zhong yaa", "yaa", "_PET_YAA_" }));
                    yaa->set_temp("dog_quit", 1);
                    message_vision(CYN"\n$N�y�W�S�X�@�ٳӧQ���L���A��⭸�ֵ��L�A�}�l�I�i"HIR"�y�~�H�����z"NOR+CYN"���N�I\n"NOR, this_object());
                    if( area_move(environment(this_object()), yaa, x, y) ) {
                        message_vision("�u��"+this_object()->query("pet/name")+"�u�y�v�a�@�}������A�~�M�ܦ��F$N�I\n\n"NOR, this_object());
                        yaa->kill_ob(enemy);
                        if( function_exists("accept_kill", enemy) && !enemy->is_killing(yaa) && enemy->accept_kill(yaa) ) return;
                        enemy->kill_ob(yaa);
                        message_vision("\n"NOR, this_object());
                    } else {
                        message_vision("���O����Ʊ��]�S���o��...\n\n"NOR, this_object());
                    }
                    break;
                }
            default:
                if( ob = present("_PET_YAA_", environment(this_object())) ) {
                    if( !area_environment(this_object(), ob) ) break;   // ���b�P�줣����
                    if( this_object() == ob ) break;                    // ���������
                    if( random(2) == 1 ) msg = "\n$n"HIC"�ਭ�@�D��$N�����W�A��H�}�l�@�P�ֳt���L�I�i"HIK"�y"BLINK+HIR" �� "NOR+BLINK+RED"�T "HIR"�� "NOR+HIK"�z"HIC"�Φ���D�j�l���������V�ؼСI\n"NOR;
                    else msg = HIC"\n$N�ਭ�@�D��$n"HIC"�����W�A��H�}�l�@�P�ֳt���L�I�i"HIK"�y"BLINK+HIR" �� "NOR+BLINK+RED"�T "HIR"�� "NOR+HIK"�z"HIC"�Φ���D�j�l���������V�ؼСI\n"NOR;
                    hit = this_object()->query_ability("exact");

                    this_object()->add_temp("apply/exact", hit)/2;
                    message_vision(msg, this_object(), ob);
                    if( !COMBAT_D->isHit(this_object(), enemy) ) {
                        message_vision("�u�O��H�ϥΤF�L�h���O�D�A�~�M�ĹL�Y�b$N���a�W�F�X�`�ƤQ���ت��j�}�I\n\n"NOR, enemy);
                    } else {
                        raiseDamage = 2200;

                        this_object()->add_temp("apply/attack", raiseDamage);
                        damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                        this_object()->add_temp("apply/attack", -raiseDamage);

                        if( damage < 1200 ) damage = random(400) + 800;

                        enemy->receive_damage(damage, this_object());
                        message_vision( sprintf("�����@�e�@��a����$n�A�������$n�����l�A�Φ���Ӧ�]�K(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                    }
                    this_object()->add_temp("apply/exact", -hit);
                    cnd["name"] = HIC+"(CD)�T��"+NOR;
                    cnd["duration"] = 5;

                    this_object()->set_condition("fang_cd", cnd);
                }
                break;
        }
    }
    return;
}

void to_do_say()
{
    int i;
    object pet, ob;
    object *inv;

    inv = all_inventory(environment(this_object()));

    if( ob = present("_PET_YAA_", environment(this_object())) ) {
        if( this_object() != ob ) {
            message_vision(CYN"$N�ݥ|�P�S���ĤH�A�K��$n"CYN"�ܦ^"+query("pet/name")+"�F�C\n"NOR, this_object(), ob);
            destruct(ob);
            command("perform animal taming.call");
        }
        return;
    }
    if( !objectp(pet = this_object()->query_temp("pet")) ) {
        add_temp("call_pet", 1);
        for(i=0;i<sizeof(inv);i++) {
            if( inv[i] == this_object() ) continue;
            if( !this_object()->visible(inv[i]) ) continue;
            if( userp(inv[i]) ) continue;
            if( environment()->is_area() && !area_environment(this_object(), inv[i])) continue;
            if( ob = present("_MY_PET_", environment(this_object())) ) {
                if( ob->query_owner() == this_object() ) {
                    delete_temp("call_pet");
                    i += sizeof(inv);
                }
            }
        }
        if( query_temp("call_pet") ) {
            command("perform animal taming.call");
        }
    } else if( pet->query_food() < 10 ) {
        pet->add_food(999);
        pet->set_name("���Y", ({ "quan zhong yaa's dog", "dog" }));
        pet->set_level(60);
        pet->set("long", "����������A�ݰ_�Ӥp�p�����Q���i�R�C\n");
        if( pet->query_stat_maximum("hp") != 12000 ) pet->set_stat_maximum("hp", 12000);
        pet->set_stat_maximum("ap", 3000);
        pet->set_stat_maximum("mp", 3000);
        pet->set_stat_current("hp", pet->query_stat_maximum("hp"));
        pet->set_stat_current("ap", pet->query_stat_maximum("ap"));
        pet->set_stat_current("mp", pet->query_stat_maximum("mp"));
        pet->set_attr("str", 120);
        pet->set_attr("con", 120);
        pet->set_attr("dex", 120);
        pet->set_attr("int", 120);
        pet->set_skill("combat", 200);
        pet->set_skill("parry", 200);
        pet->set_skill("dodge", 200);
        pet->set_skill("heavy hit", 200);
        pet->set_skill("savage hit", 200);
        pet->set_skill("continual hit", 200);
    } else if( pet->query_food() < 800 ) {
        pet->add_food(200);
    }
    do_heal();
    return;
}

void create()
{
    set_name("�����", ({ "quan zhong yaa", "yaa" }));
    set_race("human");
    set_level(50);
    set_class("middle");            // ����
    set("classify", "strengthen");  // �j��
    set("camp", "muye");
    set("long", "�ʮ��P�A�H�����ʡB�R�����ʪ��츭���Ԫ̡C�ݩ�i����p����\n"
                "�����C����@�a�N�p��W�A�@�ͳ��P�����@�P��ʡA������]�O�p��\n"
                "���Ǫ����Y�`�O�μv��������ۥD�H������C\n");

    set("age", 16);
    set("gender", "male");

    set("chat_chance", 70);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    set("guild", "muye");
    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 140, "muye", -2);              // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 180, "muye", -2);               // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 120, "muye", -2);               // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 160, "muye", -2);           // �������N
    set_train_with_camp("savage hit", 1, 5, 140, "muye", -2);          // �������N
    set_train_with_camp("continual hit", 1, 5, 140, "muye", -2);       // �s�����N
    set_train_with_camp("ninja", 1, 10, 160, "muye", -2);              // �ԳN
    set_train_with_camp("force", 1, 10, 120, "muye", -2);              // ��N
    set_train_with_camp("animal taming", 0, 15, 140, "muye", -1);      // �ԳN�G���~�N
    set_train_with_camp("double fang", 0, 20, 140, "muye", 0);         // �ԳN�G���q��
    set_train_with_camp("four foot", 1, 21, 120, "muye", 0);           // �ԳN�G�|�}���N

    setup();
    set_skill("combat", 180);
    set_skill("continual hit", 200);
    set_skill("ninja", 200);
    set_skill("double fang", 200);
    set_skill("four foot", 200);
    set_skill("animal taming", 200);
    set_skill("substitute", 200);
    map_skill("dodge", "substitute");

    add_temp("apply/exact", 250);      // �R��
    add_temp("apply/evade", 150);      // �j��
    add_temp("apply/intimidate", 50);  // ������O
    add_temp("apply/dex", 30);
}

void die()
{
    object enemy, killer;
    int i = 15 + random(16);
    string msg;

    enemy = this_object()->last_damage_giver();

    if( !enemy ) {
        destruct(this_object());  // �䤣����A��������
        return;
    }

    if( query_temp("dog_quit") ) { // �d������ ��������
        ::die();
        return;
    }

    // �d��������D�H��
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = HIR"\n���Y���L�a�b�D�H������ǫs�z...\n\n�o�Q"+enemy->query("name")+"�@�}�學�X�h�A�u����b�@�ǭ��_...\n\n"NOR;
    msg += HIG"�i"HIR"�츭�ְT"HIG"�j"HIG"�]���e���D�H�u"NOR+YEL"����@��"HIG"�v"+this_object()->query("name")+"�w�g�Q"+enemy->query("name")+"�����A�]�L�k���_�Ӧ^���e�F...\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

int accept_kill(object me, string arg)
{
    if( query_condition("four_foot") == 0) {
        message_vision("$N���D�R"HIG"�~�M���X��A�|�}���N�I\n"NOR, this_object());
        command("perform four foot.beast");
    } else {
        message_vision("$N���D�R"HIG"�~�M���X��A�ڭ̤W�I���Y�I\n"NOR, this_object());
    }
}

#include <npc.h>
#include <ansi.h>

inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    object enemy;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( query_temp("snipe_ok") ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // �������Ҧ��}��
    if( query("snipe_king", 1) ) {
        // �S���ϥΪ�������N����
        if( !query_condition("snipe") ) {
            command("perform snipe soul.up");
        } else {
            message_vision("$N"CYN"�J�}�F�H�e���x�p�A����"NOR"$n"CYN"�o��j�Ĩ̵M�N�R��ҹﵦ...\n"NOR, this_object(), enemy);
            set_temp("snipe_ok", 1);
            call_out("snipe",2, this_object());
        }
    } else {
        if( query_stat_current("hp") < query_stat_maximum("hp")*1/3 ) {
            message_vision("\n$N�h�W�a���D�R"HIG"...�ڧ֦��F..�I�ϧڡI�������I\n"NOR, this_object());
            message_vision(CYN"�u��$N�q�h�����X�@������a�b�y�W...\n\n"NOR, this_object());
            set_level(50);
            set_name(YEL"������"NOR, ({ "snipe king", "king" }) );
            set("title", HIW"�ʵo�ʤ�"NOR);
            set("snipe_king", 1);

            set_stat_current("hp", query_stat_maximum("hp"));
            set_stat_current("ap", query_stat_maximum("ap"));
            set_stat_current("mp", query_stat_maximum("mp"));

            add_temp("apply/exact", 150);       // �R��
            add_temp("apply/evade", 200);       // �j��
            add_temp("apply/intimidate", 171);  // �����ޥ�
            add_temp("apply/wittiness", 130);   // ���m�ޥ�
            add_temp("apply/dex", 15);
            command("wear mask");
            return;
        } else if( this_object()->query_stat_current("hp") < this_object()->query_stat_maximum("hp")/2 ) {
            command("think");
            command("perform ketchup star.die");
        }
    }
    return;
}
void snipe(object ob)
{
    string msgin, msgout;
    object enemy;
    object* targets;
    int i;

    enemy = query_opponent();
    targets = ob->query_enemy();

    if( !is_fighting() ) {
        delete_temp("snipe_ok");
        return;
    }
    if( !enemy ) {
        delete_temp("snipe_ok");
        return;
    }
    if( environment(ob)->is_area() ) {
        if( !area_environment(ob, enemy) ) {
            delete_temp("snipe_ok");
            return;
        }
    } else {
        if( environment(enemy) != environment(ob) ) {
            delete_temp("snipe_ok");
            return;
        }
    }
    if( query_temp("snipe_check") > 4 ) {
        message_vision("\n$N"CYN"���F���Y�W�������A�֪��ݤ��L��C\n\n"NOR, this_object(), enemy);
        delete_temp("snipe_check");
        delete_temp("snipe_ok");
        return;
    }
    message_vision("\n$N���D�G"HIG"�u�n��$n�L�k�X������I�ڴN���Ӻ�I\n\n"NOR, this_object(), enemy);
    switch ( random(4) ) {
        case 0: 
            msgin = "$N"BYEL"���X�����@���}���A�P�a�@�n�Q�X�j�q������I�z�I�O���I�n��I\n"NOR;
            msgout = "$n"HIY"�����F�������D�A�~�M�N������F�����I\n"NOR;
            break;
        case 1:
            msgin = "$N"HIK"�b�ۤv�������x�U�j�q����I\n"NOR;
            msgout = "��$n�L�k�a��i������I\n"NOR;
            break;
        case 2:
            msgin = "$N"YEL"���X�{�����A���M�|�P�g�X�j�P�벴�����~�I\n"NOR;
            msgout = "$n"HIY"�������Q���u�Ӯg��A�~�M�i���}���L�k�����I\n"NOR;
            break;
        case 3:
            msgin = "$N"REV"�q�y�]���X�T���u�Y�®���@�g�A�զ�@�ϱN�����л\�F�I\n"NOR;
            msgout = "$n"HIW"�@�ɶ��ݤ���$N����m�I��������I\n"NOR;
            break;
    }
    message_vision(msgin, ob);
    for(i=0;i<sizeof(targets);i++) {
        targets[i]->start_busy(5);
        message_vision(msgout, ob, targets[i]);
    }
    call_out("snipe", random(2)+5, this_object(), enemy);
    add_temp("snipe_check", 1);
    return;
}
void to_do_say()
{
    if( query("snipe_king") ) {
        set_name("�F�H��", ({ "usopp" }) );
        set("title", YEL"������"NOR);
        set_level(40);

        add_temp("apply/exact", -150);       // �R��
        add_temp("apply/evade", -200);       // �j��
        add_temp("apply/intimidate", -171);  // �����ޥ�
        add_temp("apply/wittiness", -130);   // ���m�ޥ�
        add_temp("apply/dex", -15);
        delete("snipe_king");
        message_vision("$N"CYN"�����N�N�a�i��|�P�A���ݨS�H�A�~�N������U�C\n"NOR, this_object());
        command("remove mask");
    }
    do_heal();
    return;
}
void create()
{
    set_name("�F�H��", ({ "usopp" }) );
    set_race("human");
    set_level(40);
    set_class("thief_sea");         // ����
    set("classify", "strengthen");  // �j��
    set("age", 16);
    set("title", YEL"������"NOR);
    set("long", "�X�ͦb�����q������������ʵo�ʤ��հհա���l�����������\n"
                "�۵۬Y�D�D���H�L�N�O��U����Ϊ��e�N�z��u�[�������F�H���A\n"
                "�ؼЬO�����i�������W�Ԥh�C\n"
                "����M���x�ޯ�i���۾ǲߡA�Q�� train ���O�ӦV�F�H���ǲߧޯ�\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    set("chat_chance", 50);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    // �����L�F�H�����оǫK�[�J���������
    // �ܩ��h���x�٬O����èS���v�T
    set("guild", "piece");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 140, "robber", -2);               // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 200, "robber", -2);                // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 100, "robber", -2);                // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 120, "robber", -2);            // �������N
    set_train_with_camp("savage hit", 1, 5, 120, "robber", -2);           // �������N
    set_train_with_camp("continual hit", 1, 5, 200, "robber", -2);        // �s�����N
    set_train_with_camp("activity", 1, 10, 160, "robber", -2);            // �S���¦
    set_train_with_camp("interfere star", 1, 15, 140, "robber", -1);      // �S��G�z�Z�P
    set_train_with_camp("ketchup star", 0, 15, 120, "robber", 0);         // �S��G���X��P
    set_train_with_camp("attack star", 1, 21, 160, "robber", -1);         // �S��G�����P
    set_train_with_camp("snipe soul", 0, 25, 100, "robber", 1);           // �S��G��������
    set_train_with_camp("super star", 0, 40, 100, "robber", 2);           // �S��G����

    set("set_drop", ({
        ([ "type":"wp", "id":65, "amount":1, "p1":1, "p2":450 ]),       // �¤}
        ([ "type":"wp", "id":64, "amount":1, "p1":100, "p2":100 ]),     // �u�}
        ([ "type":"eq", "id":116, "amount":1, "p1":1, "p2":800 ]),      // ����������
    }) );

    setup();
    set_skill("combat", 150);
    set_skill("dodge", 200);
    set_skill("parry", 140);
    set_skill("heavy hit", 150);
    set_skill("savage hit", 150);
    set_skill("continual hit", 200);
    set_skill("activity", 200);
    set_skill("interfere star", 200);
    set_skill("ketchup star", 200);
    set_skill("attack star", 200);
    set_skill("super star", 200);
    set_skill("snipe soul", 200);

    add_temp("apply/exact", 50);        // �R��
    add_temp("apply/dex", 15);

    carry_object(__DIR__"wp/du_bow.c")->wield("twohanded");
    carry_object(__DIR__"eq/mask.c");
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 40 + random(11);

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
    msg = "\n\n"YEL"�ϧڡI�������I....�s�������]�L�k�ϧڤF��...\n\n�ڭn�����i�������W�Ԥh�I...��ӥu�O�ӥi���������I\n\n"NOR;
    msg += HIR"�i���|�s�D�j"NOR+YEL"�u�������v"HIR+this_object()->query("name")+"("+this_object()->query("id")+")�G�ѩ�"+enemy->rank()+enemy->query("name")+"("+enemy->query("id")+")����I\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    set_name("�F�H��", ({ "usopp" }) );  // �W�r���^�ӧa
    tell_object(killer, HIY"(�]���A�����F�H����o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

int accept_kill(object me, string arg)
{
    if( query("snipe_king", 1) ) {
        message_vision("$N���D�R"HIG"�ڥi�O�����q���������I\n"NOR, this_object());
    } else {
        message_vision(CYN"$N�G�s�@�n, ���y�u���]�w��?!?!?�v����.\n"NOR, this_object());
        message_vision("$N���D�R"HIG"�A..�A�A..�A�A���k���i�S���|�F��I\n"NOR, this_object());
    }
}

int accept_fight(object me, string arg)
{
    do_chat( ({
        (: command, "say ��..������M..�M���I�h��|�ҡI" :),
        (: command, "fear" :),
    }) );
    return 0;
}

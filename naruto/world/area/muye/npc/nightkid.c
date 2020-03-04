#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;
inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    string *point = ({ "�ʷ|", "���x", "�Ӷ�", "�ժ�", "����", "�H��",
                       "�ת�", "����", "�H��", "�褤", "����", "����",
                       "����", "���", "����", "����", "����", "�N��",
                       "�Ť�", "�Ů�", "����", "����", "�Ӧ�", "�R��",
                       "�Ӥ�", "��u", "�ӫ�", "���[", "�ǫ\\", "�ӲW",
                       "�ͫ\\", "�߫\\", "�T����", "���T��", "����\\", "�ֳ��\\" });
    string msg = "";
    object enemy;
    int damage, raiseDamage, i, exact, evade, number=0;
    mapping cnd = ([]);

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( !query_condition("white_eyes") ) {
        command("perform white eyes.open");
    } else if( !query_condition("sky_palm_cd") ) {
        command("perform sky palm.attack");
    } else {
        switch( random(4) ) {
            case 0: // �ʯP�x
                command("perform hundred palm.attack on " + enemy->query_id() );
                break;
            case 1: // �K�����Q�|�x
                command("perform soft fist.attack on " + enemy->query_id() );
                break;
            case 2: // �K���Ŵx
                message_vision("\n$N�N�d�J�Ծ��E�b�k��A�j�Ŵµ�$n���X�@�O"HIR"�u"HIW"�K���Ŵx"HIR"�v"NOR"�L�Ϋl�D�ĦV$n�I\n"NOR, this_object(), enemy);
                if( !COMBAT_D->isHit(this_object(), enemy) ) {
                    message_vision("�u�S�v�a�@�n�A$n�{�L�F�o�L�Ϊ������A�l�D�b��W�L�X�F�@�Ӵx�L�C\n\n"NOR, this_object(), enemy);
                } else {
                    raiseDamage = 1100;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 700 ) damage = 450 + random(251);

                    enemy->receive_damage(damage, this_object());
                    message_vision( sprintf("�u�I�v�a�@�n�A$n�Pı�@�D�x�l��z�ۤv������A�n�ɳ��V�@�}�̲��A�R�X�F�@�f�A��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                }
                start_busy(3);
                break;
            case 3: // �X���I�޳N
                if( query_condition("fang_cd") ) break;
                exact = COMBAT_D->exact(this_object(), enemy, 1) + COMBAT_D->intimidate(this_object(), 1);
                evade = COMBAT_D->evade(enemy, this_object(), 1);

                message_vision(HIR"\n$N�\�X��V�a�зǧ������A�I�i�y"HIW"�X���k�E"HIC"�I�޳N"HIR"�z��V$n���W�T�Q���Ӥj�ޡI\n"NOR, this_object(), enemy);
                if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                    message_vision("���G$n���G�q��$N�ǳƧ������X�ӥަ�A�H�Y�X��N�����j�}�F�C\n\n"NOR, this_object(), enemy);
                } else {
                    raiseDamage = 2000;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 500 ) damage = 350 + random(151);

                    if( enemy->query_stat_current("ap") > damage ) enemy->damage_stat("ap", damage, this_object());
                    else if( enemy->query_stat_current("ap") <= 0 ) enemy->set_stat_current("ap", 0);
                    else enemy->damage_stat("ap", enemy->query_stat_current("ap"), this_object());

                    for(i=0;i<4;i++) {
                        number += random(9);
                        if( i > 0 ) number += 1;
                        if( number > 36 ) number = random(36);
                        msg += point[number];
                        if( i < 3 ) msg += "�B";
                    }
                    message_vision( sprintf("$n�G�s�@�n�A���W"+msg+"���n�ި���$N�����A�Y�h�����A�믫�W���췥�j�������I(%d)\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                }
                cnd["name"] = HIW+"(CD)�I��"+NOR;
                cnd["duration"] = 5;

                this_object()->set_condition("fang_cd", cnd);
                break;
        }
    }
    return;
}

void to_do_say()
{
    if( query_condition("white_eyes") ) {
        message_vision(CYN"$N�]�������԰��ӱN�ղ����^�F�C\n"NOR, this_object());
        delete_condition("white_eyes");
    }
    if( query_condition("sky_palm_cd") ) {
        message_vision(CYN"$N�y�L���W�����𮧤F�@�U�A�`�N�O���G�����F�C\n"NOR, this_object());
        delete_condition("sky_palm_cd");
    } else {
        switch( random(70) ) {
            case 10..15:
                do_chat( ({
                   (: command, "say ���ެO���a�٬O�v�a�A���i�H���ܦۤv���H�͡C" :),
                   (: command, "say �O�x����H�M�������ڪ��D�F�o�I�C" :),
                   (: command, "say �ܼy����b���Ը���ѵ��x����H�C" :),
                }) );
                break;
            case 50..55:
                do_chat( ({
                   (: command, "say �O�@�츭���P��V�@�ڴN�O�ڪ��ϩR�C" :),
                   (: command, "say �{�b���ڤw�g�D�`�F�ѩM���P�o�I�F�C" :),
                }) );
                break;
        }
    }
    do_heal();
    return;
}

void create()
{
    set_name("��V�禸", ({ "night kid", "kid" }));
    set_race("human");
    set_level(50);
    set_class("superior");          // �W��
    set("classify", "strengthen");  // �j��
    set("camp", "muye");
    set("long", "�츭�̱j�a�ڤ�V�a�����a�A�֦��u�ղ��v�����~���ɡC�ߤ��R���F\n"
                "��v�a�H�����Ъ�����A�Q�n�N�v�a���������A�ҩ��ۤv����O����\n"
                "���v�a�C���]��H���E�y�A�禸�������к������ܤF�ݪk�C��V�禸\n"
                "�y�W���S�X�۫H���ˤl�A�Y�B�e���ۤ��˩үd�U���G�L...�C\n");

    set("nickname", HIG"���a"NOR);
    set("age", 16);
    set("gender", "male");

    // �@��ɰʧ@
    set("chat_chance", 10);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    // �԰��ɰʧ@
    set("chat_chance_combat", 30);
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
    set_train_with_camp("combat", 1, 1, 180, "muye", -2);              // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 140, "muye", -2);               // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 160, "muye", -2);               // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 140, "muye", -2);           // �������N
    set_train_with_camp("savage hit", 1, 5, 100, "muye", -2);          // �������N
    set_train_with_camp("continual hit", 1, 5, 160, "muye", -2);       // �s�����N
    set_train_with_camp("ninja", 1, 10, 140, "muye", -2);              // �ԳN
    set_train_with_camp("force", 1, 10, 160, "muye", -2);              // ��N
    set_train_with_camp("hundred palm", 0, 15, 160, "muye", -1);       // ��N�G�ʯP�x
    set_train_with_camp("white eyes", 0, 20, 120, "muye", 0);          // �ԳN�G�ղ�
    set_train_with_camp("soft fist", 1, 21, 140, "muye", -1);          // ��N�G�K�����Q�|�x

    setup();
    set_skill("force", 200);
    set_skill("hundred palm", 200);
    set_skill("white eyes", 200);
    set_skill("soft fist", 200);
    set_skill("sky palm", 200);
    set_skill("substitute", 200);
    map_skill("dodge", "substitute");

    add_temp("apply/exact", 150);        // �R��
    add_temp("apply/intimidate", 200);   // �����ޥ�
    add_temp("apply/attack", 100);       // ������O
    add_temp("apply/str", 30);
}

void die()
{
    object enemy, killer;
    int i = 25 + random(6);
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
    msg = HIG"\n�w�g�ɤO�F�A�o�٬O����"+enemy->query("name")+"...\n\n"HIR"���L���F�u�@�츭���A�o�I�Ʊ��O���ӭn�����a...\n\n"HIW"�N�����˷�쬰�F�u�@��V�v�a�@��...\n\n"NOR;
    msg += HIG"�i"HIR"�츭�ְT"HIG"�j"HIG"�츭����j�a�ڤ��@����V"NOR"�u���a�v"HIG+this_object()->query("name")+"�A�g�L�@�f�ľԤ���ѵ��F"+enemy->query("name")+"...\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

int accept_kill(object me, string arg)
{
    if( !query_condition("white_eyes") ) {
        message_vision("$N���D�R"HIG"�~�M�����ڡI�O�ӧ䦺�I\n"NOR, this_object());
        command("perform white eyes.open");
    } else {
        message_vision("$N���D�R"HIG"�o�����|��L$n�F�I\n"NOR, this_object(), me);
    }
}

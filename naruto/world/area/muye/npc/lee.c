#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;
inherit F_TRAINER;    // �V�m�ɮv

string *door = ({ HIW"�}��"NOR, HIR"���"NOR, HIC"�ͪ�"NOR, NOR+YEL"�˪�"NOR, 
                  HIG"����"NOR, HIB"����"NOR, HIK"����"NOR, REV"���"NOR });

int i = 0;

void do_fight()
{
    string msg;
    object enemy;
    int j, damage, raiseDamage;
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
    if( query_condition("soft_cd") ) return;
    if( is_busy() ) return;

    // �K���P�Ҷ}���ԭz�Τ@�b�o
    // �p���ثe��}�����A�T�줭�����i�H�ϥ��ؽ���
    if( (i == 1 || i > 3) && random(5) < 2 ) {
        set_temp("eight_pe", 1);
    } else if( i == 0 && random(10) > 6 ) {
        set_temp("lion_pe", 1);
    } else {
        if( i < 5 ) message_vision(HIR"\n$N���ⴤ���A�N�������d�J�Զ����b�P���j��..."NOR"\n$N���D�R"HIG"�K���P�� ��"HIY+chinese_number(i+1)+HIG"���E"+door[i]+HIG"�A�}�I�I\n\n"NOR, this_object());
    }
    if( i == 5 ) set_temp("eight_pe", 1);
    if( i > 3 && query_temp("eight_pe", 1) ) {
        j = i;
        if( i != 5 ) i = 5;
    }
    switch( i ) {
        case 0:  // �}�� - ���ءA��l�s�u
            if( !query_temp("lion_pe") ) {
                msg = HIG"�u��$N�B�Y�W�_�X�C���A������G�R���F�O�q�C\n\n"NOR;
            } else {
                raiseDamage = 500;
                add_temp("apply/attack", raiseDamage);
                message_vision("\n$N���D�R"HIG"��$n"HIG"�@�@�ګC�K���媺�F�`��\n", this_object(), enemy);
                message_vision(HIY"\n$N�ϥX�@��"HIG"�u�v�R���v"HIY"�N$n"HIY"��W�Ť��A���ۨϥX�s�������"NOR+YEL"�y�C�K�z�o�z\n"NOR, this_object(), enemy);
                for(j=0;j<4;j++) {
                    COMBAT_D->fight(this_object(), enemy, this_object());
                }
                add_temp("apply/attack", -raiseDamage);
                message_vision("\n", this_object());

                cnd["name"] = HIR+"(CD)�s�u"+NOR;
                cnd["duration"] = 5;

                set_condition("soft_cd", cnd);
                delete_temp("lion_pe");
            }
            break;
        case 1:  // ��� - �d�J�Ըɺ�
            if( !query_temp("eight_pe") ) {
                msg = HIG"$N���W�d�J�ԧt�q���H���`�֪��t�צ^�_���I\n\n"NOR;
                this_object()->set_stat_current("mp", query_stat_maximum("mp"));
            } else {
                message_vision("\n$N���M���[�ֳt�פ@�O"HIG"�u�v�R���v"NOR"�N$n��ܪŤ��A�������}�ަa�D�V$n�I\n"NOR, this_object(), enemy);
                if( !COMBAT_D->isHit(this_object(), enemy) ) {
                    message_vision("���O$n�b�Ť��@���ਭ�A�N�o�˶��Q�׶}�F$N����ŧ�C\n"NOR, this_object(), enemy);
                } else {
                    raiseDamage = 1000;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 400 ) damage = random(200) + 200;

                    enemy->receive_damage(damage, this_object());
                    message_vision( sprintf("$n�Q$N�c�c���"HIR"�y��E���ءz"NOR"�ֳt�q�Ť����V�a���A�N$n��������U�k�I(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                }
            }
            break;
        case 2:  // �ͪ�
            msg = HIG"$N���W�ҧt���d�J�Զq�w�g�W�X����s�q�A�}�l���X��~�y���ѷn�a�ʡI\n\n"NOR;
            break;
        case 3:  // �˪� - �[�t��O�^�_ (�ϥή��骺���Ƨl��buff)
            msg = HIG"���X��~���d�J�ԧֳt�]��$N���ˤf�A�~�M��$N��O���`�ֳt�^�_�I\n\n"NOR;

            cnd["name"] = HIR+"�K��-��"+NOR;
            cnd["duration"] = query_skill("eight shell", 1);
            cnd["hp"] = query_stat_maximum("hp")/50;

            set_condition("da", cnd);
            break;
        case 4:  // ���� - ���� evade
            msg = HIG"$N�b�d�J�Բ��`�W�Ȫ����p�U�A�s���v���ܪ������U�k...\n\n"NOR;
            add_temp("apply/evade", 300);
            break;
        default: // �P�_�ؽ��إ�
            message_vision("\n$N�ϥX"HIG"�u�v�R���v"NOR"�N$n���W�Ť��A���k���H�Y�Τ���^�a���$n�N$n�ԦV����ϥX"GRN+BLINK"�y�ءE���ءz"NOR"�I\n", this_object(), enemy);
            if( !COMBAT_D->isHit(this_object(), enemy) ) {
                message_vision("��$n���Z�O�w�O�N�^�a��H�A���\���L�F�����C\n"NOR, this_object(), enemy);
            } else {
                raiseDamage = 500*i;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 200*i ) damage = (50 + random(150))*i;

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("$N�N�d�J�ԽĦV$n���餺�A�O$n��Ŧ���ƨ����Y���������A�����g�ߤ]�]������@�P�ˮ`�I"NOR"(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            }
            break;
    }
    if( query_temp("eight_pe") ) {
        delete_temp("eight_pe");
        message_vision(HIR"\n�L�רϥΤK���P�ҷ|���ͭt�@�ΡA$N�����F�K���P�ҡC\n\n"NOR, this_object());
        if( i > 3 ) {
            add_temp("apply/evade", -300);
            delete_skill("sock power");
        }
        cnd["name"] = HIR+"(CD)�K��"+NOR;
        cnd["duration"] = j*4;
        i = 0;
        j = 0;

        set_condition("soft_cd", cnd);
        if( query_condition("da") ) delete_condition("da");
        start_busy(3);
    } else if( !query_condition("soft_cd") ) {
        message_vision(msg, this_object());
        i++;
        start_busy(3);
    }
    return;
}

void to_do_say()
{
    if( i > 0 || query_condition("soft_cd") ) {
        message_vision(CYN"$N�վA�ۤv������A���K���P�Ҫ��t�@�ή���̧C�C\n"NOR, this_object());
        delete_condition("soft_cd");
        if( i > 3 ) {
            add_temp("apply/evade", -300);
            delete_skill("sock power");
        }
        if( this_object()->query_condition("da") ) this_object()->delete_condition("da");
        i = 0;
    }
    switch( random(100) ) {
        case 0..5:
            do_chat( ({ (: command, "say �C�K�I�����I���\�I������b���" :) }) );
            break;
        case 20..25:
            do_chat( ({ (: command, "say ���\�O�C�K���L�O�I" :) }) );
            break;
        case 40..45:
            do_chat( ({ CYN"�p����M�w�b�a�W���_�F��a�����I\n"NOR, }) );
            break;
        case 60..65:
            do_chat( ({ CYN"�p����M�˥ߤF�_�ӡI\n"NOR, }) );
            break;
        case 80..85:
            do_chat( ({ CYN"�p��������M�o�G���D�G�и�ڥ橹�A�ڳo�@���l���|�O�@�A���I\n"NOR, }) );
            break;
    }
    do_heal();
}

void create()
{
    set_name("�����J", ({ "small lee", "lee" }));
    set_race("human");
    set_level(50);
    set_class("middle");            // ����
    set("classify", "strengthen");  // �j��
    set("camp", "muye");
    set("long", "�p���O�츭���̪��Ԫ̡A�O���ͦѮv���ǥ͡A�p���O����N����A��\n"
                "�o���|�ԳN�M�۳N�A�L���Vۣ�Y�M�@�����H�L���`��A�ѩ�L�̷P�E\n"
                "���ͦѮv�����ۡA�ҥH�q�v����A�˳�������ͦѮv���P�V�C\n");

    set("title", "����");
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
    set_train_with_camp("combat", 1, 1, 160, "muye", -2);              // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 140, "muye", -2);               // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 100, "muye", -2);               // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 140, "muye", -2);           // �������N
    set_train_with_camp("savage hit", 1, 5, 120, "muye", -2);          // �������N
    set_train_with_camp("continual hit", 1, 5, 140, "muye", -2);       // �s�����N
    set_train_with_camp("force", 1, 10, 180, "muye", -2);              // ��N
    set_train_with_camp("muye wind", 0, 15, 160, "muye", -1);          // ��N�G�줧���P��
    set_train_with_camp("muye cyclone", 1, 20, 140, "muye", 0);        // ��N�G�줧���ۭ�
    set_train_with_camp("eight shell", 0, 21, 60, "muye", 0);          // ��N�G�K���P��
    setup();
    set_skill("combat", 200);
    set_skill("heavy hit", 200);
    set_skill("continual hit", 200);
    set_skill("dodge", 200);
    set_skill("force", 200);
    set_skill("muye wind", 200);
    set_skill("muye cyclone", 200);
    set_skill("eight shell", 120);

    // ���[��O�A������O���I�t
    add_temp("apply/intimidate", 150);  // �����ޥ�
    add_temp("apply/wittiness", 50);    // ���m�ޥ�
    add_temp("apply/exact", 250);       // �R����O
    add_temp("apply/str", 20);
    add_temp("apply/con", 10);
}

void relay_say(object ob, string arg)
{
    if( arg == "����" || arg == "���ͦѮv") {
        command("giggle");
        do_chat(({
            (: command, "say ���ͦѮv�O�ڳ̷q�����Ѯv�F�C" :),
            (: command, "say �L�ɱ`���y�M���ߪ��оɧڭ̡A�ڳ̷P�E���ͦѮv���u�ۡC" :),
            "���ۻ��ۡA�p����M���_�F��a�����A�u�O����I\n",
        }));
    }
}

void die()
{
    object enemy, killer;
    int i = 20 + random(11);
    string msg;

    enemy = this_object()->last_damage_giver();

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
    msg = HIW"\n�٨S���ѹ禸...�٨S������쵪�����ͦѮv�����@�I\n\n"HIG"������b�o�̴N�Q���ѡI�o�˴��g���ѦA���_�ӤS������N�q�O�I\n\n"NOR;
    msg += HIG"�i"HIR"�츭�ְT"HIG"�j"HIG"�֦��츭��N�T�ޡu"HIY"�K���P��"HIG"�v�ǩӪ��Ԫ�"+this_object()->query("name")+"�A�~�M�Q"+enemy->query("name")+HIG"�����ѤF...\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

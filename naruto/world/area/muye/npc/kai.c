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
    // ���ͥثe��}����
    if( (i == 1 || i == 3) && random(5) < 2 ) {
        set_temp("eight_pe", 1);
    } else {
        if( i < 6 ) message_vision(HIR"\n$N���ⴤ���A�N�������d�J�Զ����b�P���j��..."NOR"\n$N���D�R"HIG"�K���P�� ��"HIY+chinese_number(i+1)+HIG"���E"+door[i]+HIG"�A�}�I�I\n\n"NOR, this_object());
    }
    switch( i ) {
        case 0:  // �}�� - ����
            msg = HIG"�u��$N�B�Y�W�_�X�C���A������G�R���F�O�q�C\n\n"NOR;
            break;
        case 1:  // ��� - �d�J�Ըɺ�
            if( !query_temp("eight_pe") ) {
                msg = HIG"$N���W�d�J�ԧt�q���H���`�֪��t�צ^�_���I\n\n"NOR;
                this_object()->set_stat_current("mp", query_stat_maximum("mp"));
            } else {
                message_vision("\n$N���M���[�ֳt�פ@�O�u"YEL"����L"NOR"�v�N$n��ܪŤ��A�������}�ަa�D�V$n�I\n"NOR, this_object(), enemy);
                if( !COMBAT_D->isHit(this_object(), enemy) ) {
                    message_vision("���O$n�b�Ť��@���ਭ�A�N�o�˶��Q�׶}�F$N����ŧ�C\n"NOR, this_object(), enemy);
                } else {
                    raiseDamage = 1200;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 600 ) damage = random(200) + 400;

                    enemy->receive_damage(damage, this_object());
                    message_vision( sprintf("$n�Q$N�c�c���"HIR"�y��E���ءz"NOR"�ֳt�q�Ť����V�a���A�N$n��������U�k�I(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                }
            }
            break;
        case 2:  // �ͪ� - �ؽ���
            msg = HIG"$N���W�ҧt���d�J�Զq�w�g�W�X����s�q�A�}�l���X��~�y���ѷn�a�ʡI\n\n"NOR;
            break;
        case 3:  // �˪� - �[�t��O�^�_ (�ϥή��骺���Ƨl��buff)
            if( !query_temp("eight_pe") ) {
                msg = HIG"���X��~���d�J�ԧֳt�]��$N���ˤf�A�~�M��$N��O���`�ֳt�^�_�I\n\n"NOR;

                cnd["name"] = HIR+"�K��-��"+NOR;
                cnd["duration"] = query_skill("eight shell", 1);
                cnd["hp"] = query_stat_maximum("hp")/50;

                set_condition("da", cnd);
            } else {
                message_vision(HIG"\n$N�η��֪��t�׹�$n"HIG"�y����X�Ƹ}�A�k�x�@���N$n"HIG"���V�Ť��I"NOR"\n����$n�|�����쳻�I���ڡA$N����w�g���E�F�K���P�ҩ����񪺹L�h�d�J��"GRN+BLINK"�y�ءE���ءz"NOR"�I\n\n", this_object(), enemy);
                if( !COMBAT_D->isHit(this_object(), enemy) ) {
                    message_vision("��$n�����a���V�����áA���\�N�o�۪������ˮ`�ಾ�b�Ů𤤡C\n"NOR, this_object(), enemy);
                } else {
                    raiseDamage = 2000;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 800 ) damage = random(300) + 500;

                    enemy->receive_damage(damage, this_object());
                    message_vision( sprintf(HIY"�|�P�ǥX�j�P�������i�A�s���Y��쳣�Q�����A�Q����������$n"HIY"��O�������ˡI"NOR"(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                }
            }
            break;
        case 4:  // ���� - ���� evade
            msg = HIG"$N�b�d�J�Բ��`�W�Ȫ����p�U�A�s���v���ܪ������U�k...\n\n"NOR;
            add_temp("apply/evade", 300);
            break;
        case 5:  // ���� - �����P�R�@�����v
            msg = HIG"$N�z�q�@�n�A�w�g������餺���_�A�����d�J�ԡA�ש�Ԥ���X��F�I\n\n"NOR;
            set_skill("sock power", 100);
            break;
        case 6:  // �¤ճ�
            set_temp("eight_pe", 1);

            raiseDamage = 400;

            add_temp("apply/attack", raiseDamage);
            set_skill("sock power", 200);
            message_vision(HIR"\n$N�����Q�X�������d�J�ԨϥX����"RED"�y"NOR+BRED+BLINK"�¤ճ�"NOR+HIR"�z���������a��$n�����W�۩I�I�I\n\n"NOR, this_object(), enemy);

            for(j=0;j<7;j++) {
                COMBAT_D->fight(this_object(), enemy, this_object());
                if( enemy->query_stat_current("hp") <= 100 ) {
                    j = 9;
                    message_vision(HIR"\n$n"HIR"�w�g������F�A", this_object(), enemy);
                }
            }
            if( j != 10 ) message_vision("\n", this_object());
            set_skill("sock power", 100);
            add_temp("apply/attack", -raiseDamage);
            message_vision(HIR"$N�N��հ��F�U�ӡI\n", this_object());
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
        cnd["duration"] = i*4;
        i = 0;

        set_condition("soft_cd", cnd);
        if( query_condition("da") ) delete_condition("da");
    } else {
        message_vision(msg, this_object());
        i++;
    }
    start_busy(3);
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
        case 0..10:
            do_chat( ({ 
                (: command, "say �����k�l�~�N�O�n����I" :),
            }) );
            break;
        case 20..30:
            do_chat( ({ 
                (: command, "say �ӧa�I��ۧڤ@�_�R�ʡI" :),
            }) );
            break;
        case 40..50:
            do_chat( ({ 
                CYN"���ͤ�X�k��j�i���A��ժ������G���@�{�A���H�L�k����.\n"NOR,
            }) );
            break;
        case 60..70:
            do_chat( ({ 
                (: command, "say �o�N�O�C�K���I" :),
            }) );
            break;
    }
    do_heal();
}

void create()
{
    set_name("����", ({ "kai" }));
    set_race("human");
    set_level(70);
    set_class("superior");          // �W��
    set("classify", "strengthen");  // �j��
    set("title", "���������O");
    set("camp", "muye");
    set("long", "���ͬO�츭��������~�l�A�]�O���d�d�謰�Ī���N����I�L���Vۣ\n"
                "�Y�M�@�ܥO�H�L���`��I\n");

    set("age", 26);
    set("gender", "male");

    set("chat_chance", 10);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    set("chat_chance_combat", 25);
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
    set_train_with_camp("combat", 1, 1, 200, "muye", -2);              // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 200, "muye", -2);               // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 180, "muye", -2);               // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 200, "muye", -2);           // �������N
    set_train_with_camp("savage hit", 1, 5, 200, "muye", -2);          // �������N
    set_train_with_camp("continual hit", 1, 5, 180, "muye", -2);       // �s�����N
    set_train_with_camp("ninja", 1, 10, 160, "muye", -2);              // �ԳN
    set_train_with_camp("force", 1, 10, 200, "muye", -2);              // ��N
    set_train_with_camp("muye wind", 0, 15, 160, "muye", -1);          // ��N�G�줧���P��
    set_train_with_camp("muye cyclone", 0, 20, 140, "muye", 0);        // ��N�G�줧���ۭ�
    set_train_with_camp("eight shell", 1, 21, 200, "muye", 0);         // ��N�G�K���P��

    setup();
    set_skill("ninja", 170);
    set_skill("force", 200);
    set_skill("muye wind", 200);
    set_skill("muye cyclone", 200);
    set_skill("eight shell", 200);
    set_skill("substitute", 200);
    map_skill("dodge", "substitute");

    // ���[��O�A������O���I�t
    add_temp("apply/intimidate", 200);  // �����ޥ�
    add_temp("apply/exact", 250);       // �R����O
    add_temp("apply/evade", 200);       // �j�ׯ�O
    add_temp("apply/str", 15);
    add_temp("apply/con", 15);
}

void die()
{
    object enemy, killer;
    int i = 60 + random(16);
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
    msg = HIR"\n"+this_object()->query("name")+"�L���y��a�b���b�a�W���_�j�i����V"+enemy->query("name")+"���D�G\n"HIG"�y�S�Q��"+enemy->rank()+"�]���o����媺�å�I�G�M���b�o�ӥ@�ɤW�N�O�n������I�I�z\n\n"HIY"�p���I�Ѯv�����@�B�F�I���Ө�ڳo�A�ЧA��Ӯ𪺷s�ۦ��a�I\n\n"NOR;
    msg += HIG"�i"HIR"�츭�ְT"HIG"�j"HIG"�츭�@�y��N����"NOR+RED"�u����ۢϢ�I�v"HIG"�Юv"+this_object()->query("name")+"�Q�N�Ū�"+enemy->query("name")+HIG"���ѤF�C\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

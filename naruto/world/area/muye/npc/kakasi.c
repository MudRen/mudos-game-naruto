#include <npc.h>
#include <ansi.h>

inherit F_TRAINER;    // �V�m�Ԫ�

int bird = 0;

void do_fight()
{
    object *targets;
    object enemy;
    int damage, raiseDamage, ntar, i, exact, evade;
    mapping cnd = ([]);

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
    switch ( random(6) ) {
        case 0:  // ���P-�����y���N
            if( query_condition("ghost_cd") ) break;
            add_temp("apply/exact", 200);
            message_vision("\n$N�}�l�ֳt���L�A���۱N�Ů�l�J�f��"HIW"�y"NOR+RED"���P"NOR"-"HIR"�����y���N"HIW"�z"NOR"�R�X�@�Τ��y�Q�V$n�I\n"NOR, this_object(), enemy);
            if( !COMBAT_D->isHit(this_object(), enemy) ) {
                message_vision("���y�F���@�n�����b�@�Ǫ���a�W�A�N�����a�N���@����C\n\n"NOR, this_object(), enemy);
            } else {
                raiseDamage = 900;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 300 ) damage = random(200) + 100;

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("���y�����b$n�����W�����������}�ӡA�������ˤF$n�A�٨�$n���W�U�N�F�_��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);

                if( !enemy->query_condition("firedamage") ) {
                    cnd["name"] = HIR+"�ۤ����A"+NOR;
                    cnd["duration"] = 15;
                    cnd["from"] = this_object();

                    enemy->set_condition("firedamage", cnd);
                }
                cnd["name"] = RED+"(CD)���P"+NOR;
                cnd["duration"] = 3;

                this_object()->set_condition("ghost_cd", cnd);
            }
            add_temp("apply/exact", -200); 
            break;
        case 1:  // ���P-�j�r�����N
            if( query_condition("tiger_cd") ) break;
            exact = COMBAT_D->intimidate(this_object(), 1)*1.2;

            message_vision("\n$N���F�X�ӦL�۹D"HIW"�y"NOR+BLU"���P"NOR"-"HIC"�j�r�����N"HIW"�z"NOR"�q$N�������M�ĥX�@�D�����A�N�Ѫ�Ţ�n�@�����¡I\n"NOR, this_object(), enemy);
            for(i=0;i<ntar;i++) {
                evade = COMBAT_D->wittiness(targets[i], 1);
                if( !COMBAT_D->SkillHit(this_object(), targets[i], exact, evade) ) {
                    if( userp(targets[i]) ) tell_object(targets[i], HIY"(���m���\) "NOR);
                    raiseDamage = 0;
                } else {
                    if( userp(targets[i]) ) tell_object(targets[i], HIR"(���m����) "NOR);
                    raiseDamage = 700;
                }
                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 100 ) damage = 80 + random(21);

                message_vision( sprintf("�����q�Ť����ĦӨӡA�ڥ��L�q�{�סA�u��a�ۤv�����m�w�צ���(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            }
            cnd["name"] = BLU+"(CD)���P"+NOR;
            cnd["duration"] = 4;

            this_object()->set_condition("tiger_cd", cnd);
            message_vision("\n"NOR, this_object());
            break;
        case 2:  // �g�P-�ߤ��٭��N
            if( query_condition("age_cd") ) break;
            exact = COMBAT_D->intimidate(this_object(), 1);
            evade = COMBAT_D->wittiness(enemy, 1);

            message_vision("\n$N���M����C���L�t�׵��X"HIW"�y"NOR+YEL"�g�P"NOR"-"HIY"�ߤ��٭��N"HIW"�z"NOR"���L�A�y�W�S�X�`���i�����L��...\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("���O$n�èS���惡���X����欰�A$N�u�n�n�n�Y�ĤF�@�f��C\n\n"NOR, this_object(), enemy);
            } else {
                message_vision("$n�H�������i�X�o�ʧ����A�o���F�����N�A�Q$N�Զi�g���u���Y���~�S�ʼu���o�I\n\n"NOR, this_object(), enemy);
                enemy->start_busy(5);
            }
            cnd["name"] = YEL+"(CD)�g�P"+NOR;
            cnd["duration"] = 8;

            this_object()->set_condition("age_cd", cnd);
            start_busy(2);
            break;
        case 3:  // �p�P-�d��
            if( query_condition("lion_cd") ) break;
            if( bird < 3 ) {
                message_vision(HIC"\b$N�k��}�l���E���K�ת��d�J�ԡA�����D�Q������...\n"NOR, this_object(), enemy);
                bird += 1;
                break;
            }
            add_temp("apply/exact", 300);
            message_vision(HIC"\b\n$N�N���E�b�k��W���d�J�ԡA�o�X���p�d������s������"HIK+BLINK"�y"HIY"�p�P"NOR+BLINK"-"HIW"�d��"HIK"�z"NOR+HIC"����$n"HIC"�I\n"NOR, this_object(), enemy);
            if( !COMBAT_D->isHit(this_object(), enemy) ) {
                message_vision("���G$n�{�}�F�d���������I�ӧ��������@�Ǿ�F��X�j�P�q�y�A�s$n���Pı���l�³ª��C\n\n"NOR, this_object(), enemy);
                enemy->start_busy(1);
            } else {
                raiseDamage = 5500;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 1200 ) damage = random(800) + 400;

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("�j�P���p���������$n������A$n�u�Pı���e�@�աA�s�F��ֳQ�q�y�����F(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                enemy->start_busy(2);

                if( enemy->query_stat_current("hp") > 100 ) {
                    remove_killer(enemy);
                    enemy->remove_killer(this_object());
                    enemy->unconcious();
                }
            }
            add_temp("apply/exact", -300);
            cnd["name"] = HIY+"(CD)�p�P"+NOR;
            cnd["duration"] = 10;

            this_object()->set_condition("lion_cd", cnd);
            bird = 0;
            start_busy(2);
            break;
        case 4:  // ���P-���B�u���N
            if( query_condition("tiger_cd") ) break;
            message_vision("\n$N�s�򵲤F�X�ӦL�I�i�X"HIW"�y"NOR+BLU"���P"NOR"-"HIB"���B�u���N"HIW"�z"NOR"�@�����j�����u�V���s���D�V$n�I\n"NOR, this_object(), enemy);
            if( !COMBAT_D->isHit(this_object(), enemy) ) {
                message_vision("�S����$n�����B�u�n�����b�������A�b��a�W�q�_�@�}�����N�����F�C\n\n"NOR, this_object(), enemy);
            } else {
                raiseDamage = 1600;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 600 ) damage = random(400) + 200;

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("���B�u�N$n�����F�X�h�A���O�����O�o�̵M����A�@���N$n�ĤW�Q�ذ��Ť~�v���Y�a(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            }
            cnd["name"] = BLU+"(CD)���P"+NOR;
            cnd["duration"] = 6;

            this_object()->set_condition("tiger_cd", cnd);
            break;
        case 5:  // �d�~��
            add_temp("apply/exact", 400);
            command("say �츭��N���q�I");
            command("perform thousand year kill.attack on " + enemy->query_id() );
            add_temp("apply/exact", -400);
            break;
    }
    return;
}

void to_do_say()
{
    if( bird != 0 ) {
        message_vision(HIY"$N�i�v�v�a�N��W�E�����d�J�Ԧ��^�C\n"NOR, this_object());
        bird = 0;
    }
    do_heal();
    return;
}

void create()
{
    set_name("�X��d�d��", ({ "ka ka si", "si" }));
    set_race("human");
    set_level(70);
    set_class("superior");          // �W��
    set("classify", "strengthen");  // �j��
    set("long", "�d�d��O�츭�Ԫ̧��̪��W�ԡA�O�Ѥ~�Ԫ̤츭�դ��u�X��ҭZ�v����l\n"
                "�A�@�Y���Ⱦv�M�e�i�������O�L���S��C�D�t���i�@�ڪ��L�o�֦��g����\n"
                "�A�]����o�����Ԫ̪����W�A���b��I��o���@�q�����H�����L�h�C\n"
                "�����Y�����Ԫ��Ѥ~���Ԫ̡A�������g�����A���t�����g���A������d��\n"
                "�H�W�ԳN�A�Q�٬��츭�Ĥ@�ޮv�C\n"
                "================================ ��q�N(mother) & �h��(kaien) ==\n" );

    set("title", "�����Ԫ�");
    set("age", 26);
    set("gender", "male");
    set("camp", "muye");
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    set("chat_chance", 10);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    // �]�w�Ԫ̧��A�ۦP���Ԫ̧��~�|��
    set("guild", "muye");
    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 180, "muye", -2);             // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 200, "muye", 0);               // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 200, "muye", 0);               // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 180, "muye", -1);          // �������N
    set_train_with_camp("savage hit", 1, 5, 180, "muye", -1);         // �������N
    set_train_with_camp("continual hit", 1, 5, 200, "muye", -1);      // �s�����N
    set_train_with_camp("force", 1, 10, 180, "muye", -1);             // ��N
    set_train_with_camp("ninja", 1, 10, 200, "muye", 0);              // �ԳN
    set_train_with_camp("alter ego", 0, 15, 160, "muye", -1);         // �ԳN�G�����N
    set_train_with_camp("thousand year kill", 0, 21, 140, "muye", 0); // ��N�G�d�~��

    setup();
    set_skill("ninja", 200);
    set_skill("force", 200);
    set_skill("thousand year kill", 200);
    set_skill("substitute", 200);
    map_skill("dodge", "substitute");

    add_temp("apply/armor", 100);       // ���m��O
    add_temp("apply/intimidate", 100);  // �����ޥ�
    add_temp("apply/wittiness", 150);   // ���m�ޥ�
    add_temp("apply/exact", 150);       // �R����O
    add_temp("apply/evade", 150);       // �R����O
    add_temp("apply/str", 15);
    add_temp("apply/dex", 15);
}

// ��char��say���O�ɡA��mob���^��
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "�d�~��" ) {
        if( me->query("guild") != "muye") {
            message_vision("$N���D�R"HIG"�d�~���O�츭��N���q�A$n�o�ӧ��~�H�N�O�ݨ���h�F�C\n"NOR, this_object(), me);
            return 1;
        }
        if( me->query_skill("thousand year kill") ) {
            message_vision("$N���D�R"HIG"��ӬO�O$n�A�p��H�d�~���n�ζܡH\n"NOR, this_object(), me);
            return 1;
        }
        if( !me->query_temp("learn_thousand") ) {
            message_vision("$N���D�R"HIG"$n�Q�Ǥd�~���H���i�S����e���ڡC\n"NOR, this_object(), me);
            message_vision("$N���D�R"HIG"�����p���u"NOR+YEL"�˼��Ѱ�"HIG"�v���X�ӲӸ`�ڦ��I�O���M�F...\n"NOR, this_object(), me);
            message_vision("$N���D�R"HIG"�h�ˤ@���L�����ڬݬݧa�C\n"NOR, this_object(), me);
            me->set_temp("learn_thousand", 1);
        } else {
            message_vision("$N���$n���D�R"HIG"�ڭn���p���O�H$n���Q�Ǥd�~���աH\n"NOR, this_object(), me);
        }
    }
    return 1;
}

int accept_object(object me, object item)
{
    if( !objectp(me) || !objectp(item) ) return 0;
    if( !me->query_temp("learn_thousand") ) return 0;
    if( !item->id("_KISS_") ) return 0;

    message_vision("$N���D�R"HIG"�˼��Ѱ󮳨ӤF�ܡH���������I\n"NOR, this_object(), me);
    message_vision("��M����$n����F$N����A�ϥX�@��"HIW"�u"HIR"�d�~��"HIW"�v"NOR"��$N�������������J�I�I\n", me, this_object());
    me->set_skill("thousand year kill", 1);
    me->delete_temp("learn_thousand");
    do_chat( ({ 
        (: command, "say �d�~�����ޥ��O��F�ܡH�z����..." :),
        (: command, "gy si":),
        (: destruct, item :),
    }) );
    return 1;
}

void die()
{
    object enemy, killer;
    int i = 55 + random(16);
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
    msg = HIW"\n�@�h�O�H�_�媺�����ǹM�U�j�Ԫ̧�...\n\n"HIG"�b�@���p���W��"+enemy->rank()+enemy->query("name")+"�A�~�M�����e���츭�����D��"+this_object()->query("name")+"\n\n"HIR"�b�s�f�԰�����A"+this_object()->query("name")+"�]�ϥΦ�����L�ׯh�Ҧ����i�X\n\n"HIW"�Q"+enemy->query("name")+"���_�r�𤧤U�ש�Ө�����ˮ`�]���ӱѰ}�U�ӡI\n\n"NOR;
    msg += HIG"�i"HIR"�츭�ְT"HIG"�j"HIG"��"HIW"�y"HIR"�����Ԫ�"HIW"�z"HIG"���٪�"+this_object()->query("name")+"�A�~�M�Q"+enemy->query("name")+"�����ѡA�u�O���H�����۫H�I\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

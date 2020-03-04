#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    object enemy, area;
    int damage, raiseDamage, exact, evade;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // �߿ߪG��-�\���A�A�w�g�ιL�~�Χޯ�
    if( !query("fruit_cat", 1) ) {
        message_vision(CYN"\n$N�ϥΰʪ��t�y"HIY"�߿ߪG��"NOR"�w"BLINK+HIR"�\���A"NOR+CYN"�z���ĪG�A�C�C�ܤƦ��F�y�\�I\n\n"NOR, this_object());

        set_skill("sock power", 50);              // �s�ޯ�A�M���ΨӴ����P�R���v�Amob�M��
        set_skill("sock bom", 50);                // �s�ޯ�A�M���ΨӴ����P�R�ˮ`�Amob�M��
        set_skill("body iron", 200);              // �W�[�K���o�ʲv
        add_temp("apply/wittiness", 150);         // ���m��O
        add_temp("apply/intimidate", 200);        // ������O
        add_temp("apply/exact", 100);             // �R��
        add_temp("apply/evade", 150);             // �j��
        set("name", "ù�����_"HIR"[�\���A]"NOR);  // �W�r�ץ�

        message_vision("$N���D�R"HIG"�u���ʪ��t���G��A�~��N�ڪ���O����e�{�I\n"NOR, this_object(), enemy);
        set("fruit_cat", 1);
        return;
    }
    switch( random(2) ) {
        case 0: // ���j�E��
            exact = COMBAT_D->intimidate(this_object(), 1);
            evade = COMBAT_D->wittiness(enemy, 1);

            message_vision("\n$N"HIY"���X�k��A�����P��������@���A�u�X���p�l�u�몺"YEL"�u���j�E"BLINK"��"NOR+YEL"�v\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision(HIB"$N"HIB"���W�B�Ϋl�D�N���j���ץ����A�b������X�@�Ӽu�աC\n\n"NOR, enemy);
                start_busy(2);
            } else {
                raiseDamage = 1100;
                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);
                enemy->receive_damage(damage, this_object());
                message_vision( sprintf(RED"$n"NOR+RED"�Q���j�����A���W�e��F�@�ӹ��u�կ몺�ˮ`�I�y�夣��(%d) %s\n\n"NOR, damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            }
            break;
        case 1: // �\��
            if( query("fruit_cat", 1) && !enemy->is_busy() ) {
                exact = COMBAT_D->exact(this_object(), enemy, 1)/2;

                add_temp("apply/exact", exact);
                message_vision("\n$N"HIY"�ϥX"HIW"�u�c�M�v"HIY"�ε۶W�V�c���t�ת����Ĩ�$n"HIY"���e�A���ϥΰ\������$n"HIY"�I\n"NOR, this_object(), enemy);
                if( !COMBAT_D->isHit(this_object(), enemy) ) {
                    message_vision(HIK"$n"HIK"�ߨ�L�t�O�����|�P�A�O"NOR"$N"HIK"�L�k�a��C\n\n"NOR, this_object(), enemy);
                    enemy->start_busy(1);
                } else {
                    message_vision(YEL"$N"NOR+YEL"�Ӥ��ΰk���A�Q�\�����_�A�L�k��ʤF�I\n\n"NOR, enemy);
                    enemy->start_busy(5);
                }
                add_temp("apply/exact", -exact);
                break;
            }
        default: // �����j
            if( query("fruit_cat", 1) && enemy->is_busy() ) {
                message_vision("\n\n$N���D�R"HIG"�u���N���������m�췥�P���H�A�~��ϥΪ��̱j�ۦ�...\n\n"NOR, this_object());
                message_vision("$N"HIK"�X��$n"HIK"�L�k��ʤ��Y�A�H�̧֪��t�רϥX"HIC"[��B]"HIW"[�c]"HIK"�ֳt����$n\n"HIK"�N�b��H�Z���@�u���j�ɡA"NOR"$N"HIK"���X������$n"HIK"�ݤf�A�o�ʶ��q\n\n\t\t"HIM"�y "NOR+RED+BLINK"���@"HIR"���@"NOR+WHT+BLINK"�j "NOR+HIM"�z\n\n"NOR, this_object(), enemy);
                raiseDamage = 5000;
                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);
                enemy->receive_damage(damage, this_object());
                message_vision( sprintf(HIR"²�檺�����o�X��"HIY"[���j]"HIR"�٭n�j�l����z�O�B��"HIB"[�P�}]"HIR"�ٱj���}�a�O�B��l���p"HIW"[�K��]"HIR"�B\n�o�S��"NOR+CYN"[��ø]"HIR"��b�餺�|�B�y«�A�����F$n�L�i��m���Y���ˮ`�I(%d) %s\n\n"NOR, damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                start_busy(1);
                enemy->start_busy(2);
            }
            break;
    }
    return;
}
void check_fruit()
{
    // �S�b�԰��n�^�_���H��
    if( query("fruit_cat", 1) ) {
        set("name", "ù�����_");              // �W�r�ץ�
        message_vision(CYN"$N�@�����y���ܦ^�F�H���C\n"NOR, this_object());
        delete("fruit_cat");
        delete_skill("sock power");
        delete_skill("sock bom");
        set_skill("body iron", 180);          // ����K���o�ʲv
        add_temp("apply/wittiness", -150);    // ���m��O
        add_temp("apply/intimidate", -200);   // ������O
        add_temp("apply/exact", -100);        // �R��
        add_temp("apply/evade", -150);        // �j��
    }
    delete_condition("fb_busy");              // �M����ø�Z���N�o
    do_heal();
    return;
}
void create()
{
    set_name("ù�����_", ({ "lu ji", "lu", "ji" }) );
    set_race("human");
    set_level(80);
    set_class("general_sea");       // ���x��N
    set("classify", "strengthen");  // �j��
    set("age", 28);
    set("title", HIR"�Ѣޢ�"NOR);
    set("long", "�y�W���L���A�Q�٬��N�Ū����H�����A���x�ҳ����c�Ѣޢ����̱j\n"
                "�����uù���E���_�v�C�ھڮ��L�������ǡA�����F���J��@�󤭦ʦW\n"
                "���x�h�L�Q�j����ΫR�����ƥ�A��ɬF���X�G�Ҽ{�n�V����Χ뭰\n"
                "�ɡA���X�F�~�ȤQ�T�������_��J�����a�A�����F���x���ʦW���R\n"
                "���A�æb������Y�K��������U�F����Ϊ����Y�A�����F�o�Өƥ�C\n"
                "����M���x�ޯ�i���۾ǲߡA�Q�� train ���O�ӦV���_�ǲߧޯ�C\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    set("chat_chance", 20);
    set("chat_msg", ({
        (: check_fruit :),
    }) );
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    // ��h���x�٬O����èS���v�T
    set("guild", "piece");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 200, "police", -2);              // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 180, "police", -2);               // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 180, "police", -2);               // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 200, "police", -2);           // �������N
    set_train_with_camp("savage hit", 1, 5, 180, "police", -2);          // �������N
    set_train_with_camp("continual hit", 1, 5, 180, "police", -2);       // �s�����N
    set_train_with_camp("martial", 1, 10, 200, "police", -2);            // �Z�N��¦
    set_train_with_camp("gun finger", 1, 15, 180, "police", 1);          // �Z�N�G���j
    set_train_with_camp("gun ban", 0, 20, 140, "police", 0);             // �Z�N�G���j�E��
    set_train_with_camp("gun gentian", 0, 40, 80, "police", 2);         // �Z�N�G���j�E����
    set_train_with_camp("fight body", 1, 15, 160, "police", 0);          // �Z�N�G��ø�Z��

    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":10+random(11), "p1":100, "p2":100 ]),   // ����
        ([ "type":"eq", "id":10, "amount":1, "p1":90, "p2":100 ]),                 // ���m
    }) );
    setup();
    set_skill("combat", 200);
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 200);
    set_skill("continual hit", 200);
    set_skill("martial", 200);
    set_skill("gun finger", 200);
    set_skill("gun ban", 200);
    set_skill("gun gentian", 200);
    set_skill("fight body",200);
    set_skill("body iron", 180);
    set_skill("paper step", 160);

    add_temp("apply/exact", 100);       // �R��
    add_temp("apply/evade", 100);       // �j��
    add_temp("apply/intimidate", 200);  // �����ޥ�
    add_temp("apply/wittiness", 100);   // ���m�ޥ�
    add_temp("apply/str", 40);
    add_temp("apply/dex", 10);

    carry_object(__DIR__"eq/pants.c")->wear();
    carry_object(__DIR__"eq/suit.c")->wear();
}
int accept_kill(object me, string arg)
{
    if( this_object()->query_condition("fb_busy", 1) == 0) {
        message_vision("$N���D�R"HIG"�~�M���ʤ�A�䦺�C\n"NOR, this_object());
        command("perform fight body.check");
    } else {
        message_vision("$N���D�R"HIG"�Q���N�����A�C\n"NOR, this_object());
    }
}
int accept_fight(object me, string arg)
{
    do_chat( ({
        (: command, "say ...." :),
        (: command, "say �����Ȧb���O�ӷo�áC" :),
    }) );
    return 0;
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 135 + random(16);

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
    msg = "\n\n"HIR"�@�ɬF����ĵ���T�_�I�U��x���h�L�|�B�b���A���G�b�ǻ�����T���I\n���M�|��ǨӤF�@�}��H����q�n�I�~�M�O"NOR+YEL"�԰ꤸ��"HIR"�b�ʫ�F�I\n\n"NOR+YEL"�԰ꤸ��"NOR"�G"HIG"����"+enemy->query("name")+"�O������Y�I�H����H"HIY+enemy->rank()+HIG"�I�H\n"NOR+YEL"�԰ꤸ��"NOR"�G"HIG"�~�M�����ѢѢޢ��������y���⪺ù�����_�I�H"NOR"\n\n"HIR"�u��"NOR+YEL"�԰ꤸ��"HIR"�ߨ�{���s���R�O�A���U�a�����x�����`�N"+enemy->query("name")+"�o���H��...\n���O���x�̳��ߩȩ�"+enemy->query("name")+"����O�A�ڥ����������o���s�k�O...\n\n"NOR;
    msg += HIB"�i�@�ɬF���j"+enemy->query("name")+"("+enemy->query("id")+")���ѤF�֦�"HIK"�u�·t�����q�v"HIB"�ٸ���"+this_object()->query("name")+HIB"("+this_object()->query("id")+")�w�g�ǹM�@�ɦU�a�F�C\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����ù�����_��o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

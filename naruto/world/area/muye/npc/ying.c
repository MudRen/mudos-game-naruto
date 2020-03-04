#include <npc.h>
#include <ansi.h>

inherit F_TRAINER;         // �V�m�Ԫ�

void do_fight()
{
    mapping buff, cnd_data;
    string cnd;
    object enemy;
    int damage, raiseDamage, exact, evade;

    // �S���ĤH
    enemy = this_object()->query_opponent();
    buff = query_all_conditions();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( random(4) ) {
        case 0:  // �ӭM����
            if( !query_condition("ca2") ) {
                command("perform cell activation.ca");
                break;
            }
        case 1:  // �v¡�N
            if( !query_condition("heal_buff") ) {
                command("perform heal buff.heal");
                break;
            }
        case 2:  // �ǤO
            exact = COMBAT_D->exact(this_object(), enemy, 1) + COMBAT_D->wittiness(this_object(), 1);
            evade = COMBAT_D->evade(enemy, this_object(), 1) + COMBAT_D->intimidate(enemy, 1);

            message_vision(HIM"\n$N�B�������ԳN����d�J�Ԫ��ޥ��A�N�Ҧ��O�q�����b����"HIW"�y�ǤO�z"HIM"�@����$n"HIM"�{�h�I\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("$n���y�宣�a�ݵۤ@�ǳQ$N���������j���۸H���A�y���٦n�S�����C\n\n"NOR, this_object(), enemy);
                start_busy(5);
            } else {
                raiseDamage = 1200;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 600 ) damage = random(100) + 500;

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("�b��������$N���P�ɡA�j�j���d�J�Աq�餺�z�}�A�y���D�`�Y�����ж�(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                start_busy(3);
            }
            break;
        case 3:  // buff �Ѱ�
            if( !buff ) break;
            message_vision(HIG"\n$N���⾮�E�X��⪺�d�J�ԡA�}�l�ˬd�ۤv���馳�L���`�g��...\n"NOR, this_object());
            foreach(cnd, cnd_data in buff) {
                if( cnd != "ca" && cnd != "ca2" && cnd != "heal_buff" ) {
                    message_vision("$N�b�԰��������եX���ġA�Ѱ��F "+cnd_data["name"]+" �����}���A�C\n"NOR, this_object());
                    delete_condition(cnd);
                    set_temp("delete_buff", 1);
                }
            }
            if( !query_temp("delete_buff") ) message_vision(CYN"$N�õL�o�{���W�����󪬪p�C\n\n"NOR, this_object());
            else {
                message_vision(CYN"$N�N���餣�}���A���h���F�C\n\n"NOR, this_object());
                delete_temp("delete_buff");
            }
            break;
    }
    return;
}

void to_do_say()
{
    if( query_stat("hp") < query_stat_maximum("hp") && !query_condition("ca2") ) command("perform cell activation.ca");
    else if ( !query_condition("heal_buff") ) command("perform heal buff.heal");

    do_heal();
    return;
}

void create()
{
    set_name("�K����", ({ "ying" }));
    set_race("human");
    set_level(50);
    set("gender", "female");
    set_class("middle");            // ����
    set("classify", "strengthen");  // �j��
    set("camp", "muye");
    set("long", "����ê���O�s�d�d��]�{�P�C�b�d�J�Ԫ��ո`�B�۳N�~��B����\n"
                "�Ҹծɪ��O�ФO���U�譱�A�����S�X�~�ءA�N�Ӫ���O�i�ण�b��\n"
                "�U���U�C\n");

    set("age", 16);

    set("chat_chance", 10);
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
    set_train_with_camp("dodge", 1, 1, 120, "muye", -2);               // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 120, "muye", -2);               // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 120, "muye", -2);           // �������N
    set_train_with_camp("savage hit", 1, 5, 180, "muye", -2);          // �������N
    set_train_with_camp("continual hit", 1, 5, 120, "muye", -2);       // �s�����N
    set_train_with_camp("ninja", 1, 10, 160, "muye", -2);              // �ԳN
    set_train_with_camp("cell activation", 0, 15, 160, "muye", -1);    // �ԳN�G�ӭM����
    set_train_with_camp("heal buff", 0, 20, 120, "muye", 0);           // �ԳN�G�v¡�N
    set_train_with_camp("hand heal", 1, 21, 140, "muye", 0);           // �ԳN�G�x�P�N

    setup();
    set_skill("combat", 200);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 200);
    set_skill("continual hit", 140);
    set_skill("ninja", 180);
    set_skill("cell activation", 200);
    set_skill("heal buff", 200);
    set_skill("substitute", 200);
    map_skill("dodge", "substitute");

    add_temp("apply/attack", 150);      // ������O
    add_temp("apply/wittiness", 150);   // ���m��O
    add_temp("apply/exact", 150);       // �R����O
    add_temp("apply/int", 30);
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
    // �d��������D�H��
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = HIM"\n����Ѯv...�d�d��Ѯv...���U...��H...\n\n���M���Z���ڷQ�l�W�O�H���}�B...�����Y���G�w�g��F...\n\n"NOR;
    msg += HIG"�i"HIR"�츭�ְT"HIG"�j"HIG"�Ĥ��N���v���⪺�����Ԫ̧̤l"+this_object()->query("name")+"�A�Q�ݧԪ�"+enemy->query("name")+"�������F�C\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

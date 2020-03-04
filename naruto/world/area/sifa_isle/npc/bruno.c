#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    object enemy;
    int exact;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // ����O�֩�@�w�q�A�|�ΪŮ���O�]
    if( query_stat_current("hp") <= query_stat_maximum("hp")/3 ) {
        message_vision(CYN"\n$N�o�{�ۤv�Ĥ��L$n���}�a�O�A�ߨ�o��"NOR+GRN"�y�����G��z"NOR+CYN"�S���O"HIC"�u�Ů���v"NOR+CYN"���]�F�C\n\n"NOR, this_object(), enemy);
        if( !this_object()->move(_DIR_AREA_"sifa_isle/door.c") ) {
            message_vision(CYN"���O�Q$n�ݬ�F�A���W�o�ʧ�������$N�k���C\n"NOR, this_object(), enemy);
            return;
        }
        this_object()->set("door_ok", 1);
        return;
    }
    // ���P�_���S���ιL�K����A�S�ιL�N���ϥ�
    // �j�۪��P�_�p�G����٦b busy�A�@�˨ϥ��K���H
    if( this_object()->query_condition("gang_busy", 1) != 0) {
        switch( random(2) ) {
            case 0: // �ޯ�1: �����G��-�j�۪�
                if( !enemy->is_busy() ) {
                    exact = COMBAT_D->exact(this_object(), enemy, 1)/5;

                    add_temp("apply/exact", exact);
                    message_vision(CYN"\n$N�b�Ť��ϥX"HIW"�u��B�v"NOR+CYN"�H���֪��t�ײ���"NOR"$n"CYN"����A����Ĳ�I"NOR"$n"CYN"���y���C\n"NOR, this_object(), enemy);
                    if( COMBAT_D->isHit(this_object(), enemy) ) {
                        message_vision(GRN"�y�����G��-"NOR+REV"�j�۪�"NOR+GRN"�z"NOR"$n���������M��������뤣����ʡA�Y������I\n\n"NOR, this_object(), enemy);
                        enemy->start_busy(5);
                    } else {
                        message_vision("���O$n�@���l�N�{�}�F$N��Ĳ�N�C\n\n"NOR, this_object(), enemy);
                    }
                    add_temp("apply/exact", -exact);
                    break;
                }
            case 1: // �ޯ�2: �K���H
                command("perform body sui.attack on " + enemy->query_id());
                break;
        }
        return;
    }
    command("perform body gang.defence");
    return;
}
void check_hp()
{
    // �^�姹���۰ʦ^���Τl��
    if( query("door_ok", 1) ) {
        if( query_stat_current("hp") >= query_stat_maximum("hp") ) {
            if( !this_object()->move(_DIR_AREA_"sifa_isle/house1.c") ) return;
            message_vision(CYN"$N���G�N���骬�A�^�_�����A�q"HIC"�u�Ů���v"NOR+CYN"�����F�X�ӡC\n"NOR, this_object());
            delete("door_ok");
        }
    }
    // ���K�N�K���誺�N�o�ɶ��]���h
    if( query_condition("gang_busy") ) this_object()->delete_condition("gang_busy");

    // �w���L���^��...�h�]�@��
    heal_stat("ap", query_stat_maximum("ap"));
    heal_stat("hp", query_stat_maximum("hp")/10);
    heal_stat("mp", query_stat_maximum("mp"));
    return;
}
void create()
{
    set_name("���|��", ({ "bruno" }) );
    set_race("human");
    set_level(60);
    set_class("guard_sea");         // ���x�ս�
    set("classify", "strengthen");  // �j��
    set("age", 31);
    set("title", HIR"�Ѣޢ�"NOR);
    set("long", "�ܰ������k�H�A�Y�v���G���Τ���S�O���v���A�ު��������@�ˡC�L\n"
                "�b�Τl�̤��ɪ��հs�A��z�d�x�A�n���@�Ӱs�a����C\n"
                "����M���x�ޯ�i���۾ǲߡA�Q�� train ���O�ӦV���|�վǲߧޯ�C\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    set("chat_chance", 20);
    set("chat_msg", ({
        (: check_hp :),
    }) );
    set("chat_chance_combat", 50);
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
    set_train_with_camp("combat", 1, 1, 180, "police", -2);           // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 120, "police", -2);            // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 200, "police", -2);            // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 180, "police", -2);        // �������N
    set_train_with_camp("savage hit", 1, 5, 140, "police", -2);       // �������N
    set_train_with_camp("continual hit", 1, 5, 120, "police", -2);    // �s�����N
    set_train_with_camp("body iron", 1, 15, 200, "police", -1);       // �K��
    set_train_with_camp("body gang", 0, 20, 140, "police", 0);        // �S��G�K���E��
    set_train_with_camp("body sui", 0, 21, 140, "police", 0);         // �S��G�K���E�H

    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":10+random(15), "p1":100, "p2":100 ]),   // ����
        ([ "type":"eq", "id":21, "amount":1, "p1":80, "p2":100 ]),                 // ����M
        ([ "type":"eq", "id":31, "amount":1, "p1":70, "p2":100 ]),                 // �R���U
    }) );
    setup();
    set_skill("combat", 180);
    set_skill("dodge", 180);
    set_skill("parry", 200);
    set_skill("heavy hit", 180);
    set_skill("savage hit", 140);
    set_skill("continual hit", 120);
    set_skill("body sui", 200);
    set_skill("body gang", 200);
    set_skill("body iron", 200);
    set_skill("paper step", 120);

    add_temp("apply/exact", 50);       // �R��
    add_temp("apply/evade", 50);       // �j��
    add_temp("apply/intimidate", 50);  // ������O
    add_temp("apply/wittiness", 200);  // ���m��O
    add_temp("apply/con", 30);

    carry_object(__DIR__"eq/pants.c")->wear();
    carry_object(__DIR__"eq/suit.c")->wear();
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 25 + random(6);

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
    msg = "\n\n"HIW+this_object()->query("name")+"���i�m�H�a�R�q�G�o���i�઺�I�̱j���K�����|�Q���ѡI"NOR"\n\n"NOR;
    msg += HIB"�i�@�ɬF���j�Ѣޢ��u�����v����"+this_object()->query("name")+"("+this_object()->query("id")+")�~�M�Q"+enemy->query("name")+"("+enemy->query("id")+")�����F�I\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A�������|����o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

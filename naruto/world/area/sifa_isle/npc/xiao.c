#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    object enemy;
    int i;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( random(3) ) {
        case 0: // �~�Y�E���å�
            add_temp("apply/attack", 300);
            message_vision(HIC"\n$N"HIC"�N���u�����A�H���j���t�׳s��ϥX"HIR"�y"HIY"�~�Y"NOR"�E"HIK"$N�å�"HIR"�z"HIC"����$n"HIC"�I\n\n"NOR, this_object(), enemy);
            for(i=0;i<4;i++) {
                COMBAT_D->fight(this_object(), enemy, this_object());
            }
            message_vision(HIC"\n$N�����F�����I\n\n"NOR, this_object(), enemy);
            add_temp("apply/attack", -300);
            start_busy(4);
            break;
        default: // �K���y
            command("perform body ball.atwirl on " + enemy->query_id() );
            break;
    }
}
void do_say()
{
    // �ӧn�F �����v�A�C�@�I
    if( random(100) < 1 ) {
        do_chat( ({ 
            (: command, "say �ڵ��藍�|�i�D�A�A�o��Ӿ����వ���򪺡I��z�z�I" :),
            (: command, "say ���O���}�q���K�a�������I��z�z�I" :),
            (: command, "say ........" :),
            (: command, "say �S���ȼL�F�I��z�z�I" :),
            (: command, "say �ϥ�����Ĺ�ڡI�O�Q�ʾ����I��z�z�I" :),
        }) );
    }
    do_heal();
}
void create()
{
    set_name("��", ({ "xiao", "_XIAO_" }) );
    set_race("human");
    set_level(60);
    set_class("guard_sea");         // ���x�ս�
    set("classify", "strengthen");  // �j��
    set("age", 18);
    set("title", HIR"�Ѣޢ�"NOR);
    set("long", "������u�u�A�L�ڤW�٦����媺�ͪ��A�L�ʷʤ����a���ۥL�O���x�S\n"
                "��ҳ����΢Ѣޢ��������A�W�r�s�@���A�]������ϥΤ��������c�A\n"
                "�๳���Y�N�@��b�t�B��ŧ�ĤH�C\n"
                "����M���x�ޯ�i���۾ǲߡA�Q�� train ���O�ӦV���ǲߧޯ�C\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    // �@��ɰʧ@
    set("chat_chance", 20);
    set("chat_msg", ({
        (: do_say :),
    }) );
    set("chat_chance_combat", 25);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    // �ܩ��h���x�٬O����èS���v�T
    set("guild", "piece");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 120, "police", -2);            // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 200, "police", -2);             // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 100, "police", -2);             // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 140, "police", -2);         // �������N
    set_train_with_camp("savage hit", 1, 5, 130, "police", -2);        // �������N
    set_train_with_camp("continual hit", 1, 5, 150, "police", -2);     // �s�����N
    set_train_with_camp("martial", 1, 10, 160, "police", -1);          // �Z�N��¦
    set_train_with_camp("animal yan", 0, 25, 120, "police", 1);        // �Z�N�G�~�Y
    set_train_with_camp("paper step", 1, 15, 200, "police", 0);        // �S��G��ø
    set_train_with_camp("paper slime", 0, 20, 140, "police", 0);       // �S��G��ø�E�n�d
    set_train_with_camp("body ball", 0, 40, 100, "police", 2);         // �S��G�K���y

    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":10+random(11), "p1":100, "p2":100 ]),   // ����
        ([ "type":"eq", "id":17, "amount":1, "p1":50, "p2":100 ]),                 // ����u
    }) );
    setup();
    set_skill("combat", 120);
    set_skill("dodge", 200);
    set_skill("parry", 100);
    set_skill("heavy hit", 140);
    set_skill("savage hit", 130);
    set_skill("continual hit", 150);
    set_skill("martial", 200);
    set_skill("animal yan", 200);
    set_skill("body ball", 200);
    set_skill("paper slime", 200);
    set_skill("gun finger", 180);
    set_skill("body iron", 180);
    set_skill("paper step", 200);

    add_temp("apply/exact", 100);       // �R��
    add_temp("apply/evade", 100);       // �j��
    add_temp("apply/intimidate", 50);   // ������O
    add_temp("apply/wittiness", 50);    // ���m��O
    add_temp("apply/dex", 30);

    carry_object(__DIR__"eq/pants.c")->wear();
    carry_object(__DIR__"eq/suit.c")->wear();
}
int accept_kill(object me, string arg)
{
    if( !this_object()->query_condition("slime", 1) ) {
        message_vision("$N���D�R"HIG"�ݧڪ���ø�E�n�d�I��z�z�I\n"NOR, this_object());
        command("perform paper slime.mud");
    } else {
        message_vision("$N���D�R"HIG"��z�z�I\n"NOR, this_object());
    }
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 20 + random(11);

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
    msg = "\n\n"GRN+this_object()->query("name")+"���L�a�s�ۡG��z�z�I�ڵL�n�����~�M�|�ѵ�"+enemy->query("name")+"���\n\n"NOR;
    msg += HIB"�i�@�ɬF���j�Ѣޢ��u�����v����"+this_object()->query("name")+"("+this_object()->query("id")+")�~�M�Q"+enemy->query("name")+"("+enemy->query("id")+")�����F�I\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A��������o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

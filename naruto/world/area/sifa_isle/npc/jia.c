#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    object enemy;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // �����G��-�T���A�A�w�g�ιL�~�Ωt�T
    if( !query("fruit_wolf", 1) ) {
        message_vision(CYN"\n$N�ϥΰʪ��t�y"HIK"�����G��"NOR"�w"BLINK+HIK"�T���A"NOR+CYN"�z���ĪG�A�j�Ʀ��T���F�I\n\n"NOR, this_object());

        set_skill("sock power", 100);           // �s�ޯ�A�M���ΨӴ����P�R���v�Amob�M��
        set_skill("body iron", 200);            // �W�[�K���o�ʲv
        add_temp("apply/intimidate", 200);      // ������O
        add_temp("apply/wittiness", 150);       // ���m��O
        add_temp("apply/evade", 100);           // �j��
        add_temp("apply/exact", 150);           // �R��
        set("name", "�륬��"HIK"[�T���A]"NOR);  // �W�r�ץ�

        message_vision("$N�T�z��D�G"HIG"�������I��$n"HIG"���D���K�����k���u���¤O�I�������I\n"NOR, this_object(), enemy);
        set("fruit_wolf", 1);
        set("chat_chance_combat", 50);          // �W�[�ϥΧޯ���v
        return;
    }
    // �P�}�E�t�T
    command("perform kick wolf.kick on " + enemy->query_id() );
    return;
}
void check_fruit()
{
    // �S�b�԰��n�^�_���H��
    if( query("fruit_wolf", 1) ) {
        set("name", "�륬��");                   // �W�r�ץ�
        message_vision(CYN"$N���ݨS�H���Z�A�S��_���H�����Y�N�ΤF�C\n"NOR, this_object());
        delete("fruit_wolf");
        delete_skill("sock power");              // �s�ޯ�A�M���ΨӴ����P�R���v�Amob�M��
        set_skill("body iron", 160);             // ����K���o�ʲv
        add_temp("apply/intimidate", -200);      // ������O
        add_temp("apply/wittiness", -150);       // ���m��O
        add_temp("apply/evade", -100);           // �j��
        add_temp("apply/exact", -150);           // �R��
    }
    do_heal();
    return;
}
void create()
{
    set_name("�륬��", ({ "jia bu la", "jia", "bu", "la", "_JIA_" }) );
    set_race("human");
    set_level(70);
    set_class("guard_sea");         // ���x�ս�
    set("classify", "strengthen");  // �j��
    set("age", 25);
    set("title", HIR"�Ѣޢ�"NOR);
    set("long", "��ۦ��I��������Z�N�a�A�u���L�L�᪺���b�a�W��ı�A�@�I����\n"
                "����\�b���䪺���U�|�Q�H�����C�~�M�ٺΨ��l�W�j�X�F�@�Ӥj\n"
                "�w�w�A���ӬO�����εۤF�a�A�Q�������U�ܡH\n"
                "����M���x�ޯ�i���۾ǲߡA�Q�� train ���O�ӦV�륬�Ծǲߧޯ�C\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    set("chat_chance", 20);
    set("chat_msg", ({
        (: check_fruit :),
    }) );
    // �۰ʧީ~�h�A���C��ʧިϥ�
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    // �����L�`�����оǫK�[�J���������
    // �ܩ��h���x�٬O����èS���v�T
    set("guild", "piece");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 180, "police", -2);           // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 160, "police", -2);            // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 160, "police", -2);            // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 160, "police", -2);        // �������N
    set_train_with_camp("savage hit", 1, 5, 200, "police", -2);       // �������N
    set_train_with_camp("continual hit", 1, 5, 140, "police", -2);    // �s�����N
    set_train_with_camp("martial", 1, 10, 180, "police", -2);         // �Z�N��¦
    set_train_with_camp("spurn", 1, 10, 180, "police", -2);           // ��ް�¦
    set_train_with_camp("body iron", 1, 15, 140, "police", 0);        // �K��
    set_train_with_camp("gun finger", 1, 15, 160, "police", -1);      // �Z�N�G���j
    set_train_with_camp("gun ten", 0, 35, 100, "police", 2);          // �Z�N�G�Q���j
    set_train_with_camp("kick wolf", 0, 20, 140, "police", 0);        // ��ޡG�P�}�E�t�T
    set_train_with_camp("body skill", 0, 40, 80, "police", 2);       // �S��G�K�����k

    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":10+random(11), "p1":100, "p2":100 ]),   // ����
        ([ "type":"eq", "id":57, "amount":1, "p1":80, "p2":100 ]),                 // �T�}
        ([ "type":"eq", "id":59, "amount":1, "p1":80, "p2":100 ]),                 // �T�}
        ([ "type":"eq", "id":61, "amount":1, "p1":90, "p2":100 ]),                 // �T��
    }) );
    setup();
    set_skill("combat", 180);
    set_skill("dodge", 160);
    set_skill("parry", 160);
    set_skill("heavy hit", 160);
    set_skill("savage hit", 200);
    set_skill("continual hit", 140);
    set_skill("martial", 200);
    set_skill("spurn", 200);
    set_skill("kick wolf", 200);
    set_skill("gun finger", 200);
    set_skill("kick haze", 200);
    set_skill("gun ten", 200);
    set_skill("body skill", 200);
    set_skill("body iron", 160);
    set_skill("paper step", 150);

    add_temp("apply/evade", 50);        // �j��
    add_temp("apply/intimidate", 150);  // ������O
    add_temp("apply/wittiness", 150);   // ���m��O
    add_temp("apply/str", 25);
    add_temp("apply/con", 15);

    carry_object(__DIR__"eq/pants.c")->wear();
    carry_object(__DIR__"eq/suit.c")->wear();
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 60 + random(11);

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
    msg = "\n\n"HIK+this_object()->query("name")+HIK"�f�R�ժj�˦b�a�W�w���F�L�h...\n\n"+enemy->query("name")+"��۷ϳ��ۻy�G�j���T�٬O�h�F�p���U�a...�ڥi�O"HIR+enemy->rank()+HIK"�I\n\n"NOR;
    msg += HIB"�i�@�ɬF���j�Ѣޢ��u�����v����"+this_object()->query("name")+HIB"("+this_object()->query("id")+")�~�M�Q"+enemy->query("name")+"("+enemy->query("id")+")�����F�I\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A�����륬����o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

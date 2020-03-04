#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    mapping cnd = ([]), weapons;
    object enemy, ob;
    object* targets;
    string skill;
    int i;

    // �S���ĤH
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision(CYN"\n$N�\�X���H�����A�A������i������A"HIW"�զ�w�j"NOR+CYN"�к������A�ݰ_�ӫD�`���H�C\n\n"NOR, this_object());

    cnd["name"] = HIW"(�w�j)"NOR;
    cnd["duration"] = 1;

    // ������H�ƶW�L��H��θs���
    // �ĪG���Z��H���A�ҥH��h�H�R���C
    // ���H�h�O�@�w��
    if( sizeof(targets) >= 2 ) {
        message_vision(NOR"�w�w�U�ӷU�h�A�N$N��ӤH�]�Цb�䤤�Φ�"HIW"�y�Ψm�ϡz"NOR"\n$N�ϥ�"HIM"�y�w�w�G��z"NOR"��O����w�j�ϥX"HIC"�u�϶��j���S�v"NOR"�w�j�ĦV$n���H�I\n\n"NOR, this_object(), enemy);
        for(i=0;i<sizeof(targets);i++) {
            if( targets[i]->query_condition("golden_bubble", 1) ) continue;
            if( !COMBAT_D->isHit(this_object(), targets[i]) ) {
                message_vision(HIC"���O$N"HIC"�ߨ��}�F���S�A�S���Q�w�j�ҧ]���C\n"NOR, targets[i]);
            } else {
                message_vision(HIW"$N"HIW"�Q���S�]�S�A�����ܪ����`���ơI�s��������í�F�I\n"NOR, targets[i]);
                if( mapp(weapons = targets[i]->query_temp("weapon")) && sizeof(weapons) ) {
                    foreach(skill, ob in weapons) ob->unequip();
                }
                targets[i]->set("no_defend", 1);      // ���ਾ�m
                targets[i]->set("no_combat", 1);      // �������
                targets[i]->set_condition("golden_bubble", cnd);
                tell_object(targets[i], HIY"(�A�����ӹL���Ʃ~�M�s��������í�^�b�a�W�A�Z���]�L�k�ϥΤF)\n"NOR);
            }
        }
        message_vision("\n\n"NOR, this_object());
    } else {
        // �w�g���F�N���ΦA��F
        if( enemy->query_condition("golden_bubble", 1) ) return;

        message_vision(HIB"$N��X"HIC"�P�}"HIB"�z�Z$n"HIB"��ʡA�H�Y��"HIC"�u�c�v"HIB"����$n"HIB"����I\n"HIY"�y�����w�j�z"HIW"$N���X���⤣���i��$n"HIW"������A$n"HIW"�������G�U�ӷU���ơI\n"NOR, this_object(), enemy);
        if( mapp(weapons = enemy->query_temp("weapon")) && sizeof(weapons) ) {
            foreach(skill, ob in weapons) ob->unequip();
        }
        enemy->set("no_defend", 1);      // ���ਾ�m
        enemy->set("no_combat", 1);      // �������
        enemy->set_condition("golden_bubble", cnd);
        tell_object(enemy, HIY"(�A�����ӹL���Ʃ~�M�s��������í�^�b�a�W�A�Z���]�L�k�ϥΤF)\n\n"NOR);
    }
    return;
}
void create()
{
    set_name("�d���k", ({ "ka li fa", "fa", "_KALIFA_" }) );
    set_race("human");
    set_level(55);
    set("gender", "female");
    set_class("guard_sea");         // ���x�ս�
    set("classify", "strengthen");  // �j��
    set("age", 24);
    set("title", HIR"�Ѣޢ�"NOR);
    set("long", "�����ܧ��v���k�l�A���y�������b�Ȥl�W�ܵ۬����A�o���G������\n"
                "���w�k���p���A���ӬO�@�ӹ�����Ʊ����l�D�������k�ʧa�C\n"
                "����M���x�ޯ�i���۾ǲߡA�Q�� train ���O�ӦV�d���k�ǲߧޯ�C\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    set("chat_chance", 20);
    set("chat_msg", ({
        (: do_heal :),
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
    set_train_with_camp("combat", 1, 1, 140, "police", -2);           // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 160, "police", -2);            // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 140, "police", -2);            // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 120, "police", -2);        // �������N
    set_train_with_camp("savage hit", 1, 5, 120, "police", -2);       // �������N
    set_train_with_camp("continual hit", 1, 5, 180, "police", -2);    // �s�����N
    set_train_with_camp("martial", 1, 10, 140, "police", -1);         // �Z�N��¦
    set_train_with_camp("activity", 1, 10, 160, "police", -1);        // �S���¦
    set_train_with_camp("gun finger", 1, 15, 120, "police", -1);      // �Z�N�G���j
    set_train_with_camp("gun whip", 1, 15, 160, "police", -1);        // �Z�N�G���j�E�@
    set_train_with_camp("briar suffuse", 0, 40, 80, "police", 2);    // �S��G��Ƥ���

    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":10+random(16), "p1":100, "p2":100 ]),   // ����
        ([ "type":"eq", "id":45, "amount":1, "p1":90, "p2":100 ]),                 // �y���@��
        ([ "type":"eq", "id":5, "amount":1, "p1":95, "p2":100 ]),                  // ÷�l
    }) );
    setup();
    set_skill("combat", 150);
    set_skill("dodge", 160);
    set_skill("parry", 140);
    set_skill("heavy hit", 130);
    set_skill("savage hit", 120);
    set_skill("continual hit", 200);
    set_skill("martial", 200);
    set_skill("gun finger", 200);
    set_skill("briar suffuse", 200);
    set_skill("gun whip", 200);
    set_skill("body iron", 120);
    set_skill("paper step", 160);

    add_temp("apply/evade", 120);        // �j��
    add_temp("apply/intimidate", 50);    // ������O
    add_temp("apply/wittiness", 80);     // ���m��O
    add_temp("apply/int", 20);
    add_temp("apply/dex", 10);

    carry_object(__DIR__"eq/pants.c")->wear();
    carry_object(__DIR__"eq/suit.c")->wear();
}
// ��char��say���O�ɡA��mob���^��
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;
    message_vision("$N���D�R"HIG"�o�O�ʷk�Z�C\n"NOR, this_object());
    return 1;
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 15 + random(11);

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
    msg = "\n\n"HIC+this_object()->query("name")+"�@�y��Y�a���G�ڬO�w�w�G���O�̡I���|��I�o�O�����Z�I\n\n"NOR;
    msg += HIB"�i�@�ɬF���j�Ѣޢ��u�����v����"+this_object()->query("name")+"("+this_object()->query("id")+")�~�M�Q"+enemy->query("name")+"("+enemy->query("id")+")�����F�I\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A�����d���k��o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

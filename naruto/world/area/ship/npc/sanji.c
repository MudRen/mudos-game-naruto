#include <npc.h>
#include <ansi.h>

inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    object enemy;
    object* targets;
    int i, damage, raiseDamage, exact, evade;

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
    // ������H�ƶW�L��H��θs���
    if( sizeof(targets) >= 2 ) {
        exact = COMBAT_D->exact(this_object(), enemy, 1)/2 + COMBAT_D->evade(this_object(), enemy, 1)*3/4;

        message_vision("\n$N��"HIY"������"NOR"�K�F�_�ӫ�D�D�G"HIG"�o�s�����W�x���å�A���A�̪��D����s�\��§���I\n\n"NOR, this_object());
        message_vision(YEL"�u��$N���⼵�a��}�¤ѡA�s������ֳt�p��"NOR"�y"BYEL"�H���\��§������"NOR"�z"YEL"�I\n"NOR, this_object());
        for(i=0;i<sizeof(targets);i++) {
            if( !userp(targets[i]) ) {
                message_vision(HIY"$N�@�}����$n���y���A$n�s�F�@�n�H�Y�w���L�h�C\n"NOR, this_object(), targets[i]);
                remove_killer(targets[i]);
                targets[i]->unconcious();
            } else {
                evade = COMBAT_D->exact(targets[i], this_object(), 1);

                if( !COMBAT_D->SkillHit(this_object(), targets[i], exact, evade) ) {
                    message_vision(HIY"$N���֦a��$n�s���X�T�L�A���O���Q$n���ư{�L�F�C\n"NOR, this_object(), targets[i]);
                    this_object()->start_busy(1);
                } else {
                    raiseDamage = 1000;
                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                    add_temp("apply/attack", -raiseDamage);
                    targets[i]->receive_damage(damage, this_object());
                    message_vision( sprintf(HIY"$N�@�}�𤤤F$n���y���A�h��$n�����X�ܨ�(%d) %s\n"NOR, damage, COMBAT_D->report_status(targets[i]) ), this_object(), targets[i]);
                    targets[i]->start_busy(1);
                }
            }
        }
    message_vision(YEL"\n$N���^�F��աI\n\n"NOR, this_object());
    } else {
        // �ʸH
        command("perform shatter kick.attack on " + enemy->query_id() );
    }
    return;
}
void check_diabo()
{
    delete_condition("diabo_busy");  // �M���c�]���}���N�o
    do_heal();
    return;
}
void create()
{
    set_name("���N�h", ({ "sanji" }) );
    set_race("human");
    set_level(60);
    set_class("reward_sea");        // �a�����
    set("classify", "strengthen");  // �j��
    set("age", 18);
    set("title", HIK"�p�v"NOR);
    set("long", "�@�ⰵ�檺�n�\�ҡA��U����θ̤H�H�����g�C���L�L�i�O�D�W�@\n"
                "�ɪ��j����w���}�������{�̡A���F����\�ҡA��ޤ]�Q���F�o�A\n"
                "�b��U����Τ��]���O�L�H�C\n"
                "����M���x�ޯ�i���۾ǲߡA�Q�� train ���O�ӦV���N�h�ǲߧޯ�\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    set("chat_chance", 30);
    set("chat_msg", ({
        (: check_diabo :),
    }) );
    set("chat_chance_combat", 25);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    // �����L���N�h���оǫK�[�J���������
    // �ܩ��h���x�٬O����èS���v�T
    set("guild", "piece");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 140, "robber", -2);             // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 200, "robber", -2);              // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 160, "robber", -2);              // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 200, "robber", -2);          // �������N
    set_train_with_camp("savage hit", 1, 5, 160, "robber", -2);         // �������N
    set_train_with_camp("continual hit", 1, 5, 140, "robber", -2);      // �s�����N
    set_train_with_camp("spurn", 1, 10, 200, "robber", -2);             // ��ް�¦
    set_train_with_camp("outfit kick", 1, 15, 160, "robber", -1);       // ��ޡG��ޥ��\
    set_train_with_camp("fried cold cuts", 1, 15, 140, "robber", -1);   // ��ޡG�o�����A���L
    set_train_with_camp("change face shot", 1, 21, 140, "robber", -1);  // ��ޡG�㫬��֢ݢ�
    set_train_with_camp("diabolically foot", 0, 20, 120, "robber", 0);  // ��ޡG�c�]���}
    set_train_with_camp("shatter kick", 0, 40, 100, "robber", 2);       // ��ޡG�ʸH

    set("set_drop", ({
        ([ "type":"eq", "id":117, "amount":1, "p1":1, "p2":900 ]),      // ���Y�־c
        ([ "type":"eq", "id":24, "amount":1, "p1":100, "p2":100 ]),     // ��l
    }) );
    setup();
    set_skill("combat", 180);
    set_skill("dodge", 180);
    set_skill("parry", 180);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 200);
    set_skill("continual hit", 160);
    set_skill("spurn", 200);
    set_skill("outfit kick", 200);
    set_skill("fried cold cuts", 200);
    set_skill("change face shot", 200);
    set_skill("diabolically foot", 200);
    set_skill("shatter kick", 200);

    add_temp("apply/exact", 100);       // �R��
    add_temp("apply/evade", 150);       // �j��
    add_temp("apply/intimidate", 150);  // ������O
    add_temp("apply/wittiness", 100);   // ���m��O
    add_temp("apply/dex", 15);
    add_temp("apply/str", 15);

    carry_object(__DIR__"eq/shoes.c")->wear();
}
int accept_kill(object me, string arg)
{
    if( me->query("gender") == "female" ) {
        do_chat( ({
            (: command, "shake" :),
        }) );
        me->remove_killer(this_object());
        return 1;
    }         
    if( this_object()->query_condition("diabo_busy", 1) == 0) {
        command("perform diabolically foot.atwirl");
        message_vision("���N�h���D�R"HIG"�t�Գt�M�I�Ի~�F�R���M�pù�����Y���ɶ��ڥi���ǧA�C\n"NOR, this_object());
    } else {
        message_vision("���N�h���D�R"HIG"���a�F�ں�߻s�@�������i���ǧA�I\n"NOR, this_object());
    }
}
int accept_fight(object me, string arg)
{
    if( me->query("gender") == "female" ) {
        do_chat( ({
            (: command, "shake" :),
            (: command, "say ��ݤk�h���i�H�o�ˡC" :),
            (: command, "say �o���H�ڪ��M�h�D�믫�C" :),
        }) );
        return 0;
    }   
    do_chat( ({
        (: command, "shake" :),
        (: command, "say �S�ݨ�ڦb���۰���ܡI" :),
    }) );
    return 0;
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 70 + random(11);

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
    msg = "\n\n"YEL"\t���N�h"HIK"���b�a�W�ε۳̫�@�f�𻡹D�G"NOR"\n\n\t"HIB"�y���F���Ů���...����b�o�ɭԴN�ˤU...�I�z"NOR"\n\n\t"HIK"���O"NOR+YEL"���N�h"HIK"�ϺɤF�̫᪺�O�q�٬O�L�k�Գӹ��"HIK"..."HIW"\n\n\t��U����μp�v"HIK"�u�¨��v"NOR+YEL"���N�h"HIW"�A�Q"HIR+enemy->query("name")+HIW"�����F�I"NOR"\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A�������N�h��o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

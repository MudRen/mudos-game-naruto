#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    object enemy;
    int damage, raiseDamage , inti, i, exact, evade;

    // �S���ĤH
    enemy = this_object()->query_opponent();
    inti = COMBAT_D->intimidate(this_object(), 1);

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( (this_object()->query_stat_current("hp") < this_object()->query_stat_maximum("hp")/8)
        && !this_object()->query_condition("da") ) {
        command("perform digest absorb.check");
        return;
    }
    switch( random(3)+1 ) {
        case 1: // �P�}�E����
            command("perform kick lotus.kick on " + enemy->query_id() );
            break;
        case 2: // ��v����
            command("perform hair bind.tie on " + enemy->query_id() );
            break;
        case 3: // ���j�E��
            exact = inti + COMBAT_D->intimidate(this_object(), 1)/2;
            evade = COMBAT_D->wittiness(enemy, 1);

            message_vision("\n$N���D�R"HIG"������I�h�E���E�u�I\n\n"NOR, this_object());
            message_vision(HIR"$N�k���|�_"NOR+YEL"�I��"HIR"�A���⭹����������_$n"HIR"��m�A"HIM"�u���j�E�ߡv"HIR"�I����L��骽��$n"HIR"�I\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("���G�Q$N�{�L�F�A"NOR+YEL"�I��"NOR"�u�I�v�a�@�n�A�u�b�a�W��X�@�Ӭ}�C\n\n"NOR, enemy);
                start_busy(1);
            } else {
                raiseDamage = 700;
                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/righthand"));
                add_temp("apply/attack", -raiseDamage);
                enemy->receive_damage(damage, this_object());
                message_vision( sprintf(HIY"$n"HIY"�Q�w����"NOR+YEL"�I��"HIY"�뤤�A�o���O�Q�M�C��鶴��@�˼Q�X��ӡI(%d) %s\n"NOR, damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                // �����ᦳ�i��A�l�[�|���A�@���R����@���C
                for(i=0;i<4;i++) {
                    inti = inti/2;
                    exact = inti + COMBAT_D->intimidate(this_object(), 1)/2;

                    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                        message_vision("$N�S�b�P�@�a�I�ϥX"HIM"�u�ߡv"NOR"���O�Q"NOR"$n"NOR"�{�L�F�A���U�F��աC\n\n"NOR, this_object(), enemy);
                        return;
                        break;
                    } else {
                        raiseDamage = 550;
                        add_temp("apply/attack", raiseDamage); 
                        damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/righthand"));
                        add_temp("apply/attack", -raiseDamage);
                        enemy->receive_damage(damage, this_object());
                        message_vision( sprintf(HIY"$N�@���դ��i�סA�}�U�@��"HIW"�u��B�v"HIY"����A�S��X�@�O"HIM"�u�ߡv"HIY"����"NOR"$n"HIY"�I(%d) %s\n"NOR, damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                    }
                }
                message_vision(HIR"\n$N���^�F�����I\n\n"NOR, this_object());
            }
            return;
            break;
    }
}
void do_heal()
{
    if( (this_object()->query_stat_current("hp") < this_object()->query_stat_maximum("hp"))
        && this_object()->query_condition("da", 1) == 0) {
        command("perform digest absorb.check");
        return;
    }
    // �ӧn�F �����v�A�C�@�I
    if( random(100) < 1 ) {
        do_chat( ({ 
            (: command, "say ����...�I" :),
            (: command, "say ����...�I�I" :),
            (: command, "say ����...�I�I�I" :),
            (: command, "say �i����..." :),
            (: command, "say �H�K..." :),
            (: command, "say �øI���I...������I" :),
            (: command, "say �n�O...�I" :),
            (: command, "say �n�O...�I�I" :),
            (: command, "say �øI..." :),
            (: command, "say �O�ǧ�..." :),
            (: command, "say �X��F�I...������I" :),
        }) );
    }
    // �~���w�g����hp�ۡA�N���t�~�]�w
    heal_stat("ap", 9999);
    heal_stat("mp", 9999);
}
void create()
{
    set_name("�~��", ({ "wei qu", "wei", "qu", "_WEI_" }) );
    set_race("human");
    set_level(60);
    set_class("guard_sea");         // ���x�ս�
    set("classify", "strengthen");  // �j��
    set("age", 25);
    set("title", HIR"�Ѣޢ�"NOR);
    set("long", "��ۤ@���M�A�A��W���ۤ@�ڪ��������k�H�A�u���L�W�ۤ@�H����\n"
                "�a�H�C�ʧ@���Z����A��۫K��_�_�Ǫ��p�աA�����ٷ|�Ψ��᪺�p\n"
                "���V���@�n�M��Ԫ��ڭ��~�򰪰ۡC\n"
                "����M���x�ޯ�i���۾ǲߡA�Q�� train ���O�ӦV�~���ǲߧޯ�C\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    // �@��ɰʧ@
    set("chat_chance", 20);
    set("chat_msg", ({
        (: do_heal :),
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
    set_train_with_camp("combat", 1, 1, 180, "police", -2);           // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 120, "police", -2);            // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 140, "police", -2);            // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 140, "police", -2);        // �������N
    set_train_with_camp("savage hit", 1, 5, 140, "police", -2);       // �������N
    set_train_with_camp("continual hit", 1, 5, 140, "police", -2);    // �s�����N
    set_train_with_camp("spurn", 1, 10, 160, "police", -2);           // ��ް�¦
    set_train_with_camp("kick haze", 1, 15, 140, "police", -1);       // ��ޡG�P�}
    set_train_with_camp("kick lotus", 0, 20, 140, "police", 0);       // ��ޡG�P�}�E����
    set_train_with_camp("digest absorb", 0, 20, 120, "police", 0);    // �S��G���Ƨl��
    set_train_with_camp("hair bind", 0, 40, 100, "police", 1);        // �S��G��v����

    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":10+random(31), "p1":100, "p2":100 ]),   // ����
        ([ "type":"wp", "id":81, "amount":1, "p1":1, "p2":100 ]),                  // �I��
    }) );
    setup();
    set_skill("combat", 180);
    set_skill("dodge", 180);
    set_skill("parry", 180);
    set_skill("heavy hit", 140);
    set_skill("savage hit", 140);
    set_skill("continual hit", 140);
    set_skill("spurn", 200);
    set_skill("kick lotus", 200);
    set_skill("hair bind", 200);
    set_skill("digest absorb", 200);
    set_skill("body iron", 140);
    set_skill("paper step", 140);

    add_temp("apply/exact", 100);       // �R��
    add_temp("apply/evade", 50);        // �j��
    add_temp("apply/intimidate", 100);  // ������O
    add_temp("apply/wittiness", 50);    // ���m��O
    add_temp("apply/str", 5);
    add_temp("apply/con", 10);
    add_temp("apply/dex", 5);
    add_temp("apply/int", 5);

    carry_object(__DIR__"wp/staff.c")->wield();
    carry_object(__DIR__"eq/pants.c")->wear();
    carry_object(__DIR__"eq/suit.c")->wear();
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
    msg = "\n\n"HIM+this_object()->query("name")+"�Q"+enemy->query("name")+"������L�����A�N�o�˭ˤF�U�h�I\n\n"NOR;
    msg += HIB"�i�@�ɬF���j�Ѣޢ��u�����v����"+this_object()->query("name")+"("+this_object()->query("id")+")�~�M�Q"+enemy->query("name")+"("+enemy->query("id")+")�����F�I\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A�����~����o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

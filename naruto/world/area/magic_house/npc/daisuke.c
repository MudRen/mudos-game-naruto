#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    object enemy, ob;
    int damage, damage_attack;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( enemy->query_condition("hairstick", 1) == 0 ) {
        command("perform hair order.lunge on " + enemy->query_id() );
    } else if( ob = present("_VEGGIE_"+this_object()->query_id(), environment(this_object())) ) {
        if( !ob->is_fighting() ) {
            damage_attack = COMBAT_D->attack(this_object(), this_object(), 0, this_object()) - COMBAT_D->defend(enemy, enemy, 0);
            if( damage_attack < 0 ) damage_attack = 0;

            message_vision("$N�V��@�D�B�Ω��O���a"+ob->query("name")+"����ʡA�u��"+ob->query("name")+"�ߨ����Y�ĦV$n�I\n\n"NOR, this_object(), enemy);

            damage = ob->query_stat_maximum("hp")/2 + this_object()->query_skill("born-again branch") + random(100) + damage_attack;

            enemy->receive_damage(damage, this_object());
            message_vision( ob->query("name")+HIW"�C��K�}����"NOR"$n"HIW"���A���骺���߶}�l�o�X"HIR+BLINK"������~"NOR+HIW"�I\n"NOR, this_object(), enemy);
            message_vision( sprintf("�u�T�v�u�G�v�u�@�v�F�����T�N$n�����|������(%d)%s\n\n", damage, COMBAT_D->report_status(enemy)), this_object(), enemy);

            this_object()->delete_temp("TREE_ONE");
            this_object()->delete_temp("TREE_TWO");
            destruct(ob);
        }
    }
    return;
}

void do_heal()
{
    object item;

    if( this_object()->query_condition("blood_cell_revive_cond") == 0 && this_object()->query_stat("hp") < this_object()->query_stat_maximum("hp")/2 ) {
        command("perform blood-cell revive.revive");
        return;
    } else {
        if( this_object()->query_temp("TREE_ONE") == 0 && this_object()->query_temp("TREE_TWO") == 0 ) {
            item = new(_DIR_AREA_"thorn_pine/npc/item/branch.c");
            item->move(this_object());
            command("perform born-again branch.crop");
        } else if( present("_TREE_", environment(this_object())) ) {
            item = new(_DIR_AREA_"thorn_pine/npc/item/water04.c");
            item->move(this_object());
            command("perform born-again branch.arise");
        }
    }
    return;
}

void create()
{
    set_name("�Q���j��", ({ "matsuzaka daisuke", "daisuke" }) );
    set_race("human");
    set_level(60);
    set_class("hxh_star");  // �@�P�y�H
    set("age", 22);
    set("camp", "hunter");
    set("nickname", HIK"�����Ǫ�"NOR);
    set("long", "�쥻�~��b�����a�Ϫ��p�����A�]������M��컡�ܦӳQ��L�p��\n"
                "���Ǫ��ݫݡA�����]�N�����εo�{�L��H���~���A�K�N�L�a�i\n"
                "�����ΡA�]���A�Q�H�����F�C��t���ج��ް��N�C�i�H�Q��train \n"
                "���O�Ӿǲߧޯ�C�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n");

    set("chat_chance", 50);
    set("chat_msg", ({
        (: do_heal :),
    }) );

    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    // �u�о��y�H
    set("guild", "hunter");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 140, "hunter", -2);             // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 160, "hunter", -2);              // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 200, "hunter", 0);              // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 140, "hunter", -2);          // �������N
    set_train_with_camp("savage hit", 1, 5, 160, "hunter", -2);         // �������N
    set_train_with_camp("continual hit", 1, 5, 160, "hunter", -2);      // �s�����N
    set_train_with_camp("operation", 1, 10, 200, "hunter", -1);         // �ާ@�t�{��
    set_train_with_camp("blood-cell revive", 0, 15, 160, "hunter", -1); // ��y�A��
    set_train_with_camp("hair order", 1, 21, 140, "hunter", 0);         // ��v����
    set_train_with_camp("born-again branch", 0, 20, 120, "hunter", 0);  // ��K����

    setup();
    set_skill("combat", 140);
    set_skill("dodge", 160);
    set_skill("parry", 180);
    set_skill("heavy hit", 140);
    set_skill("savage hit", 160);
    set_skill("continual hit", 160);
    set_skill("operation", 200);
    set_skill("blood-cell revive", 200);
    set_skill("hair order", 200);
    set_skill("born-again branch", 200);
}
int accept_fight(object me, string arg)
{
    return 0;
}

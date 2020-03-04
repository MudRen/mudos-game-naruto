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
    if( this_object()->query_temp("SUMMON_DRAGON") == 0 ) {
        command("perform dragon-head draw.summon on " + enemy->query_id() );
    } else {
        command("perform psychical bullet.shoot on " + enemy->query_id() );
    }
    return;
}

// ��������Q���q�ߩ۪����s����Ѱ��԰���...
// ���G���|������= =...�u�n�t�~�g�R��
void do_delete()
{
    object ob;
    if( this_object()->query_temp("SUMMON_DRAGON") != 0 && ob = present("_DRAGON_NPC_", environment(this_object())) ) {
        message_vision(ob->query("name")+HIY"�o�X�@�}�j���A�����b�o�̤F�C\n"NOR, ob);
        destruct(ob);
    }
}

void create()
{
    set_name("�Q���q��", ({ "matsui hideki", "matsui", "hideki" }) );
    set_race("human");
    set_level(60);
    set_class("hxh_star");  // �@�P�y�H
    set("age", 26);
    set("camp", "hunter");
    set("nickname", HIM"�Ŵ���"NOR);
    set("long", "�]�N�����Υl��v�A����X�ϦU�ؤ��P���l��ͪ��A�䤤��������\n"
                "�j�N�s���ͪ��u�Ŵ��ԡv��O����p�B�ͪ��߷R�A�[�Ӥ[���o�]��\n"
                "���L���ٸ��F�A��t���ج��r�~�S�ޡC�i�H�Q��train ���O�Ӿǲ�\n"
                "�ޯ�C�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n");

    set("chat_chance", 50);
    set("chat_msg", ({
        (: do_delete :),
    }) );

    set("chat_chance_combat", 40);
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
    set_train_with_camp("combat", 1, 1, 160, "hunter", -2);            // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 160, "hunter", -2);             // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 160, "hunter", -2);             // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 140, "hunter", -2);         // �������N
    set_train_with_camp("savage hit", 1, 5, 160, "hunter", 0);          // �������N
    set_train_with_camp("continual hit", 1, 5, 160, "hunter", -2);     // �s�����N
    set_train_with_camp("emit", 1, 10, 200, "hunter", -1);             // ��X�t�{��
    set_train_with_camp("psychical bullet", 0, 15, 160, "hunter", -1); // ���u
    set_train_with_camp("machine gun", 0, 21, 140, "hunter", 0);       // ��������j
    set_train_with_camp("dragon-head draw", 0, 20, 120, "hunter", 0);  // �s�Y���e

    setup();
    set_skill("combat", 160);
    set_skill("dodge", 160);
    set_skill("parry", 160);
    set_skill("heavy hit", 140);
    set_skill("savage hit", 200);
    set_skill("continual hit", 160);
    set_skill("emit", 200);
    set_skill("psychical bullet", 200);
    set_skill("machine gun", 200);
    set_skill("dragon-head draw", 200);
}
int accept_fight(object me, string arg)
{
    return 0;
}

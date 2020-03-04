#include <npc.h>

inherit F_FIGHTER;
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
    command("perform thousand year kill.attack on " + enemy->query_id() );
    return;
}
void create()
{
    set_name("�x����H", ({ "naruto" }));
    set_race("human");
    set_level(50);
    set_class("inferior");   // �U��
    set("camp", "muye");
    set("long", "���w�c�@�@����H�A�O�츭�������D�ൣ�A�b�Ԫ̾Ǯդ]�O�ӡu�Q��\n"
                "���v���ǥ͡C�]�����W�Q���~�u�E�����v�Ҫ����A�ҥH�p�ɭԧ��H��\n"
                "���@�N�a��L�A�����|�d�Ѯv��L���}�ߩХ[�W��ӥ[�J�d�d��p\n"
                "���o�ͤj�D�Yŧ���ƥ󵥡A����K��ۤT�Ԥ��@���ۨӤ]�ǲߧԳN�C\n");

    set("age", 16);
    set("gender", "male");
    set("chat_chance_combat", 30);
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
    set_train_with_camp("combat", 1, 1, 160, "muye", -2);              // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 100, "muye", -2);               // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 120, "muye", -2);               // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 120, "muye", -2);           // �������N
    set_train_with_camp("savage hit", 1, 5, 140, "muye", -2);          // �������N
    set_train_with_camp("continual hit", 1, 5, 120, "muye", -2);       // �s�����N
    set_train_with_camp("ninja", 1, 10, 120, "muye", -2);              // �ԳN
    set_train_with_camp("force", 1, 10, 140, "muye", -2);              // ��N
    set_train_with_camp("alter ego", 0, 15, 140, "muye", -1);          // �ԳN�G�����N
    set_train_with_camp("shadow", 0, 20, 120, "muye", -1);             // �ԳN�G�v�����N
    set_train_with_camp("thousand year kill", 0, 21, 100, "muye", 0); // ��N�G�d�~��

    setup();
    set_skill("ninja", 160);
    set_skill("force", 180);
    set_skill("thousand year kill", 200);
    set_skill("substitute", 200);
    map_skill("dodge", "substitute");
}

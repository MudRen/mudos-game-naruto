#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // �V�m�ɮv

void create()
{
    set_name("��E�^��", ({ "T bone", "bone" }) );
    set_race("human");
    set_level(40);
    set_class("officer_sea");  // ���x�h�x
    set("age", 20);
    set("title", HIB"���x�`���W��"NOR);
    set("long", "���x���W���N��A�H�١u�ٲ�L�v�@�M�i�H�N�@���������A����b�A\n"
                "�]���Q���s�����M�k�A�ҥH�ϥΪ��ۦ������O���Ӫ����������M�k�C\n"
                "�ثe���u�@�O���ɮ��x�s�i�H���ǲߧޯ�C\n"
                "����M���x�ޯ�i���۾ǲߡA�Q�� train ���O�ӦV�^���ǲߧޯ�C\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    // ����������A���x����i���۾ǲߧޯ�
    set("guild", "piece");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 100, "police", -2);           // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 100, "police", -2);            // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 140, "police", -2);            // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 120, "police", -2);        // �������N
    set_train_with_camp("savage hit", 1, 5, 120, "police", -2);       // �������N
    set_train_with_camp("continual hit", 1, 5, 120, "police", -2);    // �s�����N
    set_train_with_camp("blade", 1, 10, 140, "police", -2);           // �M�N��¦
    set_train_with_camp("blink normal", 1, 15, 160, "police", -1);    // �M�N�G�����{��
    set_train_with_camp("flybird normal", 1, 20, 140, "police", -1);  // �M�N�G��������

    setup();
    set_skill("blade", 180);
    set_skill("blink normal", 200);
    set_skill("flybird normal", 200);
    carry_object(_DIR_WP_"longsword.c")->wield();
}

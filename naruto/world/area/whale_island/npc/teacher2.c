/* guild: hunter  �y�H */
// write by Tmr 2005/10/22

#include <npc.h>

inherit F_VILLAGER;
inherit F_TRAINER;    // �V�m�ɮv

void create()
{
    set_name("����¶", ({ "ma bu-rao", "rao", "teacher"}) );
    set_race("human");
    set_level(30);
    set_class("hxh_intermediate");  //�����y�H
    set("age", 25);
    set("camp", "hunter");
    set("title", "�y�H�����ɮv");
    set("gender","female");
    set("long", "����¶�O�@�즳�W���y�H�����ɮv�A�]�O���W������O�̡A��q���j�t��\n"
                "�`�Χޯ�C�i�H�Q��train ���O�Ӿǲߧޯ�C�ϥ� list ���O�d�ߥi�ǲ�\n"
                "���ޯ�C��C\n" );

    // �u�����y�H
    set("guild", "hunter");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("finger-guessing fist", 1, 10, 100, "hunter", -1);  // ����
    set_train_with_camp("solid", 1, 10, 120, "hunter", -1);                 // �� 
    set_train_with_camp("body strength", 1, 10, 100, "hunter", -1);         // ����j��
    set_train_with_camp("psychical bullet", 1, 10, 100, "hunter", -1);      // ���u
    set_train_with_camp("holy hand", 1, 10, 100, "hunter", -1);             // �t������
    set_train_with_camp("harm touch", 1, 10, 100, "hunter", -1);            // �ˮ`��Ĳ
    set_train_with_camp("blood-cell revive", 1, 10, 100, "hunter", -1);     // �ӭM�A��
    set_train_with_camp("fire variation", 1, 10, 100, "hunter", -1);        // �����O�ܤ�
    set_train_with_camp("ice variation", 1, 10, 100, "hunter", -1);         // �B���O�ܤ�
    set_train_with_camp("electric variation", 1, 10, 100, "hunter", -1);    // �q���O�ܤ�
    set_train_with_camp("eaves family", 1, 10, 100, "hunter", -1);          // ��ò�U���@�a�H

    setup();

    // �H���������ޯ�]�w
    set_skill("solid", 100);               // ���ޡG��
    map_skill("parry", "solid");    
}

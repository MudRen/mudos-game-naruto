/* guild: hunter  �y�H */
// write by Tmr 2005/10/22
// �W�[���tsk lv 160   by mouse 2007/4/24

#include <npc.h>

inherit F_VILLAGER;
inherit F_TRAINER;    // �V�m�ɮv

void create()
{
    set_name("�ŽէƤZ", ({ "blue xi fan", "fan"}) );
    set_race("human");
    set_level(30);
    set_class("hxh_intermediate");  //�����y�H
    set("age", 40);
    set("camp", "hunter");
    set("title", "�y�H�����ɮv");
    set("gender","female");
    set("long",@long
�ŽէƤZ�O�@�즳�W���y�H�G�������ɮv�A�]�O���W������O�̡A��q����
�y�H�`�������j�t�S��ޯ�C�i�H�Q��train ���O�Ӿǲߧޯ�C�ϥ� list 
���O�d�ߥi�ǲߪ��ޯ�C��
long
);

    // �u�����y�H
    set("guild", "hunter");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("machine gun", 1, 21, 100, "hunter", 0);         // ��X�t�G��������j
    set_train_with_camp("chamber fish", 1, 21, 100, "hunter", 0);        // ��{�t�G�K�ǩ���
    set_train_with_camp("chain lighting", 1, 21, 100, "hunter", 0);      // �ܤƨt�G�s��{�q
    set_train_with_camp("frost closed ball", 1, 21, 100, "hunter", 0);   // �ܤƨt�G�B�ʲy
    set_train_with_camp("variation", 1, 10, 160, "hunter", -1);          // �ܤƨt
    set_train_with_camp("strength", 1, 10, 160, "hunter", -1);           // �j�ƨt
    set_train_with_camp("operation", 1, 10, 160, "hunter", -1);          // �ާ@�t
    set_train_with_camp("emit", 1, 10, 160, "hunter", -1);               // ��X�t
    set_train_with_camp("concrete", 1, 10, 160, "hunter", -1);           // ��{�t
    set_train_with_camp("special", 1, 10, 160, "hunter", -1);            // �S��t
    setup();

    // �H���������ޯ�]�w
    set_skill("solid", 100);               // ���ޡG��
    map_skill("parry", "solid");    
}

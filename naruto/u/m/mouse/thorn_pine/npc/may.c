#include <npc.h>

inherit F_VENDOR;

void create()
{
    set_name("�\�f", ({ "bow may", "may" }));
    set_race("human");
    set_level(60);
    set("age", 20);
    set("gender", "female");
    set("nickname","���Y�Z���M��");
    set("long", "�Ʀ�\�f�A�j�F��ǡA�`�o���@�ǧ��Y�Z���C\n");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "ccc" :),
        (: command, "say �s���~�I���� & �԰���ϥ]�I" :),
    }));

    // �]�w�ӤH�ҳc�檺���~
    // set_goods(�N�X, ����, �s��, �ƶq, ���)
    // �ӤH��c�檺�F��u��� query ���O�̬d eq, wp, food ��d�X�Ӫ����~
    // �p set_goods(1, "food", 1, 10, -1) ��ܳc�� query ���O�d�X�Ӫ�food�s����1�����~�Q��
    // �Y�ƶq�]�w -1 ��ܵL���q����
    // �Y����]�� -1 ��ܻ����O�ϥθӪ���]�w��value
    // �N�X�O�Ω� buy ���O�W�A�p buy 1 �h�|�V�ӤH�R�U�N�X��1���ӫ~

    set_goods(1, "wp", 5, 50, -1);     // �W�L
    set_goods(2, "wp", 11, 50, -1);    // �u�C
    set_goods(3, "obj", 58, -1, -1);   // �믫���
    set_goods(4, "obj", 65, -1, -1);   // ��O���
    set_goods(5, "obj", 66, -1, -1);   // ���d���
    set_goods(6, "obj", 62, 50, -1);   // ����
    set_goods(7, "obj", 63, 30, -1);   // ����
    set_goods(8, "obj", 64, 10, -1);   // ��
    set_goods(9, "obj", 59, 10, -1);   // ���u
    setup();
}

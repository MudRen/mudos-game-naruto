#include <npc.h>

inherit F_VENDOR;

void create()
{
    set_name("�\��", ({ "bow gr", "gr" }));
    set_race("human");
    set_level(60);
    set("age", 28);
    set("gender", "male");
    set("nickname","���Z���M��");
    set("long", "�Ʀ�Ѥj�A�����F���A����s�@���Z���C\n");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "say �w����{�I" :),
        (: command, "say ���H�K�ݬݪ��I" :),
    }));

    // �]�w�ӤH�ҳc�檺���~
    // set_goods(�N�X, ����, �s��, �ƶq, ���)
    // �ӤH��c�檺�F��u��� query ���O�̬d eq, wp, food ��d�X�Ӫ����~
    // �p set_goods(1, "food", 1, 10, -1) ��ܳc�� query ���O�d�X�Ӫ�food�s����1�����~�Q��
    // �Y�ƶq�]�w -1 ��ܵL���q����
    // �Y����]�� -1 ��ܻ����O�ϥθӪ���]�w��value
    // �N�X�O�Ω� buy ���O�W�A�p buy 1 �h�|�V�ӤH�R�U�N�X��1���ӫ~

    set_goods(1, "wp", 10, 20, -1);    // �ñ�
    set_goods(2, "wp", 3, 20, -1);     // ��M
    set_goods(3, "wp", 2, 15, -1);     // �j�M
    set_goods(4, "wp", 7, 15, -1);     // ���C
    set_goods(5, "wp", 8, 15, -1);     // ���I��
    set_goods(6, "wp", 45, 10, -1);    // ��C
    set_goods(7, "wp", 41, 10, -1);    // ���M
    set_goods(8, "wp", 35, 10, -1);    // �K��
    set_goods(9, "wp", 34, 10, -1);    // �K�M
    set_goods(10, "wp", 38, 10, -1);   // �����K��
    set_goods(11, "wp", 36, 10, -1);   // �课�C
    set_goods(12, "wp", 30, 5, -1);    // �����ԤM
    set_goods(13, "wp", 40, 1, -1);    // ���ۼC
    setup();
}

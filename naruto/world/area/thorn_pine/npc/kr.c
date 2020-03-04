#include <npc.h>
#include <ansi.h>

inherit F_VENDOR;

void create()
{
    set_name("�\�i", ({ "bow kr", "kr" }));
    set_race("human");
    set_level(60);
    set("age", 25);
    set("gender", "male");
    set("nickname","����Z���M��");
    set("long", "�Ʀ�ѤG�A�O�j�p���A�t�d����Z�����s���C\n");
    set("camp", "bow");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "sweat" :),
        CYN"�\�i�����p�B�������V���Z���C\n"NOR,
    }));

    // �]�w�ӤH�ҳc�檺���~
    // set_goods(�N�X, ����, �s��, �ƶq, ���)
    // �ӤH��c�檺�F��u��� query ���O�̬d eq, wp, food ��d�X�Ӫ����~
    // �p set_goods(1, "food", 1, 10, -1) ��ܳc�� query ���O�d�X�Ӫ�food�s����1�����~�Q��
    // �Y�ƶq�]�w -1 ��ܵL���q����
    // �Y����]�� -1 ��ܻ����O�ϥθӪ���]�w��value
    // �N�X�O�Ω� buy ���O�W�A�p buy 1 �h�|�V�ӤH�R�U�N�X��1���ӫ~

    set_goods(1, "wp", 6, 20, -1);     // ���b��
    set_goods(2, "wp", 1, 20, -1);     // �j��
    set_goods(3, "wp", 4, 15, -1);     // ���ޤM
    set_goods(4, "wp", 12, 15, -1);    // �尨�j�M
    set_goods(5, "wp", 33, 10, -1);    // �j���
    set_goods(6, "wp", 31, 10, -1);    // ���Y
    set_goods(7, "wp", 44, 10, -1);    // �j�۩�
    set_goods(8, "wp", 43, 10, -1);    // ����
    set_goods(9, "wp", 42, 10, -1);    // ���j
    set_goods(10, "wp", 39, 10, -1);   // �n�j
    set_goods(11, "wp", 32, 5, -1);    // ����
    set_goods(12, "wp", 37, 1, -1);    // ���`���

    setup();
}

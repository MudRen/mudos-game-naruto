#include <npc.h>

inherit F_VENDOR;

void create()
{
    set_name("�Z���ӤH", ({ "weapon vendor", "vendor" }));
    set_race("human");
    set_level(50);
    set("age", random(50)+18);

    set("long", "�L�l�����ӡA�Q�����l�Ӽ˪��Ѧl�ӤH�C\n");

    // �]�w�ӤH�ҳc�檺���~
    // set_goods(�N�X, ����, �s��, �ƶq, ���)
    // �ӤH��c�檺�F��u��� query ���O�̬d eq, wp, food ��d�X�Ӫ����~
    // �p set_goods(1, "food", 1, 10, -1) ��ܳc�� query ���O�d�X�Ӫ�food�s����1�����~�Q��
    // �Y�ƶq�]�w -1 ��ܵL���q����
    // �Y����]�� -1 ��ܻ����O�ϥθӪ���]�w��value
    // �N�X�O�Ω� buy ���O�W�A�p buy 1 �h�|�V�ӤH�R�U�N�X��1���ӫ~

    set_goods(1, "wp", 1, 10, -1);
    set_goods(2, "wp", 2, 10, -1);
    set_goods(3, "wp", 3, 10, -1);
    set_goods(4, "wp", 4, 10, -1);
    set_goods(5, "wp", 5, 10, -1);
    set_goods(6, "wp", 6, 10, -1);
    set_goods(7, "wp", 7, 10, -1);
    set_goods(8, "wp", 8, 10, -1);
    set_goods(9, "wp", 9, 10, -1);
    set_goods(10, "wp", 10, 10, -1);
    set_goods(11, "wp", 11, 10, -1);
    set_goods(12, "wp", 12, 10, -1);

    setup();
}
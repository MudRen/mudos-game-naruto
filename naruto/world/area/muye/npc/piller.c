#include <npc.h>

inherit F_VENDOR;

void create()
{
    set_name("�ī~�ӤH", ({ "pill vendor", "vendor" }));
    set_race("human");
    set_level(50);
    set("age", random(50)+18);
    set("camp", "muye");
    set("long", "�L�l�����ӡA�Q�����l�Ӽ˪��Ѧl�ӤH�C\n");

    // �]�w�ӤH�ҳc�檺���~
    // set_goods(�N�X, ����, �s��, �ƶq, ���)
    // �ӤH��c�檺�F��u��� query ���O�̬d eq, wp, food ��d�X�Ӫ����~
    // �p set_goods(1, "food", 1, 10, -1) ��ܳc�� query ���O�d�X�Ӫ�food�s����1�����~�Q��
    // �Y�ƶq�]�w -1 ��ܵL���q����
    // �Y����]�� -1 ��ܻ����O�ϥθӪ���]�w��value
    // �N�X�O�Ω� buy ���O�W�A�p buy 1 �h�|�V�ӤH�R�U�N�X��1���ӫ~

    set_goods(1, "food", 1, -1, -1);
    set_goods(2, "food", 2, -1, -1);
    set_goods(3, "food", 3, -1, -1);
    set_goods(4, "food", 4, -1, -1);
    set_goods(5, "food", 5, -1, -1);
    set_goods(6, "food", 6, -1, -1);
    set_goods(7, "food", 7, -1, -1);
    set_goods(8, "food", 8, -1, -1);
    set_goods(9, "food", 9, -1, -1);
    set_goods(10, "food", 12, -1, -1);
    set_goods(11, "food", 13, -1, -1);
    set_goods(12, "food", 14, -1, -1);
    set_goods(13, "food", 15, -1, -1);
    set_goods(14, "food", 16, -1, -1);
    set_goods(15, "food", 17, -1, -1);
    set_goods(16, "food", 18, -1, -1);
    set_goods(17, "food", 19, -1, -1);
    set_goods(18, "food", 20, -1, -1);

    setup();
}

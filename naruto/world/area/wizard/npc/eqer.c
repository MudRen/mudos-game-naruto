#include <npc.h>

inherit F_VENDOR;

void create()
{
    set_name("���j�v", ({ "armor master", "master" }));
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

    set_goods(1, "eq", 1, 10, -1);
    set_goods(2, "eq", 2, 10, -1);
    set_goods(3, "eq", 3, 10, -1);
    set_goods(4, "eq", 4, 10, -1);
    set_goods(5, "eq", 5, 10, -1);
    set_goods(6, "eq", 6, 10, -1);
    set_goods(7, "eq", 7, 10, -1);
    set_goods(8, "eq", 8, 10, -1);
    set_goods(9, "eq", 9, 10, -1);
    set_goods(10, "eq", 10, 10, -1);
    set_goods(11, "eq", 11, 10, -1);
    set_goods(12, "eq", 12, 10, -1);
    set_goods(13, "eq", 13, 10, -1);
    set_goods(14, "eq", 14, 10, -1);
    set_goods(15, "eq", 15, 10, -1);
    set_goods(16, "eq", 16, 10, -1);
    set_goods(17, "eq", 17, 10, -1);
    set_goods(18, "eq", 18, 10, -1);
    set_goods(19, "eq", 19, 10, -1);
    set_goods(20, "eq", 20, 10, -1);
    set_goods(21, "eq", 21, 10, -1);
    set_goods(22, "eq", 22, 10, -1);
    set_goods(23, "eq", 23, 10, -1);
    set_goods(24, "eq", 24, 10, -1);
    set_goods(25, "eq", 25, 10, -1);

    setup();
}

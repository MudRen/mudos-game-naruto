#include <npc.h>

inherit F_VENDOR;

void create()
{
    set_name("����ӤH", ({ "equip vendor", "vendor" }));
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

    set_goods(1, "eq", 26, 10, -1);
    set_goods(2, "eq", 27, 10, -1);
    set_goods(3, "eq", 28, 10, -1);
    set_goods(4, "eq", 29, 10, -1);
    set_goods(5, "eq", 30, 10, -1);
    set_goods(6, "eq", 31, 10, -1);
    set_goods(7, "eq", 32, 10, -1);
    set_goods(8, "eq", 33, 10, -1);
    set_goods(9, "eq", 34, 10, -1);
    set_goods(10, "eq", 35, 10, -1);
    set_goods(11, "eq", 36, 10, -1);
    set_goods(12, "eq", 37, 10, -1);
    set_goods(13, "eq", 38, 10, -1);
    set_goods(14, "eq", 39, 10, -1);
    set_goods(15, "eq", 40, 10, -1);
    set_goods(16, "eq", 41, 10, -1);
    set_goods(17, "eq", 42, 10, -1);
    set_goods(18, "eq", 43, 10, -1);
    set_goods(19, "eq", 44, 10, -1);
    set_goods(20, "eq", 45, 10, -1);
    set_goods(21, "eq", 46, 10, -1);
    set_goods(22, "eq", 48, 10, -1);
    set_goods(23, "eq", 49, 10, -1);
    set_goods(24, "eq", 50, 10, -1);
    set_goods(25, "eq", 51, 10, -1);
    set_goods(26, "eq", 52, 10, -1);

    setup();
}

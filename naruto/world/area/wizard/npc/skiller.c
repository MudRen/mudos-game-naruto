#include <npc.h>

inherit F_VENDOR;

void create()
{
    set_name("�N�j�v", ({ "skill master", "master" }));
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

    set_goods(1, "obj", 1, 10, 50000);
    set_goods(2, "obj", 4, 10, 50000);
    set_goods(3, "obj", 6, 10, 50000);
    set_goods(4, "obj", 8, 10, 50000);
    set_goods(5, "obj", 2, 10, 200000);
    set_goods(6, "obj", 3, 10, 200000);
    set_goods(7, "obj", 5, 10, 200000);
    set_goods(8, "obj", 7, 10, 200000);
    set_goods(9, "obj", 14, 10, 50000);
    set_goods(10, "obj", 15, 10, 50000);
    set_goods(11, "obj", 18, 10, 50000);
    set_goods(12, "obj", 19, 10, 50000);
    set_goods(13, "obj", 20, 10, 200000);
    set_goods(14, "obj", 21, 10, 200000);
    set_goods(15, "obj", 16, 10, 200000);
    set_goods(16, "obj", 17, 10, 200000);
    set_goods(17, "obj", 83, 10, 1000000);
    set_goods(18, "obj", 84, 10, 1000000);
    set_goods(19, "obj", 85, 10, 1000000);
    set_goods(20, "obj", 86, 10, 1000000);
    set_goods(21, "obj", 10, 10, 200000);
    set_goods(22, "obj", 11, 10, 50000);
    set_goods(23, "obj", 12, 10, 100000);
    set_goods(24, "obj", 75, 10, 100000);
    set_goods(25, "obj", 91, 10, 430000);
    set_goods(26, "obj", 93, 10, 75000);
//    set_goods(17, "obj", 10, 50, -1);
//    set_goods(18, "obj", 11, 50, -1);
//    set_goods(19, "obj", 12, 50, -1);
//    set_goods(20, "obj", 75, 10, -1);



    setup();
}

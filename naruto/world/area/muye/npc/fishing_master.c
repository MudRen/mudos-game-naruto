#include <npc.h>

inherit F_VENDOR;

void create()
{
    set_name("�����H", ({ "fishing master", "master" }));
    set_race("human");
    set_level(50);
    set("age", random(50)+18);

    set("long", "�����ɤ����Ĥ@���ȡA�A�i�H��L�R����ӳ����C\n");

    // �]�w�ӤH�ҳc�檺���~
    // set_goods(�N�X, ����, �s��, �ƶq, ���)
    // �ӤH��c�檺�F��u��� query ���O�̬d eq, wp, food ��d�X�Ӫ����~
    // �p set_goods(1, "food", 1, 10, -1) ��ܳc�� query ���O�d�X�Ӫ�food�s����1�����~�Q��
    // �Y�ƶq�]�w -1 ��ܵL���q����
    // �Y����]�� -1 ��ܻ����O�ϥθӪ���]�w��value
    // �N�X�O�Ω� buy ���O�W�A�p buy 1 �h�|�V�ӤH�R�U�N�X��1���ӫ~

    set_goods(1, "wp", 15, 10, -1);

    // �]�w���������c�G (���l/����) �O�������v
    // ({ ([ "type":���O, "id":�s��, "amount":�ƶq, "p1":���l, "p2":���� ]),
    //    ([ ... ]), ([ ... ]), ... })
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":100+random(100), "p1":50, "p2":100 ]),  // �Ȥl
        ([ "type":"eq", "id":21, "amount":1, "p1":70, "p2":100 ]),     // ����M
        ([ "type":"eq", "id":7, "amount":1, "p1":70, "p2":100 ]),     // ����
        ([ "type":"eq", "id":64, "amount":1, "p1":20, "p2":100 ]),     // ���
        ([ "type":"wp", "id":15, "amount":1, "p1":60, "p2":100 ]),     // ����
    }) );

    setup();
}

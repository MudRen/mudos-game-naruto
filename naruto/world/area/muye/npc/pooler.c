#include <npc.h>

inherit F_VENDOR;

void create()
{
    set_name("�w������", ({ "pool boss", "boss" }));
    set_race("human");
    set_level(50);
    set("age", random(50)+18);
    set("camp", "muye");
    set("long", "�L�O�w�Ŭu������A�ݰ_�өMħ�i�ˡC\n");

    // �]�w�ӤH�ҳc�檺���~
    // set_goods(�N�X, ����, �s��, �ƶq, ���)
    // �ӤH��c�檺�F��u��� query ���O�̬d eq, wp, food ��d�X�Ӫ����~
    // �p set_goods(1, "food", 1, 10, -1) ��ܳc�� query ���O�d�X�Ӫ�food�s����1�����~�Q��
    // �Y�ƶq�]�w -1 ��ܵL���q����
    // �Y����]�� -1 ��ܻ����O�ϥθӪ���]�w��value
    // �N�X�O�Ω� buy ���O�W�A�p buy 1 �h�|�V�ӤH�R�U�N�X��1���ӫ~

    setup();
}

#include <npc.h>
#include <ansi.h>

inherit F_VENDOR;

void create()
{
    set_name("�ӤH", ({ "seller" }));
    set_race("human");
    set_level(15);
    set("age", 55);
    set("title",HIM"��s�{"NOR);
    set("long", "�Mħ�i�˪��ӤH�A���G���o�̥X�����@���D�`���H�ߡC\n");

    // �]�w�ӤH�ҳc�檺���~
    // set_goods(�N�X, ����, �s��, �ƶq, ���)
    // �ӤH��c�檺�F��u��� query ���O�̬d eq, wp, food ��d�X�Ӫ����~
    // �p set_goods(1, "food", 1, 10, -1) ��ܳc�� query ���O�d�X�Ӫ�food�s����1�����~�Q��
    // �Y�ƶq�]�w -1 ��ܵL���q����
    // �Y����]�� -1 ��ܻ����O�ϥθӪ���]�w��value
    // �N�X�O�Ω� buy ���O�W�A�p buy 1 �h�|�V�ӤH�R�U�N�X��1���ӫ~

    set_goods(1, "obj", 116, 20, -1);
    set_goods(2, "obj", 117, 10, -1);
    set_goods(3, "obj", 115, 10, -1);
    set_goods(4, "obj", 114, 5, -1);

    setup();
}

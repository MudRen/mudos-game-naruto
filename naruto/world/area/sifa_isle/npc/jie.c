#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_VENDOR;

void create()
{
    set_name("�ǧQ", ({ "jie li", "li", "jie" }));
    set_race("human");
    set_level(50);
    set("age", 55);
    set("title",HIR"�Ѣޢ�"NOR);
    set_class("guard_sea");  // ���x�ս�
    set("long", "�����D�`���j���k�H�A��W�a�ۦy�뮱�M�A���G�|�Z�N���ˤl�C�L�{\n"
                "�b���u�@�O�O�ޥq�k�q�W���u�ĩСA�p�G����x���j�䦳����]�\\�i\n"
                "�H��L�R�@��Ӫ����]�����w�C\n");

    // �]�w�ӤH�ҳc�檺���~
    // set_goods(�N�X, ����, �s��, �ƶq, ���)
    // �ӤH��c�檺�F��u��� query ���O�̬d eq, wp, food ��d�X�Ӫ����~
    // �p set_goods(1, "food", 1, 10, -1) ��ܳc�� query ���O�d�X�Ӫ�food�s����1�����~�Q��
    // �Y�ƶq�]�w -1 ��ܵL���q����
    // �Y����]�� -1 ��ܻ����O�ϥθӪ���]�w��value
    // �N�X�O�Ω� buy ���O�W�A�p buy 1 �h�|�V�ӤH�R�U�N�X��1���ӫ~

    set_goods(1, "wp", 56, -1, -1);
    set_goods(2, "obj", 100, -1, -1);

    setup();
}

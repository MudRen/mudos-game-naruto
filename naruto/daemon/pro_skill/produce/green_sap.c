// ����G�s�y green_sap.c
#include <ansi.h>

// �ݩ�Ͳ��ޯ�U�����~
string getProSkill() { return "produce"; }

// �߱o�����~���n���ޯ൥��
int getLearnLevel() { return 0; }

// ���~�W��
string getName() { return "����G"; }

// ²�z
string getBrief() {
    return "��⪺���G��A�వ����ΩO�H";
}

// �ԭz
string getDetail() {
    return "�ϥκ�⽭�洣�ҥX�Ӫ��G��A�]���O��ġA�L�k����ĭ��ΡC\n";
}

// �s�y�����~�һݪ�����
mapping getStuff() {
    mapping stuff = ([
        "/world/area/rural_area/item/pill_obj01.c": 1,  // �Ե�
        "/world/area/rural_area/item/pill_obj03.c": 1,  // ���
    ]);
    return stuff;
}

// �s�y�����~��
string getProduct() {
    return "/world/area/thorn_pine/npc/item/water01.c";  // ����G
}

// �s�y���~�ɪ��T��
string makeMsg()
{
    return HIG"$N���_�o�ڱN���ƥ�����i�ڤ��A�}�l�^������G�C\n"NOR;
}

// ���~�O�_�j�w(�]�N�O�s�y���H�~���), (1:�O, 0:�_)
// ���G�j�w�����~�̦n�O����X�֪����~�A�_�h�j�w�|�V��
//     �j�w�����~�W�|�]�w set("binding", ����id)
//     �ҥH�n�P�_�Ӳ��~�O�_��Q�ϥδN�O�ˬd binding �O�_�ŦX���a��id�N��F
int isBinding() { return 0; }

#include <ansi.h>

// �����o�O�@�Ӱ}����
int isCamp() { return 1; }

// �}��W��
string getName() { return "�B����"; }

// �ͦn�}��
string* getFriendly() { return ({}); }

// �Ĺ�}��
string* getAdversely() { return ({ "muye" }); }

// (4) �R��, (3) �R�q, (2) �L�q, (1) �ͦn, (0) ����, (-1) �N�H, (-2) �ĵ�, (-3) �Ĺ�, (-4) ����

// ���a�b�Ӱ}�窺�n��C��h�֮ɷ|�QAuto kill�A�w�]���ȬO-3
int getHate() { return -2; }

// Auto Kill �ɡA�ҭn�۪���, $N�O�ۤw, $n�O���
string getHateMsg() {
    switch( random(3) ) {
        case 0: return HIR"$N���M�j�s�_�ӡG��$n���D�P�ڭ̫B�������Ī��U���I\n"NOR; break;
        case 1: return HIR"$N�q�D�G�֬ݤ��_�B�ԤF�I��$n���D�ڭ̪��F�`�I\n"NOR; break;
        case 2: return HIR"$N�H���ۡG�����o��e���Q$n���ѡI\n"NOR; break;
    }
}

// ���a�b�Ĺ�}�窺�n�氪��h�֮ɷ|�QAuto kill, �w�]���ȬO 3
int getAdvHate() { return 1; }

// �ع�Ĺ�}���Auto kill�n�۪���, $N�ɦۤw, $n�O���
string getAdvHateMsg() {
    return HIR"$N���㪺�q�s�ۡG�ڭn��$n���D�I�Q�a�츭�o�Ӥj���O�S�n�U�����I\n"NOR;
}

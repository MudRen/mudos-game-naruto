#include <ansi.h>

// �����o�O�@�Ӱ}����
int isCamp() { return 1; }

// �}��W��
string getName() { return "�\��"; }

// �ͦn�}��
string* getFriendly() { return ({}); }

// �Ĺ�}��
string* getAdversely() { return ({ "owl" }); }

// (4) �R��, (3) �R�q, (2) �L�q, (1) �ͦn, (0) ����, (-1) �N�H, (-2) �ĵ�, (-3) �Ĺ�, (-4) ����

// ���a�b�Ӱ}�窺�n��C��h�֮ɷ|�QAuto kill�A�w�]���ȬO-3
int getHate() { return -3; }

// Auto Kill �ɡA�ҭn�۪���, $N�O�ۤw, $n�O���
string getHateMsg() {
    switch( random(3) ) {
        case 0: return HIR"$N�ݨ�O$n�N���o�F�Ʀ����ĤW�ӧq�ۡG�\�ڪ��ĤH�O�]�I\n"NOR; break;
        case 1: return HIR"$N����$n�j�s�G�N�O$n�I�N�O$n���F�j���Ѥ����Ĥl�I\n"NOR; break;
        case 2: return HIR"$N�d���a�q�s�ۡG�i�c��$n�`�ڭ̷l���F�h�֦P�M�I\n"NOR; break;
    }
}

// ���a�b�Ĺ�}�窺�n�氪��h�֮ɷ|�QAuto kill, �w�]���ȬO 3
int getAdvHate() { return 3; }

// �ع�Ĺ�}���Auto kill�n�۪���, $N�ɦۤw, $n�O���
string getAdvHateMsg() {
    return HIR"$N�q�D�G$n�N�O���U�a�����m���ڭ̦a�L���H�a�I$n�S���X�{�b�o�̡I\n"NOR;
}

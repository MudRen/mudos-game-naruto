#include <ansi.h>

// �����o�O�@�Ӱ}����
int isCamp() { return 1; }

// �}��W��
string getName() { return "�F�ޱj�s"; }

// �ͦn�}��
string* getFriendly() { return ({}); }

// �Ĺ�}��
string* getAdversely() { return ({ "hunter" }); }

// (4) �R��, (3) �R�q, (2) �L�q, (1) �ͦn, (0) ����, (-1) �N�H, (-2) �ĵ�, (-3) �Ĺ�, (-4) ����

// ���a�b�Ӱ}�窺�n��C��h�֮ɷ|�QAuto kill�A�w�]���ȬO-3
int getHate() { return -2; }

// Auto Kill �ɡA�ҭn�۪���, $N�O�ۤw, $n�O���
string getHateMsg() {
    switch( random(3) ) {
        case 0: return HIR"$N���c�a���F�X�n�j�ۡG�ޡI$n�I�٤��⨭�W�����]��X�ӡI\n"NOR; break;
        case 1: return HIR"$N���c�a���ۻ��D�G�e���e��a���f...$n�ٯu�n�ߪ��I\n"NOR; break;
        case 2: return HIR"$N�V�e�@���A�z�z�j�s�G���i�O�H�a�̤����D���L���O���I\n"NOR; break;
    }
}

// ���a�b�Ĺ�}�窺�n�氪��h�֮ɷ|�QAuto kill, �w�]���ȬO 3
int getAdvHate() { return 3; }

// �ع�Ĺ�}���Auto kill�n�۪���, $N�ɦۤw, $n�O���
string getAdvHateMsg() {
    return HIR"$N���q���s�ۡG�̰Q����$n�o�ئۥH���^�����H�I�h���a�I\n"NOR;
}

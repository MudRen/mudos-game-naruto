#include <ansi.h>

// �����o�O�@�Ӱ}����
int isCamp() { return 1; }

// �}��W��
string getName() { return "���}�s��"; }

// �ͦn�}��
string* getFriendly() { return ({}); }

// �Ĺ�}��
string* getAdversely() { return ({ "hunter" }); }

// (4) �R��, (3) �R�q, (2) �L�q, (1) �ͦn, (0) ����, (-1) �N�H, (-2) �ĵ�, (-3) �Ĺ�, (-4) ����

// ���a�b�Ӱ}�窺�n��C��h�֮ɷ|�QAuto kill�A�w�]���ȬO-3
int getHate() { return -1; }

// Auto Kill �ɡA�ҭn�۪���, $N�O�ۤw, $n�O���
string getHateMsg() {
    switch( random(3) ) {
        case 0: return HIR"$N�j�n�H���ۡG$n�~�M�o�{�F�ڭ̪����K��a�I����d���f�I\n"NOR; break;
        case 1: return HIR"$N���D�G$n�O�q���̶]�Ӫ��I\n"NOR; break;
        case 2: return HIR"$N�l���a���G�S�Q��o�~�Y�٦��ΦϦۤv�]�W���ӡI\n"NOR; break;
    }
}

// ���a�b�Ĺ�}�窺�n�氪��h�֮ɷ|�QAuto kill, �w�]���ȬO 3
int getAdvHate() { return 2; }

// �ع�Ĺ�}���Auto kill�n�۪���, $N�ɦۤw, $n�O���
string getAdvHateMsg() {
    return HIR"$N���h���s�D�G�����y�H�A��ѻ��n�����ڭ̡I�����o��e���I\n"NOR;
}

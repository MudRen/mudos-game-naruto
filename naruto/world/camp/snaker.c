#include <ansi.h>

// �����o�O�@�Ӱ}����
int isCamp() { return 1; }

// �}��W��
string getName() { return "�D�H"; }

// �ͦn�}��
string* getFriendly() { return ({}); }

// �Ĺ�}��
string* getAdversely() { return ({ "orc", "wheya", }); }

// (4) �R��, (3) �R�q, (2) �L�q, (1) �ͦn, (0) ����, (-1) �N�H, (-2) �ĵ�, (-3) �Ĺ�, (-4) ����

// ���a�b�Ӱ}�窺�n��C��h�֮ɷ|�QAuto kill�A�w�]���ȬO-3
int getHate() { return -2; }

// Auto Kill �ɡA�ҭn�۪���, $N�O�ۤw, $n�O���
string getHateMsg() {
    switch( random(3) ) {
        case 0: return HIR"$N���G�o���캡�����j�ۡG�������I��h����I���ۧa$n�I\n"NOR; break;
        case 1: return HIR"$N�۵ۡG�I���ڱڧ�h���A��I$n�u���L�O�䤤���@�I\n"NOR; break;
        case 2: return HIR"$N���j���D���I�б���$n���A��a�I\n"NOR; break;
    }
}

// ���a�b�Ĺ�}�窺�n�氪��h�֮ɷ|�QAuto kill, �w�]���ȬO 3
int getAdvHate() { return 2; }

// �ع�Ĺ�}���Auto kill�n�۪���, $N�ɦۤw, $n�O���
string getAdvHateMsg() {
    return HIR"$N���|�۪Z���j�ۡG����ڭ̴N�n�m�W$n����ײ����D���M���h���P�M�I\n"NOR;
}

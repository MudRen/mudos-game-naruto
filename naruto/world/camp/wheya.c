#include <ansi.h>

// �����o�O�@�Ӱ}����
int isCamp() { return 1; }

// �}��W��
string getName() { return "�˨��@��"; }

// �ͦn�}��
string* getFriendly() { return ({ "music" }); }

// �Ĺ�}��
string* getAdversely() { return ({ "snaker", "muye" }); }

// (4) �R��, (3) �R�q, (2) �L�q, (1) �ͦn, (0) ����, (-1) �N�H, (-2) �ĵ�, (-3) �Ĺ�, (-4) ����

// ���a�b�Ӱ}�窺�n��C��h�֮ɷ|�QAuto kill�A�w�]���ȬO-3
int getHate() { return -2; }

// Auto Kill �ɡA�ҭn�۪���, $N�O�ۤw, $n�O���
string getHateMsg() {
    switch( random(3) ) {
        case 0: return HIR"$N���D�G�o�o�F�˨��@�ڡA$n�N�u�������@���I\n"NOR; break;
        case 1: return HIR"$N�\�X�ƾԪ����A�A�@�����o�N����$n�I\n"NOR; break;
        case 2: return HIR"$N����$n���D�G�N�O$n�S�ƨӳo�̷o�áA�˨��@�ڰZ��e$n�����I\n"NOR; break;
    }
}

// ���a�b�Ĺ�}�窺�n�氪��h�֮ɷ|�QAuto kill, �w�]���ȬO 3
int getAdvHate() { return 3; }

// �ع�Ĺ�}���Auto kill�n�۪���, $N�ɦۤw, $n�O���
string getAdvHateMsg() {
    return HIR"$N���$n�ꮱ���D�G�j�D�Y�j�H���O�����L�츭�Ԫ̡A�N��$n��ۧa�I\n"NOR;
}

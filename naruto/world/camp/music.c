#include <ansi.h>

// �����o�O�@�Ӱ}����
int isCamp() { return 1; }

// �}��W��
string getName() { return "������"; }

// �ͦn�}��
string* getFriendly() { return ({ "wheya" }); }

// �Ĺ�}��
string* getAdversely() { return ({ "muye" }); }

// (4) �R��, (3) �R�q, (2) �L�q, (1) �ͦn, (0) ����, (-1) �N�H, (-2) �ĵ�, (-3) �Ĺ�, (-4) ����

// ���a�b�Ӱ}�窺�n��C��h�֮ɷ|�QAuto kill�A�w�]���ȬO-3
int getHate() { return -1; }

// Auto Kill �ɡA�ҭn�۪���, $N�O�ۤw, $n�O���
string getHateMsg() {
    switch( random(3) ) {
        case 0: return HIR"$N����$n�۹D�G�o�å�N�O�j�D�Y�j�H�s���J��I��L��_�ӡI\n"NOR; break;
        case 1: return HIR"$N���D�G�������Z�O$n���ӴN�ӻ����N�����a��I\n"NOR; break;
        case 2: return HIR"$N���D�G$n�ˤj���աI�j�D�Y�j�H��N�ڭ̤�����$n�������}�I\n"NOR; break;
    }
}

// ���a�b�Ĺ�}�窺�n�氪��h�֮ɷ|�QAuto kill, �w�]���ȬO 3
int getAdvHate() { return 2; }

// �ع�Ĺ�}���Auto kill�n�۪���, $N�ɦۤw, $n�O���
string getAdvHateMsg() {
    return HIR"$N����$n�۹D�G$n�O�츭���̻ᦳ�W�𪺤H�����I��L��^�h���I\n"NOR;
}

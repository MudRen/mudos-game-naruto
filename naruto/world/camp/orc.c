#include <ansi.h>

// �����o�O�@�Ӱ}����
int isCamp() { return 1; }

// �}��W��
string getName() { return "�b�~�H"; }

// �ͦn�}��
string* getFriendly() { return ({}); }

// �Ĺ�}��
string* getAdversely() { return ({ "snaker" }); }

// (4) �R��, (3) �R�q, (2) �L�q, (1) �ͦn, (0) ����, (-1) �N�H, (-2) �ĵ�, (-3) �Ĺ�, (-4) ����

// ���a�b�Ӱ}�窺�n��C��h�֮ɷ|�QAuto kill�A�w�]���ȬO-3
int getHate() { return -3; }

// Auto Kill �ɡA�ҭn�۪���, $N�O�ۤw, $n�O���
string getHateMsg() {
    return HIR"$N�@����$n���p�`���j��몺�R�۹D�G�u�ǩR�ӡI����I�v�C\n"NOR;
}

// ���a�b�Ĺ�}�窺�n�氪��h�֮ɷ|�QAuto kill, �w�]���ȬO 3
int getAdvHate() { return 3; }

// �ع�Ĺ�}���Auto kill�n�۪���, $N�ɦۤw, $n�O���
string getAdvHateMsg() {
    return HIR"$N�@����$n���p�`���j��몺�R�۹D�G�u�D�H�������I�ǩR�ӡI�v�C\n"NOR;
}

#include <ansi.h>

// �����o�O�@�Ӱ}����
int isCamp() { return 1; }

// �}��W��
string getName() { return "�y�H���|"; }

// �ͦn�}��
string* getFriendly() { return ({}); }

// �Ĺ�}��
string* getAdversely() { return ({}); }

// (4) �R��, (3) �R�q, (2) �L�q, (1) �ͦn, (0) ����, (-1) �N�H, (-2) �ĵ�, (-3) �Ĺ�, (-4) ����

// ���a�b�Ӱ}�窺�n��C��h�֮ɷ|�QAuto kill�A�w�]���ȬO-3
int getHate() { return -4; }

// Auto Kill �ɡA�ҭn�۪���, $N�O�ۤw, $n�O���
string getHateMsg() {
    return HIR"$N����a�۵ۡG�����@�W�y�H��b�O�ݤ��D$n���@���I���ѴN�n$n�����I\n"NOR;
}

// ���a�b�Ĺ�}�窺�n�氪��h�֮ɷ|�QAuto kill, �w�]���ȬO 3
int getAdvHate() { return 3; }

// �ع�Ĺ�}���Auto kill�n�۪���, $N�ɦۤw, $n�O���
string getAdvHateMsg() {
    return "";
}

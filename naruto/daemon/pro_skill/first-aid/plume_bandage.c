/* �Ф��^�a plume_bandage.c
*/

// �ݩ��ϧޯ�U�����~
string getProSkill() { return "first-aid"; }

// �߱o�����~���n���ޯ൥��
int getLearnLevel() { return 10; }

// ���~�W��
string getName() { return "�Ф��^�a"; }

// ²�z
string getBrief() {
    return "�i�H���W��_ HP 300 ���^�a�C";
}

// �ԭz
string getDetail() {
    string msg = "";
    msg += "�i�H���W��_ HP 300 ���^�a�C\n";
    msg += "��ϵ��Ťp��20�ŮɡA�s�@�ᦳ���|���ɫ�ϵ��šC\n";
    return msg;
}

// �s�y�����~�һݪ�����
mapping getStuff() {
    mapping stuff = ([
        "/world/area/muye/npc/item/plume.c": 1,  // �Ф�
    ]);
    return stuff;
}

// �s�y�����~��
string getProduct() {
    return "/world/pro_skill/first-aid/plume_bandage.c";
}

// �s�y���~�ɪ��T��
string makeMsg()
{
    return "$N��W�b�ӷb�h���A�}�l�s�y�u�Ф��^�a�v�C\n";
}

// ���~�O�_�j�w(�]�N�O�s�y���H�~���), (1:�O, 0:�_)
// ���G�j�w�����~�̦n�O����X�֪����~�A�_�h�j�w�|�V��
//     �j�w�����~�W�|�]�w set("binding", ����id)
//     �ҥH�n�P�_�Ӳ��~�O�_��Q�ϥδN�O�ˬd binding �O�_�ŦX���a��id�N��F
int isBinding() { return 0; }

// �i�H�ۭq�s�@����
int preCondition(object player)
{
    return 1;
}

// �i�H�ۭq�s�@��ĪG
int postCondition(object player)
{
    // �j��20�Ť��ണ��
    if( player->getProSkillLevel("first-aid") >= 20 )
        return 1;

    // �����|, ��Ϥɤ@��
    if( random(100) > 60)
        player->addProLevel("first-aid");

    return 1;
}

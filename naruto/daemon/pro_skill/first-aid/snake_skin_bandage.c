/* �D���^�a snake_skin_bandage.c
*/

// �ݩ��ϧޯ�U�����~
string getProSkill() { return "first-aid"; }

// �߱o�����~���n���ޯ൥��
int getLearnLevel() { return 0; }

// ���~�W��
string getName() { return "�D���^�a"; }

// ²�z
string getBrief() {
    return "�i�H���W��_ HP 100 ���^�a�C";
}

// �ԭz
string getDetail() {
    string msg = "";
    msg += "�i�H���W��_ HP 100 ���^�a�C\n";
    msg += "��ϵ��Ťp��10�ŮɡA�s�@�ᦳ���|���ɫ�ϵ��šC\n";
    return msg;
}

// �s�y�����~�һݪ�����
mapping getStuff() {
    mapping stuff = ([
        "/world/area/wild/npc/item/snake_skin.c": 1,  // �D��
    ]);
    return stuff;
}

// �s�y�����~��
string getProduct() {
    return "/world/pro_skill/first-aid/snake_skin_bandage.c";
}

// �s�y���~�ɪ��T��
string makeMsg()
{
    return "$N��W�b�ӷb�h���A�}�l�s�y�u�D���^�a�v�C\n";
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
    // �j��10�Ť��ണ��
    if( player->getProSkillLevel("first-aid") >= 10 )
        return 1;

    // �����|, ��Ϥɤ@��
    if( random(100) > 60)
        player->addProLevel("first-aid");

    return 1;
}

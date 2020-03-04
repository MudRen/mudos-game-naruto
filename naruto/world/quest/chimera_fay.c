#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

/* �����ȬO�_�୫�Ƹ�  return 0  ���୫��
                       return 1  �i����
   ��ĳ�̦n�]�w���୫�ơC
 */
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�����¼�";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�u"HIC"�۷Q����"NOR"�v�O�@�ۧ��ܥ|�P��Գy�������¼Ӥ۶H���ۦ��A�S����\n";
    msg += "�Ѯ𪺤F�ѬO�L�k�ϥγo�۪��A�]���R���n�D�A�h��X�˥��n�����~\n";
    msg += "�o�~����оɧA�ϥγo�өۦ��C�䤤���@�ˤѮ�w�������n��츭\n";
    msg += "���Ԫ̡u�����v�����A�o�i���]�O�Ҧ����~���̭��n���A�p�G�S��\n";
    msg += "����o�i���A�Q�n������H����S�Ƿ|���a�Ѯ�ڥ����i��C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 20;
}

/* �������Ȫ��e�m����A�i��O
        1. ���ŻݨD
        2. ¾�~�ݨD
        3. �رڻݨD
        4. �w�����Y�ǥ��ȻݨD
    �����A���i�H�ۥѵo���~�O�C
    �^�ǫD�s�Ȫ�ܲŦX����C
 */
int preCondition(object player) {
    if( player->query("guild") != "piece" ) return 0;
    if( player->query_skill("chimera fay", 1) ) return 0;
    if( player->query_class() == "work_sea" ) return 0;
    if( player->query_class() == "little_sea" ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/ship/npc/nami.c";   // �R��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�C�Y�I��.\n"NOR,
        "$N���D�G"HIG"$n���G�S��������g��A��Ѯ�w���Q�����O�ܮ���C\n"NOR,
        "$N���D�G"HIG"�h�츭�Ԫ̧���@��W�s�u�����v���Ԫ̮��u�Ѯ�w����v�a�C\n"NOR,
        "$N���D�G"HIG"�٦���L�����~�]���K�@�_���ӡC\n"NOR,
        "$N���D�G"HIG"��$n���������ڴN�о�$n������Ԫ����ѡC\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    return ([]);
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    mapping item = ([
        "/world/eq/armor/turtle.c": 1,             // �t��
        "/world/area/old_forest/npc/eq/leaf.c": 1, // ��
        "/world/area/ship/npc/item/paper.c": 1,    // �Ѯ�w����
    ]);
    return item;
}

// �������Ȫ����󰣤F�t�δ��Ѫ�
// 1. �j�����~
// 2. ���F�����ƶq���Ǫ����~
// ���ݭn���ܡA�٥i�H�ۭq�������ȱ���
// return 1, ����������, return 0;������
int postCondition(object player, object npc)
{
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/world/area/ship/npc/nami.c";   // �R��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"���~�ƻ��F�A�{�b�ӧi�D$n������Ԫ����ѡC\n"NOR,
        "$N���D�G"HIG"���Ԥ����ɥi�H�d���t�ү����άO�|�P���𸭸���...\n"NOR,
        "$N���D�G"HIG"���Ǿ𪺸��l�������������A�o�ɬݾ�֤]�\�|��M���C\n"NOR,
        CYN"$N���ѵۨ�L�����Ѯ𪺪���...\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIC"�۷Q����"NOR"�v\n";
    return msg;
}

/*  ���ȼ��y
    ���y���ӯ�ۥѵo���A�p�G
        1. ��o�g��
        2. ��o���~
        3. ��o�u��Buff
        4. �߱o�Y�ޯ�
        5. ��缾�a���A, ex: ��¾
 */
void reward(object player, object npc)
{
    player->set_skill("chimera fay", 2);
    tell_object(player, HIY"(�g�L�R�����оǫ�A�A�F�Ѥ۷Q���몺�ϥΤ�k�F)\n"NOR);
}

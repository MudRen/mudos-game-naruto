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
    return "�F�H������";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�F�H���D�`�ۻ����z���L�^�i���W�Ԥh�����ݡA�u"HIR"���X��P"NOR"�v��O�L\n";
    msg += "�̮��⪺�ۦ����@�I�ӿ��X��P�̭��n�����Ƣw���X�̪�o�ʪ����Y\n";
    msg += "���I�]����U����Τ��e�}�l�~�P���xĥ����Ĳ�A�F�H������@�H�W\n";
    msg += "�D���ʤH�֩w��O�F�ܦh���f�X�Өϥο��X��P�C�b�S�����X�S�Q��\n";
    msg += "�߳o�۪����p�U�A�F�H����ĳ�A��J�q�k�q�A�h�R�Ѣޢ��˳ǩһs�@\n";
    msg += "���q�j�Q�ѨӴ��ҿ��X��C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 15;
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
    if( player->query_skill("ketchup star", 1) ) return 0;
    if( player->query("level") < 15 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/ship/npc/usopp.c";   // �F�H��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�ܱo�N�a �f�c �f�X �f�X �f�X ����a���F�_�ӡC\n"NOR,
        "$N���D�G"HIG"���e�ڴN�O�a�o�ۥ��ѤF���ʦW���x�h�L�O�I\n"NOR,
        "$N���D�G"HIG"���G�{�b�⿻�X���Υ��F�I\n"NOR,
        CYN"$N�����a��F�@�U���U, ���G�Q�줰��D�N�C\n"NOR,
        "$N���D�G"HIG"�q�k�q�W���ӢѢޢ����˳Ǧb��q�j�Q�ѡC\n"NOR,
        "$N���D�G"HIG"�ڭ̴N�Ψ��ӨӴ��ҿ��X��a�I\n"NOR,
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
        "/world/area/sifa_isle/npc/food/spaghetti.c": 30,  // �q�j�Q��
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
    return "/world/area/ship/npc/usopp.c";   // �F�H��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"�ש󮳻��F�I�p�G�O$N�j�ݪ֩w��ִN�����F�I\n"NOR,
        CYN"$N�}�l�հt���X��...\n\n"NOR,
        "$N���D�G"HIG"�հt�n�աI�{�b�i�D$n���X��P���n�q...\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIR"���X��P"NOR"�v\n";
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
    player->set_skill("ketchup star", 2);
    tell_object(player, HIY"(�A�Ƿ|�F�F�H������...���سQ�F���Pı)\n"NOR);
}

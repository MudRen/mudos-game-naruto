#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

/* �����ȬO�_�୫�Ƹ�  return 0  ���୫��
                       return 1  �i����
   ��ĳ�̦n�]�w���୫�ơC
 */
int isNewly() { return 0; }

// ���ȦW��
string getName() {
    return "�a�ް��i";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "���F���j�a�Y��n�Y���ަסA�����S�Ʊ����ثe���a�޻P���ͽްt\n";
    msg += "�ءA�����@�طs���ޡA���L���ͽޤ����a�ޥ��̮_�ΡA��B�ö]��\n";
    msg += "�쥻��O�N���n�������S�֭ӥb���A�̫�u�n�e�U�����C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 2;
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
    if( player->query("level") < 2 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/old_forest/npc/test.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"�ڳ̪񥿦b��s�s�~�ت��ޡI\n"NOR,
        "$N���$n���D�G"HIG"���L���ͪ��޶]���n��...�l���ڥ����ĵh...\n"NOR,
        "$N���$n���D�G"HIG"�p�G���ů����ڮ��Ǹ�ƶܡH\n"NOR,
    });
        
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/wild/npc/babypig.c": 10,  // �p�ޥJ
        "/world/area/wild/npc/smallpig.c": 6,  // �ޥJ
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
// ���i�ƪ����~�ƶq�u��]�w��1, ���M���ȷ|�L�k����
mapping getItem() {
    mapping item = ([
        "/world/area/wild/npc/item/pig_gut.c": 20, // �޸z
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
    return "/world/area/old_forest/npc/test.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�e�ص��ޡA�n���ݨ�F�@�󤣥i��ĳ���ơC\n"NOR,
        "$N���Ħa���D�G"HIG"$n�u�����ڮ�����ưաI\n"NOR,
        CYN"$N�o�N���@�X�ӧQ�����! �u V �v  ��: �u ������...�v\n"NOR,
        "$N���$n���D�G"HIG"�o����§�N�浹$n�աI\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 70 �I�C\n";
    msg += "�Ȥl 1600 ��C\n";
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
void reward(object player, object npc) {
    player->add_point("learn", 70);
    tell_object(player, HIY"(�A��o�F 70 �I�ǲ��I�ơC)\n"NOR);
    player->add("bank", 1600);
    tell_object(player, HIY"(�A��o�F 1600 ��Ȥl�C)\n"NOR);
}

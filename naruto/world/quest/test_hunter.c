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
    return "���ӦҸխl�ͥ���";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�M�丹�X�P�l�O�ӧx�������ȡA���W�x�������A�`�`�����ҥͪ�\n";
    msg += "�۫H�ߡA�]���į����ͯS�O�Q�X�o�ӥ������U�ҥͧ����ҸաC\n";

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
    if( player->query("guild") != "hunter" ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/thorn_pine/npc/saze.c";  // �į�
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���n��$n�ݡM�����D���Ǥ���D�N�C�C\n"NOR,
        "$N���D�G"HIG"$n�q�L�����y�H�ҸդF�ܡH\n"NOR,
        "$N���D�G"HIG"�ڳo���ӥ��Ȥ]�\��W�[$n��Ҹժ�����C\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/thorn_pine/npc/butterfly.c": 10,  // �ʯv��
        "/world/area/thorn_pine/npc/crow.c": 10,       // ��H�~
        "/world/area/thorn_pine/npc/frog.c": 10,       // �i�H��
        "/world/area/thorn_pine/npc/hunter.c": 6,      // ���ӦҸզҥ�
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    return ([]);
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
    return "/world/area/thorn_pine/npc/saze.c";  // �į�
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"���S�����U$n�q�L�ҸաH\n"NOR,
        "$N���D�G"HIG"�N�⦨���F�y�H�]����]���۶ơA�~��V�O�a�C\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 1000 �I�C\n";
    msg += "�Ȥl 10000 ��C\n";
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
    player->add_point("learn", 1000);
    tell_object(player, HIY"(�A��o�F 1000 �I�ǲ��I�ơC)\n"NOR);
    player->add("bank", 10000);
    tell_object(player, HIY"(�A��o�F 10000 ��Ȥl�C)\n"NOR);
}

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
    return "�l�ܬr�j��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�]��ť�������Ԫ̶}�l�ϥάr�j��V�m�ۤv���U�ԡA�o�˪��Ԫ̤�\n";
    msg += "����r�ʩ�ܤ���j�P�A�P�ɤ]�i��ϥλj��r�ӹ�I��L���ĤH\n";
    msg += "�A�W�Ե���������v�ҥ浹�����ȶ}�l��s�r�j�諸�ߩʡA�]����\n";
    msg += "�T�Ӧh�����@�@��z�ӨS�ɶ��h��a�ҹ�A�{�b�K�N���ȥ浹�A�h\n";
    msg += "���������Ҭd�C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 25;
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
    if( player->query("level") < 25 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/bone/npc/gau.c";  // ����
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"���n�N��A�Ӧ��F�䤣�}���C\n"NOR,
        "$N���$n���D�G"HIG"��·�$n���H���q�s�}���ڮ��Ǭr�j�諸��ƶܡH\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/whale_island/npc/spider.c": 20,     // �p�r��
        "/world/area/whale_island/npc/spider2.c": 20,    // �j���r��
        "/world/area/whale_island/npc/spider3.c": 20,    // �����r��
        "/world/area/whale_island/npc/spider4.c": 20,    // ���ܬr��
        "/world/area/whale_island/npc/spider5.c": 20,    // ���ܼ@�r�j��
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    mapping item = ([
        "/world/area/whale_island/npc/item/spider-leg.c": 130,   // �j��L
        "/world/area/whale_island/npc/item/spider-eye.c": 70,   // �j�ﲴ��
        "/world/area/whale_island/npc/item/spider-venom.c": 30, // �j��r�G
    ]);
    return item;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/world/area/bone/npc/gau.c";  // ����
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

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N������Ʊ��ۻ��D�G"HIG"��...�o�ǻj���~��b���̪G�M�ܦM�I...\n"NOR,
        "$N���D�G"HIG"�����n�i�D���v�j�H�o�Ʊ����Y���ʡC\n"NOR,
        "$N���$n���D�G"HIG"�o�����Ȩ��W$n�F�C\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 2500 �I�C\n";
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
    player->add_point("learn", 2500);
    tell_object(player, HIY"(�A��o�F 2500 �I�ǲ��I�ơC)\n"NOR);
}

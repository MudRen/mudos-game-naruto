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
    return "���@�n��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�O�d��ť���b���Z�����~�M���ؿ��ɾ֦��W���u�ɦץլءv����\n";
    msg += "�f�P�A�����r�l�A�O�����ɮƲz�̴Ϊ��ɦסC��O�O�d�ɬ��F���X\n";
    msg += "�̴Ϊ��ɦ׮Ʋz�A��B��H�������^�o���ɦסC���F���}�a�׽��\n";
    msg += "�z�ɦסA�O�d���٭n�D�A�i�D�L�p������o�ؿ��ɪ���k�C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 10;
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
    if( player->query("level") < 10 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/whale_island/npc/tu-qian-xie.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�����a���p�Ĥl�������۸���.\n"NOR,
        "$N�����a�ݹD�G"HIG"$n��ť�L�u�ɦץլءv�ܡH\n"NOR,
        "$N���$n���D�G"HIG"ť���o�ئצ׽��A���I�O�ڤ۪��ɦת��I\n"NOR,
        "$N���$n���D�G"HIG"���L�e�̫D�`���ɡI�ڧ�H�h�����Q���ˤF�I\n"NOR,
        "$N���$n���D�G"HIG"$n�����ڮ��@�Ǧ^�ӶܡH\n"NOR,
    });
        
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/lake/npc/crab.c": 5,  // �ɱN
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    mapping item = ([
        "/world/area/lake/npc/item/crab.c": 10, // �ɦץլ�
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
    return "/world/area/whale_island/npc/tu-qian-xie.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���������_�R��!!!\n"NOR,
        "$N���Ħa���D�G"HIG"�ӴΰաI�o�N�O�ǻ������ɦץլءI\n"NOR,
        "$N���$n���D�G"HIG"�����e����k�O�o�˶ܡH�ڪ��D�F�C\n"NOR,
        "$N���$n���D�G"HIG"�u�O�ӷP��$n�����U�F�I\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 400 �I�C\n";
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
    player->add_point("learn", 400);
    tell_object(player, HIY"(�A��o�F 400 �I�ǲ��I�ơC)\n"NOR);
}

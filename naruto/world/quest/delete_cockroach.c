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
    return "�����j�@��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�R�l�p�j�a�]����|�����O�͡A�ҥH�����]�S�O�h�I�ר�O�j����\n";
    msg += "�����A�C���X�{���~���R�l�p�j�����W�b�Ѥ����U�ӡA�p�G���_\n";
    msg += "�ӧ�O�s�a�����n�F�A�����ܪ��ӥX�C�o�ؤ����x�����ͬ��o�A�]\n";
    msg += "���Q�L�F�A�M�w�Ӧ�������ʡC\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 4;
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
    if( player->query("level") < 4 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/muye/npc/ai.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�D�`�`�Ȫ��j�n�y�s�T�T\n"NOR,
        "$N��i�a���D�G"HIG"���}�I�������n�a��ڡI\n"NOR,
        "$N���$n���D�G"HIG"���I���ڥ����e�I\n"NOR,
    });
        
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/muye/npc/cockroach2.c": 15,         // �j����
        "/world/area/whale_island/npc/cockroach2.c": 15, // �j������
        "/world/area/muye/npc/cockroach3.c": 10,         // ������
        "/world/area/whale_island/npc/cockroach3.c": 10, // ��������
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    mapping item = ([
        "/world/area/muye/npc/item/cr_antenna.c": 10,    // ����Ĳ��
        "/world/area/muye/npc/item/cr_feet.c": 10,       // �����}
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
    return "/world/area/muye/npc/ai.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�D�`�`�Ȫ��j�n�y�s�T�T\n"NOR,
        "$N�`�Ȧa���D�G"HIG"�֥s$n������������^�ӡI\n"NOR,
        "$N�`�Ȧa���D�G"HIG"���ȵ����F�I���ֱa���������������}�I\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 160 �I�C\n";
    msg += "�Ȥl 300 ��C\n";
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
    player->add_point("learn", 160);
    tell_object(player, HIY"(�A��o�F 160 �I�ǲ��I�ơC)\n"NOR);
    player->add("bank", 300);
    tell_object(player, HIY"(�A��o�F 300 ��Ȥl�C)\n"NOR);
}

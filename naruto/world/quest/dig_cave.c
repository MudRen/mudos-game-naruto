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
    return "�s�}�}�w";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�]���H���q�H�����W�}�w���_��s�}�}��@�b��M��J�j�q���j\n";
    msg += "��ӳQ�����}�w�A�����`�Ȥs�}�̪��j��|�]�i���̦M�`����\n";
    msg += "�A�ҥH�M�w�ά��ħ�}�f���ʦ�A���O�����ĳo�ئM�I�����~�@\n";
    msg += "��ө��ڥ����|��A���H���q�����˳z�F�����C\n";

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
    if( player->query("level") < 15 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/whale_island/npc/village_head.c";  // �H���q����
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���W�U���q��$n�A���G���b����$n���԰���O...\n"NOR,
        "$N�ݵ�$n���D�G"HIG"$n���D�ڭ̧��l�_�䦳�Ӥs�}�a�I\n"NOR,
        "$N���D�G"HIG"�s�}�٨S�������o��i�F�@��j��I\n"NOR,
        "$N����a���D�G"HIG"�ҥH�ڨM�w�ά��ħ�s�}�����F�I\n"NOR,
        "$N���$n���D�G"HIG"�i�O��B���R���쬵�ġI$n�ण�����ڶR�I�^�ӡH\n"NOR,
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
        "/world/area/thorn_pine/npc/item/firepill.c": 10,  // ����
        "/world/area/thorn_pine/npc/item/bom.c": 5,        // ���u
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
    return "/world/area/whale_island/npc/village_head.c";  // �H���q����
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���������_�R��!!!\n"NOR,
        "$N�����a���D�G"HIG"�����I�ݧګ��½���s�j��I\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 800 �I�C\n";
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
    player->add_point("learn", 800);
    tell_object(player, HIY"(�A��o�F 800 �I�ǲ��I�ơC)\n"NOR);
}

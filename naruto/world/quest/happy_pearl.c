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
    return "���]����";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�����~����e�U�����n���ȡI���ȥؼЬO��a�̪�~�R�i���s\n";
    msg += "�_���A���]�I���L���Q���F�W���h��O�A�H�K���X�����j�ï]��\n";
    msg += "�t�F�ƴN�n�F�C\n";

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
    return "/world/area/lake/npc/gin.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���Ʀa���D�G"HIG"�����j���~��a�I�a�̫���S�I�N�����O�I\n"NOR,
        "$N���Ʀa���D�G"HIG"�A�ݬݡI�����_...������...���۰�....�����ɦ����I\n"NOR,
        CYN"$N�G�s�@�n, ���y�u���]�w��?!?!?�v����.\n"NOR,
        "$N��W�a���D�G"HIG"�Q�ѶR�����]��򤣨��F�I\n"NOR,
        "$N����$n���D�G"HIG"�A�A�A�sԣ�W�r�I�֥h���ڧ���]�I\n"NOR,
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
        "/world/area/lake/npc/item/pearl.c": 10,  // ���j�ï]
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
    return "/world/area/lake/npc/gin.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"���ӤF�ܡH��򤣬O���]�O�I\n"NOR,
        CYN"$N�C�Y�I��.\n"NOR,
        "$N���D�G"HIG"�o�Ǭݰ_�Ӧn���]�����I\n"NOR,
        "$N���$n���D�G"HIG"�J�M�F����F��M�n���I���y�աI\n"NOR,
        "$N���$n���D�G"HIG"�����j����X��]�n���ǡI\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�Ȥl 60000 ��C\n";
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
    player->add("bank", 60000);
    tell_object(player, HIY"(�A��o�F 60000 ��Ȥl�C)\n"NOR);
}

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
    return "���̤���";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�o�O���y�H�ɮv�ŽէƤZ�Ҧ������ȡA�ت��O���Y�N�B�J�s�Ҭɪ�\n";
    msg += "�H����|����s�����̪����d�C\n";

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
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/thorn_pine/npc/hxh_adv_master.c";  // �ŽէƤZ
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���W�U���q��$n�A���G���b����$n���԰���O...\n"NOR,
        "$N���$n���D�G"HIG"�t���h�]��ɭԤF�A�A�U�h$n�i��|�J��j�j���ĤH�a�C\n"NOR,
        "$N���D�G"HIG"���U�o�ӥ��ȧa�I�h�ݬݰʪ������̪����A�I\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/lake/npc/zombie3.c": 1,                // �G�ͤ�
        "/world/area/wild/npc/kingpig.c": 1,                // �½ޤ�
        "/world/area/echo/npc/mouse_king.c": 2,             // �a����
        "/world/area/muye/npc/mouse_king.c": 2,             // ����
        "/world/area/whale_island/npc/cockroach_king.c": 3, // ������
        "/world/area/muye/npc/cockroach_king.c": 3,         // ����
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
    return "/world/area/thorn_pine/npc/hxh_adv_master.c";  // �ŽէƤZ
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"���Q�ѨM�F�ܡH\n"NOR,
        "$N���$n���D�G"HIG"�ܦn�A�o�˪��D�ԥH��i��|�`�J���C\n"NOR,
        "$N���$n���D�G"HIG"�J����󪺬D�Գ��n�p����b�ӸѡC\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 1400 �I�C\n";
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
    player->add_point("learn", 1400);
    tell_object(player, HIY"(�A��o�F 1400 �I�ǲ��I�ơC)\n"NOR);
}

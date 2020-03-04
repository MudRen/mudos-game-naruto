#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

/* �����ȬO�_�୫�Ƹ�  return 0  ���୫��
                       return 1  �i����
   ��ĳ�̦n�]�w���୫�ơC
 */
int isNewly() { return 0; }

// ���ȦW��
string getName() {
    return "�d�X���ߨ�";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�_�c�H�d�X�b�p��q�W�ݤF�X�Q�~�A���F�u�@�ڤ����_�ä��~��\n";
    msg += "�h�F�@�ӷs���@��A�N�O�u�@�q�W���U�ج��~�̪��w���A���L�b\n";
    msg += "�m���_�c�����餤�~�M���\�h�H�O���~�v�A�L�̤w�g���A�F�ܦh\n";
    msg += "�����~�A���Ǧ������L�����~�ǳƤj�|�����c��A�]���d�X��\n";
    msg += "�h�U�F�@�ӨM�w�A�Ʊ榳�H��⨺�s�Q���A�����~�M���C\n";

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
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/barren_isle/npc/ka.c";  // �_�c�H�d�X
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���n��$n�ݡM�����D���Ǥ���D�N�C�C\n"NOR,
        "$N���D�G"HIG"�i�c������~�M���W���~���D�N�F...\n"NOR,
        "$N���D�G"HIG"���ǳQ���A�����~�ٷ|��ŧ��L���~...\n"NOR,
        "$N���D�G"HIG"$n�����U�ڲM�����ǳQ���A�����~�ܡH\n"NOR
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/barren_isle/npc/monkey.c": 10,  // ���ѵU
        "/world/area/barren_isle/npc/pig.c": 10,     // ���Y�ި�
        "/world/area/barren_isle/npc/rabbit.c": 10,  // �D��
        "/world/area/barren_isle/npc/corsair.c": 6,  // ����Ҹծ���
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
    return "/world/area/barren_isle/npc/ka.c";  // �_�c�H�d�X
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"���~�̯u�O��p�F...�ڤ@�w�n�O�@�n�Ѿl�����~�I\n"NOR,
        "$N���D�G"HIG"�D�`����$n�������A�o�ǬO�ڪ��@�I�߷N�C\n"NOR,
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

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
    return "�p�ը���";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "��ӥE��A����¶�M�w�浹�A�@�Ӹոը��⪺���ȡA�L�n�D�A�h�U\n";
    msg += "�a���y�p�����ʪ��A���K�F�ѷ�a���a�z���ҡC\n";

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
    return "/world/area/whale_island/npc/teacher2.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���W�U���q��$n�A���G���b����$n���԰���O...\n"NOR,
        "$N���$n���D�G"HIG"���ӥ��ȭn��B���y�p���ʪ��A�]���d��ܼs��C\n"NOR,
        "$N���D�G"HIG"��O�@�Ӹը��⪺���ȧa�A$n������ܡH\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/wild/npc/babypig.c": 20,        // �p�ޥJ
        "/world/area/whale_island/npc/rabbit.c": 15, // �p�ը�
        "/world/area/wild/npc/smallwolf.c": 10,      // �p�T
        "/world/area/wild/npc/smallsnake.c": 10,     // �p�D
        "/world/area/old_forest/npc/monkeyc.c": 10,  // �p�U
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
    return "/world/area/whale_island/npc/teacher2.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"�ܦn�A�ݨӳo�˪����Ȥw�g������$n�F�C\n"NOR,
        "$N���$n���D�G"HIG"�o�����ȷQ����F�ѦU�Ϥ]�ܦ����U�a�C\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 200 �I�C\n";
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
    player->add_point("learn", 200);
    tell_object(player, HIY"(�A��o�F 200 �I�ǲ��I�ơC)\n"NOR);
}

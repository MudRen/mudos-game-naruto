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
    return "�ĤG�M��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�����H���P�n�O���ѨS���i���A���ۤv�Z���O�L�ƥi���H�]���M�w\n";
    msg += "�ǲ߲ĤG�M���A�ʽ�P�����ۦ����u�����ɡv���L�����ɤ]�O�@��\n";
    msg += "���`���޳N�A�S��k�L�v�۳q�������H�����дo���w�C\n";

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
    return "/world/area/muye/npc/fishing_master.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���ۻy�G"HIG"���ɫ��o������O�I\n"NOR,
        "$N���ۻy�G"HIG"�ڥ����٥H����쳽�@�˩O...\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/whale_island/npc/crab.c": 20,  // �p����
        "/world/area/whale_island/npc/crab2.c": 6,  // ����
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
    return "/world/area/muye/npc/fishing_master.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�e�ص��ޡA�n���ݨ�F�@�󤣥i��ĳ���ơC\n"NOR,
        "$N���$n���D�G"HIG"�p���n���ɤW�U���I\n"NOR,
        "$N���$n���D�G"HIG"�n�e���ڶܡI�ӷP�¤F�I\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 140 �I�C\n";
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
    player->add_point("learn", 140);
    tell_object(player, HIY"(�A��o�F 140 �I�ǲ��I�ơC)\n"NOR);
}

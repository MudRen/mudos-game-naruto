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
    return "�}�a��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�H���q�ī~�ӤH���F�����ħ��ɱ`�b���U�a�A�̪�o�o�{�\�h����\n";
    msg += "���ħ����Q�}�a�F�A�o��׭��N�O�^���s�}�̪��a���̡C\n";

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
    return "/world/area/whale_island/npc/piller.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�u���v���@�n�ĤF�f��C\n"NOR,
        "$N���D�G"HIG"�̪��ħ��u�ʡA�j�������Q�a���}�a�F�C\n"NOR,
        "$N���D�G"HIG"�u�Ʊ榳�H��v�@�v�o�Ǧa���C\n"NOR,
    });
        
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/echo/npc/mouse1.c": 10, // �a��
        "/world/area/echo/npc/mouse2.c": 7,  // �Φa��
        "/world/area/echo/npc/mouse3.c": 4,  // �D�a��
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
    return "/world/area/whale_island/npc/piller.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"$n�u�������F���Ǧa���H�I\n"NOR,
        "$N���Ħa���D�G"HIG"�o�U�l���ξ���ħ������D�աI\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 180 �I�C\n";
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
    player->add_point("learn", 180);
    tell_object(player, HIY"(�A��o�F 180 �I�ǲ��I�ơC)\n"NOR);
}

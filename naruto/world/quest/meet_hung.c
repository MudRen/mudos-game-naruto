/*  travel_muye.c
        
    write by Acme       - 2007.02.05
 */

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
    return "�A���y�H¾�~";
}

// ���ȴy�z
string getDetail() {
    string msg;
        
    msg  = "�p�G�A�Q�A���y�H¾�~�S�⪺�ܡA�A�i�H�h�бСu�y�H�ɲ߾Ǯաv���C�K�ޡC\n";
    msg += "��m�N�b�X�F�u�̯S���s���v����_��A�A���ӫܮe���i�H��쪺�C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 1;
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
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/whale_island/npc/village_head.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�p�G�A�Q�A���y�H¾�~�S�⪺�ܡA�A�i�H�h�бСu�y�H�ɲ߾Ǯաv���C�K�ޡC\n",
        "$N���$n���D�G��m�N�b�X�F�u�̯S���s���v����_��A�A���ӫܮe���i�H��쪺�C\n",
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
    return "/world/area/whale_island/npc/teacher.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�A�n�I\n",
        CYN"$N�r�֪��L���ۡC\n"NOR,
        "$N���$n���D�G�A�Q�A���y�H�O����ڡH\n",
        "$N���$n���D�G�y�H�N�O�i�H�Q�Ω���O�I�i�U�ة��O��¾�~�C\n",
        "$N���$n���D�G�ө���O�j���i�H���T�j���C\n",
        "$N���$n���D�G�Ĥ@�G�j�ƨt�B�ĤG�G�ܤƨt�B�ĤT�G��{�t�B�ĥ|�G��X�t�B�Ĥ��G�ާ@�t�B�Ĥ��G�S��t\n",
        "$N���$n���D�G�Q�����ѥ[�y�H�ɲ߶ܡH�ڭ̫D�`�w��A���u���W�v\n",
        "$N���$n���D�G�p�G�A�w�g�O�ڭ̪��ǭ��A�ӥB�Q�ոլݡu�����ҡv���ܡA�i�H�ӧ�ڡC(���O�Gsay ������)\n",
    });
        
    return msg;
}

string getReward()
{
    return "�ǲ��I�� 20 �I";
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
    player->add_point("learn", 20);
    tell_object(player, HIY"(�A��o�F 20 �I�ǲ��I�ơC)\n"NOR);
}

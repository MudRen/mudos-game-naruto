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
    return "�s��շ�";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�o�O�s��ɮv���ߪ��ҵ����A���̫���ȡA�ت��O���U�A����b�|\n";
    msg += "���X�Y�ɦ��ӻ��P���a�����j���g��A�֥h�ݬݳo�Ӧa��a�I��\n";
    msg += "�F�ت��a�������ӷ|�ݨ�t�@��s��ɮv�A�N��L�������ȧa�C\n";
msg += "�Ӥ��|�ѰO�a�I�F�a�I�H  �a�I�b�u"HIY"�ѤW�H��"NOR"�v�F��u"HIC"���F����"NOR"�v\n";

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
    return "/world/area/wizard/npc/zhang.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"$n�䤣��m�\���a��ܡH\n"NOR,
        "$N���D�G"HIG"���ڷs��ɮv���ߪ�����$n�@�Ӧn�a��a�I\n"NOR,
        "$N���D�G"HIG"��m�N�b�q�o�̩���(w)�����᪺�a��"HIW"[�ѤW�H��]"HIG"��I\n"NOR,
        "$N���D�G"HIG"�i�H��J map �h��@�ӥs"HIC"[���F����]"HIG"���a��C\n"NOR,
        "$N���D�G"HIG"�p�G�䤣��O�I�N���n(s)���A�ݨ�[����ǰe]���᩹�F(e)�A�N�|�ݨ�աI\n"NOR,
        "$N���$n���D�G"HIG"�[�o�a$n�I�Ʊ�$n�m�\�r�֡I\n"NOR,
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
    return "/world/area/wizard/npc/fei.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"���ӬO���ߪ��s$n�Ӫ��a�I\n"NOR,
        "$N���$n���D�G"HIG"��J "HIY"seedoor"HIG" ��^���ѲŸ����X���Ʀr�A�N�i�H�i�h�F�I\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�Ȥl 10 ��C\n";
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
    player->add("bank", 10);
    tell_object(player, HIY"(�A��o�F 10 ��Ȥl�C)\n"NOR);
}

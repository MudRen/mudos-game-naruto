/*  newbie.c
        
    write by Acme       - 2007.02.07
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
    return "��ӥE��";
}

// ���ȴy�z
string getDetail() {
    string msg;
        
    msg  = "�o��i���ͱo�ܰڡA�֩w�O�s�Ӫ��C\n\n";
    msg += "�p�G�A��o�ӥ@�ɤ��O�ܤF�ѡA�q�`�A�i�H�[�ݻ������C(���O�Ghelp)\n";
    msg += "�Y�O�b�ާ@�W�������x�A�]�i�H�D�U���O�����C(���O�Ghelp cmds)\n\n";
    msg += "�t�~�A�A�b�������ȫ�A�i�H�Q�� quest ���O�Ӭd�ߥثe�w���������ȡC\n";
    msg += "�åB�i�� quest <�s��> �ݥ��Ȫ��Բӻ����C\n\n";
    msg += "ť���b�u�s��ǰ�v�����ߪ����Q�n��A�O�I\n";
    msg += "�X�F�u�Ův�����v��A���F���A�A�K�i�H�ݨ�u�s��ǰ�F�v�C\n";

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
    return "/world/area/wizard/npc/chi.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�o��i���ͱo�ܰڡA�֩w�O�s�Ӫ��C\n",
        "$N���$n���D�G�p�G�A��o�ӥ@�ɤ��O�ܤF�ѡA�q�`�A�i�H�[�ݻ������C(���O�Ghelp)\n",
        "$N���$n���D�G�Y�O�b�ާ@�W�������x�A�]�i�H�D�U���O�����C(���O�Ghelp cmds)\n",
        "$N���$n���D�G�t�~�A�A�b�������ȫ�A�i�H�Q�� quest ���O�Ӭd�ߥثe�w���������ȡC\n",
        "$N���$n���D�G�åB�i�� quest <�s��> �ݥ��Ȫ��Բӻ����C\n",
        "$N���$n���D�Gť���b�u�s��ǰ�v�����ߪ����Q�n��A�O�I\n",
        "$N���$n���D�G�X�F�u�Ův�����v��A���F���A�A�K�i�H�ݨ�u�s��ǰ�F�v�C\n",
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
    return "/world/area/wizard/npc/zhang.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�A�ӰաI�ڵ��A�ܤ[�F�O�I\n",
        CYN"$N���������F�X�n�C\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    return "�ǲ��I�� 20 �I�C\n";
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
    tell_object(player, HIY"(�A��o�F20 �I�ǲ��I�ơC)\n"NOR);
}

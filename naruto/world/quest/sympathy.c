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
    return "�ӦP�D�X";
}

// ���ȴy�z
string getDetail() {
    string msg;
        
    msg  = "�g�H���v�浹�A�@�ʥΪG�֫ʦ��H�A���ާA�Υ����k���S\n";
    msg += "��k���}�o�ʫH�C�H�W�����G�浹�D�ڪ��D���C\n";

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
    return "/world/area/old_forest/npc/wizard3.c";  // �g�ۥD��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"���̩ԭw�R...\n"NOR,
        CYN"$N�����a��F�@�U���U, ���G�Q��F����D�N.\n"NOR,
        "$N���$n���D�G"HIG"�ѤF�~�ӤH���|���g�y...\n\n"NOR,
        "$N���$n���D�G"HIG"$n...���S���������ڤ@�Ӧ��H\n"NOR,
        "$N���$n���D�G"HIG"�ڦ��ʫH�Q�ǵ��������t�@�첽�v�C\n"NOR,
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
    return "/world/area/echo/npc/snake02.c";  // �D��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���ǳƧ���$n...$n���W���X�g�H���v���H��$N�C\n"NOR,
        CYN"$N���L�H���ܻ��P���N���}�F�C\n"NOR,
        CYN"$N�w�R���ݵ۫H��....\n\n"NOR,
        "$N��_�Y���D�G"HIG"��ӥ��`�b�����ɷ|���H���n���O�L�b��ڥ��...\n"NOR,
        "$N���$n���D�G"HIG"�d���Ӧ��e�H���W$n�F�C\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 400 �I�C\n";
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
    player->add_point("learn", 400);
    tell_object(player, HIY"(�A��o�F 400 �I�ǲ��I�ơC)\n"NOR);
}

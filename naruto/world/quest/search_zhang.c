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
    return "�M��ѱi";
}

// ���ȴy�z
string getDetail() {
    string msg;
        
    msg  = "�]���@�����U�O�H�h�a�^�����ѹ�b�O�ӨS�Ĳv�F�I���ʸU�o���M\n";
    msg += "�w�ФH��ѱi�a�^�a���A�u�n�����ѱi�a�^�����֩w�״I�I\n";

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
    return "/world/area/echo/npc/wang.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�w�w��! �@��|���ܪ������{�{�ʤH!\n"NOR,
        "$N���$n���D�G"HIG"$n�N�O�����ڧ�ѱi���ܡH\n"NOR,
        "$N���$n���D�G"HIG"�u�n���ѱi�a�^�����ڵN�ѡA�������O���D�I\n"NOR,
        "$N���$n���D�G"HIG"ť�����H�b�H���ӪL�ݹL�L�I�֥h�֦^��I\n"NOR,
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
    return "/world/area/echo/npc/zhang.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�u���v���@�n�ĤF�f��C\n"NOR,
        "$N���L�a���D�G"HIG"�ڪ��k��Q�D�H��h�F�I�{�b�����߱����ѩO�H\n"NOR,
        "$N���$n���D�G"HIG"���L$n�o�򨯭W���]�ӤF�A��$n�Ť�^�h�]���n�N��C\n"NOR,
        "$N���$n���D�G"HIG"�o�I�F��A�N���U�a�C\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 100 �I�C\n";
    msg += "�Ȥl 500 ��C\n";
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
    player->add_point("learn", 100);
    tell_object(player, HIY"(�A��o�F 100 �I�ǲ��I�ơC)\n"NOR);
    player->add("bank", 500);
    tell_object(player, HIY"(�A��o�F 500 ��Ȥl�C)\n"NOR);
}


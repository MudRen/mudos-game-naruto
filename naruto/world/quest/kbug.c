/*  TestQuest.c
        
        �@�ӥΨӴ��ե��Ȩt�Υ��T�ʪ����եΥ��ȡA�]�O���ȼ��g���d�ҡC
        
        �ثe���Ȥ䴩�����G
                1. �����Y�Ǽƶq���Ǫ�
                2. ���o�Y�Ǽƶq�����~
                3. �y�X�ʥ���  (�N���YA�n�A�h��YB�A�Y�i��������)
        
        �`�N�G�]���H�ɦW���ѧO�A�b�]�w���ɦW�O�o�[�W .c 
        
    write by Acme       - 2007.02.04
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
    return "�M���`��";
}

// ���ȴy�z
string getDetail() {
    string msg;
        
    msg  = "�츭���U���D�`�ζV�ӶV�h�F�A�ϱo�q�Υͦs�Ŷ��D���Y���¯١C\n";
    msg += "������U�����@�Ǯ`�Χa�I\n";

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
    return "/world/area/muye/npc/nai.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�`�`���ĤF�@�f��C\n"NOR,
        "$N���$n���D�G�츭���U���D�`�ζV�ӶV�h�F�A�ϱo�q�Υͦs�Ŷ��D���Y���¯١C\n",
        "$N���$n���D�G�A���������U�����@�Ǯ`�ζܡH\n",
    });
        
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/muye/npc/cockroach.c": 20,  // ����
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
    return "/world/area/muye/npc/nai.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�u�O�ӷP�§A�F�A���o�@�ɤW�ͪ��������o���ġI\n",
        CYN"$N�ּ֪���R���СC\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 100 �I�C\n";
    msg += "�Ȥl 100 ��C\n";
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
    player->add("bank", 100);
    tell_object(player, HIY"(�A��o�F 100 ��Ȥl�C)\n"NOR);
}

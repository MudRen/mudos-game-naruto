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
    return "�����G��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "���Z�򩳪���}���A�����֪��G�ͦb���ʡA�츭�Ԫ̧����N���a\n";
    msg += "�o�i���V�m�Ԫ̾԰��ޥ����a��A�i�O�̭����G�͹�b�O�Ӧh�F�A\n";
    msg += "�]���츭�Ԫ̧��}�l�l������O���H�����M���G�͡C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 15;
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
    if( player->query("level") < 15 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/muye/npc/ka.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���W�U���q��$n�A���G���b����$n���԰���O...\n"NOR,
        "$N���D�G"HIG"�츭���̪�b�M��@�妳��O���H�����M���G�͡C\n"NOR,
        "$N���$n���D�G"HIG"$n���S�����������H\n"NOR,
    });
        
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/lake/npc/zombie.c": 30,  // �G��
        "/world/area/lake/npc/zombie2.c": 2,  // �G��(�L�_)
        "/world/area/lake/npc/zombie4.c": 2,  // �G��(�k��)
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
    return "/world/area/muye/npc/ka.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"�o�˻G�����ӤS��֤F���֧a�C\n"NOR,
        "$N���Ħa���D�G"HIG"�D�`�P��$n�����U�C\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 1200 �I�C\n";
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
    player->add_point("learn", 1200);
    tell_object(player, HIY"(�A��o�F 1200 �I�ǲ��I�ơC)\n"NOR);
}

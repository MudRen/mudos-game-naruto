#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

/* �����ȬO�_�୫�Ƹ�  return 0  ���୫��
                       return 1  �i����
   ��ĳ�̦n�]�w���୫�ơC
 */
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�P���@�R";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "���F�P�d���F��}�n�����Y�A�V�m�]�O�D�`���n���A�]��������n�D\n";
    msg += "�A��@�ɬF������a�u�q�k�q�v�W�V�M���V�m�����S�����E�k����\n";
    msg += "�i��X����աA�F�Ѩ�V���N�����n�C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 20;
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
    if( player->query("guild") != "muye" ) return 0;
    if( player->query_class() == "inferior" ) return 0;
    if( player->query_skill("double fang", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/muye/npc/yaa.c";   // �����
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"���q�������n�d���P�D�H���۷f�t�~��o���ĪG�C\n"NOR,
        CYN"$N�C�Y�I��.\n"NOR,
        "$N���D�G"HIG"�q�k�q�n�����ئW�s�k���������A�N�O�M���V�m�����C\n"NOR,
        "$N���D�G"HIG"$n�h�q�k�q���Ѩ��ѥL�̪��V���N�a�C\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/sifa_isle/npc/guarddog.c": 5,  // �k������
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
    return "/world/area/muye/npc/yaa.c";   // �����
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�u��v���@�n�M�@�Ʊ����S��ˤl�C\n"NOR,
        "$N���D�G"HIG"�J�M$n�w�g�q�L�F����A�o�N��$n���q���a�C\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIC"���q��"NOR"�v\n";
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
void reward(object player, object npc)
{
    player->set_skill("double fang", 2);
    tell_object(player, HIY"(�g�L����������ɡA�A�F�ѨϥΤ��q����¬���F)\n"NOR);
}

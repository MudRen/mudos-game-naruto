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
    return "�K�����";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�K���O��׶ˮ`���S��ޡA���������ܦp�K�@�˰�w�A�u�K���E��v\n";
    msg += "�N�O�K���j�ƨ��m������ҧ������̱j���m�ޥ��C���|�խn�D�A�h��\n";
    msg += "�X�ؾ֦��Ҵߪ��ͪ��H�K�F�Ѩ��m������C\n";

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
    if( player->query("guild") != "piece" ) return 0;
    if( player->query_skill("body gang", 1) ) return 0;
    if( player->query_class() == "work_sea" ) return 0;
    if( player->query_class() == "little_sea" ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/sifa_isle/npc/bruno.c";   // ���|��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�C�Y�I��.\n"NOR,
        "$N���D�G"HIG"$n�Q�n�ǲ��K�����i���ޯ��...\n"NOR,
        "$N���D�G"HIG"�h�F�ѥҴߥͪ������m��O���K���չ�O�a�C\n"NOR,
        "$N���D�G"HIG"�p�G�������ȧڴN��$N�C\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/whale_island/npc/crab3.c": 5,  // �j����
        "/world/area/lake/npc/shrimp.c": 3,         // ���L
        "/world/area/lake/npc/shell.c": 2,          // ����
        "/world/area/muye/npc/bturtle.c": 5,        // �j�Q�t
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
    return "/world/area/sifa_isle/npc/bruno.c";   // ���|��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N�I�Y���D�G"HIG"�J�M�������Ȩ��N��$n�a�C\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIW"�K���E��"NOR"�v\n";
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
    player->set_skill("body gang", 2);
    tell_object(player, HIY"(���|�է��K����ƪ���k�Ǳµ��A�F)\n"NOR);
}

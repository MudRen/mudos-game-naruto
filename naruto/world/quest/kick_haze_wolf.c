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
    return "�s�T�ûR";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�u"YEL"�P�}�E�t�T"NOR"�v�O�@�ۮھگT�������覡�ҧ������S��ޥ��A�����\n";
    msg += "�����H���D���覡��V���C�p�G��T�s����ʤ����F�ѬO�L�k���Q\n";
    msg += "���ϥΥX�t�T�����A�V�O�������륬�ԩҵ������ȧa�C\n";

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
    if( player->query_skill("kick wolf", 1) ) return 0;
    if( player->query_class() == "work_sea" ) return 0;
    if( player->query_class() == "little_sea" ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/sifa_isle/npc/jia.c";   // �륬��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�C�Y�I��.\n"NOR,
        "$N���D�G"HIG"���������I��ڪ��t�T���ۦ�����ܡI\n"NOR,
        "$N���D�G"HIG"���h��@�ǯT�s��s��s�a�I\n"NOR,
        "$N���D�G"HIG"�p�G�٬O�S�⮩�A�^�ӧ�ڧa�I���������I\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/wild/npc/wolf.c": 10,     // �T
        "/world/area/wild/npc/bigwolf.c": 6,   // �j�T
        "/world/area/echo/npc/wolf2.c": 6,     // �s�T
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
    return "/world/area/sifa_isle/npc/jia.c";   // �륬��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"��I�H$n�u���]�h���T���I�������I\n"NOR,
        "$N���D�G"HIG"���O���T���i��Ƿ|�¡I�Ӥѯu�F�I\n"NOR,
        "$N���D�G"HIG"�ݦb$n�o�򦳤ߡA�N��$n�a�I\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"YEL"�P�}�E�t�T"NOR"�v\n";
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
    player->set_skill("kick wolf", 2);
    tell_object(player, HIY"(�A�Ƿ|�t�T�ޥ��F�A���Pı�륬�Ԧ��G�٦��d�@��)\n"NOR);
}

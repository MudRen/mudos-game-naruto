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
    return "�ͩR�k��";
}

// ���ȴy�z
string getDetail() {
    string msg;

        msg  = "�u�ͩR�k��v�O�@�دS���Z�N�A�g�Ѹ�����������ܨ��骺���A�A\n";
        msg += "��Ǫ̥i�H�P�i�s���N�¡A�W�i���ƩM�l������O�A�Ϧ�G�`����[\n";
        msg += "�ֳt�A�F��[�t��O�^�_�����ɡC���F�������H�ɲߺD�ͩR�k��ϥ�\n";
        msg += "�ɪ����A�A�~���n�D�A�a�^�@�ǯ���^�_��O���ī~�C\n";

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
    if( player->query_skill("digest absorb", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/sifa_isle/npc/wei.c";   // �~��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"������I�n�ǥͩR�k��I\n"NOR,
        "$N���D�G"HIG"�ͩR�k��I�ݭn�j��������I������I\n"NOR,
        "$N���D�G"HIG"�ݭn�@�Ǧ^�_��O���ī~�I\n"NOR,
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
    mapping item = ([
        "/world/drug/hp_heal.c": 10,                       // ��O�Y
        "/world/drug/hp_heal2.c": 2,                       // �j��O�Y
        "/world/area/thorn_pine/npc/item/hp_help.c": 1,    // ��O���
    ]);
    return item;
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
    return "/world/area/sifa_isle/npc/wei.c";   // �~��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"������I���ڨ�...�I\n"NOR,
        "$N���D�G"HIG"��$n�a�I\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIW"���Ƨl��"NOR"�v\n";
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
    player->set_skill("digest absorb", 2);
    tell_object(player, HIY"(�A��������G����t��ͩR�k��F)\n"NOR);
}

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
    return "�ߨ߸�";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "������k���w�諸���P�J�ܪ����A�o���S�Q���i�R�����u�A�L�����\n";
    msg += "��L�|��Ť����H�@�_��W�ߦզ��P�ߧ��ڦb�Ť���t�A�o�ˤ�����\n";
    msg += "�l�ް��k�P�ɤ]��l�ޤp�ġA���L�����θ̪��ߦզ���ߧ��ګe�Ǥ�\n";
    msg += "�l�~�Q�����骺�s�H�p���N�Ӻ���A�u�n�·ЧA�h��F�C\n";

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
    if( player->query("guild") != "hunter" ) return 0;
    if( player->query_class() == "hxh_initial" ) return 0;
    if( player->query_skill("change ability", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/magic_house/npc/clemens.c";   // �J�ܪ���
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"������I�{�ɻݭn�ߦզ��M�ߧ��ګo�Q�N���F�I\n"NOR,
        "$N���D�G"HIG"$n�p�G�����ڧ�Ӥ���I�ڴN��$n�ಾ��z���ɯ�O���ޥ��I\n"NOR,
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
        "/world/area/whale_island/npc/eq/rears.c": 5,  // �ߦզ�
        "/world/area/whale_island/npc/eq/rtail.c": 5,  // �ߧ���
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
    return "/world/area/magic_house/npc/clemens.c";   // �J�ܪ���
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"�䧹�F�ܡI�ֵ��ڡI\n"NOR,
        "$N���D�G"HIG"�I�A�`��O���b��t�e�N�D�㮳���F�C\n"NOR,
        "$N���D�G"HIG"�J�M���n���N���୹���A�n�n�ǵۧa�C\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIW"�����ഫ"NOR"�v\n";
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
    player->set_skill("change ability", 2);
    tell_object(player, HIY"(�J�ܪ�����榣�����оɧA�A�n���|���F����...)\n"NOR);
}

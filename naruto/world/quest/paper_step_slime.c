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
    return "�n�d";
}

// ���ȴy�z
string getDetail() {
    string msg;

        msg  = "�A�����N���ҭn�D���U�دȱi�a�^�ӵ��L�C�u��ø�v�����N�O�@�ذ{\n";
        msg += "�����ޥ��]�����ȱi�@�˹J�쭷�N�|�Q�j�}�A�]���@�몺�����X�G��\n";
        msg += "����ൽ�ί�ø������A�n�d�O��ø���S��ޯ�A������N��Q����\n";
        msg += "�A�]���ǵ۪d�گ몺����A���{�L�����C\n";

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
    if( player->query_skill("paper slime", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/sifa_isle/npc/xiao.c";   // ��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"��z�z�I���Y�N���ޯण�O���`�H��Ǫ��I\n"NOR,
        "$N���D�G"HIG"$n�n���ڮ��^�o�Ǻ������ȧڤ~��$n�I��z�z�I\n"NOR,
        "$N���D�G"HIG"�ڵ��藍�|�����ӤѮ�w����O�n��츭�����u�����v�I\n"NOR,
        "$N���D�G"HIG".....\n"NOR,
        "$N���D�G"HIG"�S���ȼL�F�I��z�z�I\n"NOR,
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
        "/world/area/ship/npc/item/paper.c": 1,     // �Ѯ�w����
        "/world/area/lake/npc/item/paper.c": 1,     // ������
        "/world/area/lake/npc/item/paper2.c": 1,    // �H��
        "/world/area/old_forest/npc/item/map.c": 1, // �j�Ѵ˪L�a��
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
    return "/world/area/sifa_isle/npc/xiao.c";   // ��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"��z�z�I�~�M���Q$n���F�I\n"NOR,
        "$N���D�G"HIG"�S��k�u�n��$n�n�d�a�I\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIW"��ø�E�n�d"NOR"�v\n";
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
    player->set_skill("paper slime", 2);
    tell_object(player, HIY"(�A�Ƿ|�F��ø���Χ޳n�d)\n"NOR);
}

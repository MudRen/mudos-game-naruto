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
    return "�M�I�h�A�a";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�Q���j���]����M�𻡸ܦӻP�𲣥ͤF�`�p���ͱ��Ať���b�ԨƪL��\n";
    msg += "���񦳤@���W���u����h�A�v�a��A�̭����ئW�s�h�A�r�����ͪ��|\n";
    msg += "�N���G�k�A����h�A�쥻�j�b���a�q���G���O�˪L�A���O�ثe�w�g\n";
    msg += "�K���p���F�A�]���Q���j���n�D�A�h�M���@�Ǭr���C\n";

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
    if( player->query_skill("born-again branch", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/magic_house/npc/daisuke.c";   // �Q���j��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"$n���D�ԨƪL���L�a������U�ӷU�p�F�ܡI\n"NOR,
        "$N���D�G"HIG"�]���W�赴��h�A�̦��جr���|�G�k���I\n"NOR,
        "$N���D�G"HIG"�p�G���H��h�Ʋz�e�̧ڴN���쭫�ͤ��N�ХL�I\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/bone/npc/fish.c": 10,     // �h�A�r��
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
    return "/world/area/magic_house/npc/daisuke.c";   // �Q���j��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"�S�Q��$n�u���h���F���I\n"NOR,
        "$N���D�G"HIG"���M�e���c�ު��ܧ֡A���L�ڬ۫H�|�����U���C\n"NOR,
        "$N���D�G"HIG"�����w���ޯ�o�N�ӱ�$n�a�C\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIY"��K����"NOR"�v\n";
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
    player->set_skill("born-again branch", 2);
    tell_object(player, HIY"(�Ať�F�Q���j�������ɡA���G���Ǥ߱o�F)\n"NOR);
}

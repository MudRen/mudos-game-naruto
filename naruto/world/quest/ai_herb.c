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
    return "���õL��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�츭���R�l�p�j���a�̪����F����A���O�o�����R�l�a���j�p�j�A��\n";
    msg += "�Q���o�زʬ��A�ҥH�Q�ϳ�O�H�����o�ޯ�C\n";

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
    // �츭���u���Ԫ̮��x�i��
    if( player->query_class() != "inferior" && player->query_class() != "work_sea" ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/muye/npc/ai.c";   // �R�l�p�j
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"���e�Ъ���B��¾�����|�N�@����áI\n"NOR,
        "$N���D�G"HIG"�ڻݭn�H���ڧ�᭱������M�z�@�U�F�I\n"NOR,
        "$N���D�G"HIG"�u�n�ޤ@�ʮڴN�i�H�F�I\n"NOR,
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
    if( player->query_temp("ai_herb") < 100 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/world/area/muye/npc/ai.c";   // �R�l�p�j
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�I�F�I�Y�A����g���C\n"NOR,
        "$N���$n���D�G"HIG"��$n����Z���t���A�n���n���ڭ̮a����B�H\n"NOR,
        CYN"$n���Y�W�����_�X�T���½u...\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�����D���y�O����C\n";
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
    object item;

    item = new("/world/item/rod.c");

    player->delete_temp("ai_herb");
    if( item->move(player) )
        tell_object(player, HIY"(�R�l�p�j�N�L�Ѫ����ê�����e���A�F�C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�R�l�p�j�N�L�Ѫ����ê�����e���A�A���O���b�a�W�F�C)\n"NOR);
    }
}

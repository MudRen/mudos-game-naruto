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
    return "�����O��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�H���q�ѱC�C���a�̪����F����A���O�o�~�Ƥw���S��k���o�زʬ�\n";
    msg += "�A�ҥH�n��M�@�N�����L�ޯ󪺤H�C\n";

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
    // �H���q�u���y�H����i��
    if( player->query_class() != "little_sea" && player->query_class() != "hxh_initial" ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/whale_island/npc/oldwoman.c";   // �ѱC�C
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���ۻ��D�G"HIG"��|��������ݰ_�Ӧn�áI\n"NOR,
        "$N���ۻ��D�G"HIG"���n�ߤH�i�H���U�ڶܡI\n"NOR,
        "$N���ۻ��D�G"HIG"�u�n���کޤ@�ʮڴN�i�H�F�I\n"NOR,
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
    if( player->query_temp("woman_herb") < 100 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/world/area/whale_island/npc/oldwoman.c";   // �ѱC�C
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�����a���n�j���C\n"NOR,
        "$N���$n���D�G"HIG"�N�O����$n�o�˪��u�n�H�v�I�C�C�ӷP�ʤF�I\n"NOR,
        CYN"$n�ϩ�ť�줰�򤣹�l����...�C�����ǩ��z�C\n"NOR,
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

    item = new("/world/area/benthal/npc/wp/gaff.c");

    player->delete_temp("woman_herb");
    if( item->move(player) )
        tell_object(player, HIY"(�ѱC�C���X�@����æh�~�����e�浹�F�A�C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�ѱC�C���X�@����æh�~�����e�浹�F�A�A���O���b�a�W�F�C)\n"NOR);
    }
}

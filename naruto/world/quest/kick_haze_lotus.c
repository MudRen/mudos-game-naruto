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
    return "�������";
}

// ���ȴy�z
string getDetail() {
    string msg;

        msg  = "�u"HIM"�P�}�E����"NOR"�v�]�t�F�P�}�H�~���S������A�D�n��O�a�����K�몺\n";
        msg += "�N�ˡA�]������O�ܪ��Q�����n�A�p�G�����ɶZ������i�O�s�ۤv��\n";
        msg += "�|�Q���K�ҧ]���C�d�w�N�O�F�ѳo�@�I�A�~�s�A�h��s�~���D���ʪ�\n";
        msg += "�m�ߡA�m�ߵ�������i�H��Ѣޢ������u�~���v�ǲߧޯ�A�d�w����\n";
        msg += "��ӹL�`���ȮɵL�k�⮩�C\n";

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
    if( player->query_skill("kick luan", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/sifa_isle/npc/ku.c";   // �d�w
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"�Q�ǲߦѦ����ۦ��H\n"NOR,
        CYN"$N�C�Y�I��.\n"NOR,
        "$N���D�G"HIG"�Ѧ����ޥ�$n�i���ٵL�k�⮩�C\n"NOR,
        "$N���D�G"HIG"�u�n$n�h���ǳD�A�A�R��Ʀ^�ӡA�ڷ|�s�~����$n�ۦ����C\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/wild/npc/snake.c": 10,     // �D
        "/world/area/wild/npc/bigsnake.c": 3,   // �j�D
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    mapping item = ([
        "/world/area/thorn_pine/npc/item/gie.c": 1,   // ��
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
        "$N���D�G"HIG"������I�N�O$n�I\n"NOR,
        "$N���D�G"HIG"�Q�ǴP�}�ܡI\n"NOR,
        "$N���D�G"HIG"�d�w�o�����N��$n�a�I������I\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIM"�P�}�E����"NOR"�v\n";
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
    player->set_skill("kick lotus", 2);
    tell_object(player, HIY"(���զh���A�ש�⮩�F���ت��ϥΤ�k)\n"NOR);
}

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

/* �����ȬO�_�୫�Ƹ�  return 0  ���୫��
                       return 1  �i����
   ��ĳ�̦n�]�w���୫�ơC
 */
int isNewly() { return 0; }

// ���ȦW��
string getName() {
    return "���}���Įv��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�Ĥj�v�^�Q�_�F��~�צ�ɪ��@��v�̡A���M���i���c�����աA���O\n";
    msg += "�o�֦��@�Ө�����ͪ����|���ޡA��~�v�̬��F�y�ֳv���Ѥƪ��H��\n";
    msg += "�A����l�O�o�i�������ٵ������_���ġA�u�O�ä������L��̪�\n";
    msg += "�{�P�A�̫�v�̥u�n���}�e���L�H���a�~��}�o���ġC�Ĥj�v�Q�즹\n";
    msg += "�B�Q���P�ˡA�C�|�������X�ܨӤF�A���L��Ư���w�ߪ��ħa�C\n";

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
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/wizard/npc/piller.c";  // �Ĥj�v
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
     CYN"$N�����a�����ڳ�....\n"NOR,
        "$N���D�G"HIG"��~��z�d�l�o�{�@�i�T�Q�~�e�کM�v�Ův�̭̪��X�ӡC\n"NOR,
        "$N���D�G"HIG"��~�v�̬��F�s�y����ٵ������ġA�Q��L����̱ƥ��C\n"NOR,
        "$N���D�G"HIG"�]���s�y���\�Q���|�y���F��...�~�M�N�γo�ؤ覡����...\n"NOR,
        "$N���D�G"HIG"���G�v�̬��F�ڭ̴N���~�`�s�A���I\n"NOR,
        "$N���D�G"HIG"��M�Q��H�e���ơA�~�M�|�o�򪺷P�ˡI\n"NOR,
     CYN"$N�Q��ˤ߳B, �Ԥ�����n�j��.\n"NOR
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
        "/world/area/echo/npc/item/noodle2.c": 1,   // �Ļ���
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
    return "/world/area/wizard/npc/piller.c";  // �Ĥj�v
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
     CYN"$N�D��$n���W���Ѫ������A����F���_���_�_�l�Y�ѡC\n"NOR,
        "$N���D�G"HIG"�o�Ѩ��D�u�O�����I��Ӻ믫���ӤF�I\n"NOR,
     CYN"$N���t�a�Y���ѡA�o�X�l���p�P���n���C\n"NOR,
     CYN"$N�N�J�������]�ܭӺ���A���������F�ӹ��СC\n"NOR,
        "$N���D�G"HIG"�P��$n���ѡI�ڪ��믫�n�h�F�C\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "��o�Ĥj�v�v�̪���m�C\n";
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
    message_vision("\n$N�����a���D�G"HIG"��$n�o�˪��n�H�A�ڬ۫H�v�̷|�@�N���U$n���C\n"NOR, npc, player);
    message_vision("$N���D�G"HIG"$n�N�h�o�̧�ڮv�̧a�C\n"NOR, npc, player);
    message_vision(CYN"$N�u�}�a�ϡA�Τ����"NOR+HIR"�u��{��v"NOR+CYN"���s�ϡC\n\n"NOR, npc, player);
    player->set("capsule_pill", 1);
}

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
    return "�Y���ɸ�";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�H���q���ѱC�C�i�Ӹ��������F���A�`�`�ѪF�Ѧ誺�A��|�����O\n";
    msg += "�͡A�]�O�]���O�ʤ��n�A���W�_�ɷQ���h�ޯ�A�~���y�N�ѤF�C��\n";
    msg += "�H�n�ڰ��o�Ӱ��D�A�ѱC�C�M�w�Y���ɸ��A�^�_�O�ФO�C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 5;
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
    if( player->query("level") < 5 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/whale_island/npc/oldwoman.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"�̪񸣳U�n�����I�����F���I\n"NOR,
        CYN"$N�����a��F�@�U���U, ���G�Q��F����D�N.\n"NOR,
        "$N���$n���D�G"HIG"�ण�����ѱC�C�ڮ��Ǹɸ����F��O�H\n"NOR,
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
        "/world/area/muye/npc/item/turtle_head.c": 10,        // �t�Y
        "/world/area/old_forest/npc/item/monkey_brain.c": 10, // �U��
        "/world/area/echo/npc/item/brain.c": 20,              // ����
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
    return "/world/area/whale_island/npc/oldwoman.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���Ħa���D�G"HIG"�����I�Y�F�o�ǧڤ]�ন���Ѥ~�աI\n"NOR,
        "$N���$n���D�G"HIG"���L�쩳�n���Ʋz�O�H\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 220 �I�C\n";
    msg += "�Ȥl 100 ��C\n";
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
    player->add_point("learn", 220);
    tell_object(player, HIY"(�A��o�F 220 �I�ǲ��I�ơC)\n"NOR);
    player->add("bank", 100);
    tell_object(player, HIY"(�A��o�F 100 ��Ȥl�C)\n"NOR);
}

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
    return "���o�w��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "���ʸU�ש��٬O�ۤv�h�H���ӪL��ѱi�F�A���L�b�S��۪����p�U\n";
    msg += "�b���̦�F�@�ߡA�o�Q�ӪL���񪺯S���j���T�u�s�T�v�ҷ��Z�A�]\n";
    msg += "���s�T��@�몺�T��|�s�ӥB�s����j�n�A�����Q�n��ίv������\n";
    msg += "���ʸU�M�w�Q�^���D�C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 15;
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
    if( player->query("level") < 15 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/echo/npc/wang.c";   // ���ʸU
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�y�W�C�@�����@��!�n���D�`�ͮ�!\n"NOR,
        "$N�ͮ�a���D�G"HIG"���e�˦ۥh�H���ӪL��ѱi�A�ߤW�Q���Ǥs�T�n���Τ��ۡI\n"NOR,
        "$N�ͮ�a���D�G"HIG"���Ǥs�T�u�O�ӥi�c�F�I\n"NOR,
        "$N�n��$n�ݡM�����D���Ǥ���D�N�C\n"NOR,
        "$N���$n���D�G"HIG"���ڥh�аV�@�U���Ǥs�T�a�I\n"NOR,
        "$N�ͮ�a���D�G"HIG"���F�a�^�e�̪���֡A���٭n�ݨ�e�̯S�����������I\n"NOR,
    });
        
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/echo/npc/wolf1.c": 10,    // ���s�T
        "/world/area/echo/npc/wolf2.c": 20,    // �s�T
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    mapping item = ([
        "/world/area/echo/npc/item/tooth.c": 10,  // �T��
        "/world/area/wild/npc/eq/wolf_fur.c": 5,  // �T��
        "/world/area/wild/npc/eq/wolf_tail.c": 2, // �T��
        "/world/area/wild/npc/wp/wolf_claw.c": 1, // �T��
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
    return "/world/area/echo/npc/wang.c";   // ���ʸU
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���Ħa���D�G"HIG"�S���S���I�N�O�o�ؤ����I\n"NOR,
        "$N���D�G"HIG"�Q���e�h���ɭԬݨ���ı�o�u���ơI\n"NOR,
        "$N���$n���D�G"HIG"�{�bı�o�]�S����¡I�o���O$n���\�Ҫ��I\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 500 �I�C\n";
    msg += "�Ȥl 30000 ��C\n";
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
    player->add_point("learn", 500);
    tell_object(player, HIY"(�A��o�F 500 �I�ǲ��I�ơC)\n"NOR);
    player->add("bank", 30000);
    tell_object(player, HIY"(�A��o�F 30000 ��Ȥl�C)\n"NOR);
}

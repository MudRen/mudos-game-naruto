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
    return "���Q�Ѹq";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�A�Q�D�өҵ������y�ҧl��....���U�F�@�ӱ��`�H�����i�ȥ��ȡC\n";
    msg += "�Ʊ�b�����o�ӥ��Ȥ��ᤣ�|����ۤv�}�ߪ����d�C\n";

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
    return "/world/area/bone/npc/snake_king.c";  // �D��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�����j�Ǧa�S�X�Ө��c�����e�M�Ӥ��|�O�Q�������a�Ƨa�C\n"NOR,
        "$N���$n���D�G"HIG"�Q���Q���ӥ��Ȫ��H���y�����״I�C\n\n"NOR,
        CYN"$n�V$N�L�ݦ������Ȫ��Ʊ�...\n"NOR,
        "$N�@�����P�a���D�G"HIG"�S����j���F���I���L���X�ӤH�Ӥw�I\n"NOR,
        "$N���D�G"HIG"�Q���N�ӧa�I���n�N�ԭˡI\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/muye/npc/fishing_man.c": 9,         // ����
        "/world/area/echo/npc/girl.c": 1,                // �֤k(�ѱi�k��)
        "/world/area/muye/npc/poolman.c": 3,             // �w���H
        "/world/area/muye/npc/muye.c": 1,                // �츭�Y
        "/world/area/whale_island/npc/tu-qian-xie.c": 1, // �O�d��
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
    return "/world/area/bone/npc/snake_king.c";  // �D��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N�j���D�G"HIG"�H�����y�ܥs������ϰ������A�����u�������I\n"NOR,
        "$N���$n���D�G"HIG"���y�b�o�̡A���F�ֺu�a�C\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 1600 �I�C\n";
    msg += "�Ȥl 40000 ��C\n";
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
    player->add_point("learn", 1600);
    tell_object(player, HIY"(�A��o�F 1600 �I�ǲ��I�ơC)\n"NOR);
    player->add("bank", 40000);
    tell_object(player, HIY"(�A��o�F 40000 ��Ȥl�C)\n"NOR);
}

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
    return "���ԦҸխl�ͥ���";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�M��Ѧa���ѬO�ӧx�������ȡA���W�x�������A�`�`�����ҥͪ�\n";
    msg += "�۫H�ߡA�]����|�d�Ѯv�S�O�Q�X�o�ӥ������U�ҥͧ����ҸաC\n";

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
    if( player->query("guild") != "muye" ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/muye/npc/ka.c";  // ��|�d
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���n��$n�ݡM�����D���Ǥ���D�N�C�C\n"NOR,
        "$N���D�G"HIG"$n�q�L���ԦҸդF�ܡH\n"NOR,
        "$N���D�G"HIG"�ڳo���ӥ��Ȥ]�\��W�[$n�Ҹժ������I\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/muye/npc/snake.c": 10,  // �j�r�D
        "/world/area/muye/npc/spider.c": 10, // �j�j��
        "/world/area/muye/npc/worm.c": 10,   // �j����
        "/world/area/muye/npc/ninja.c": 6,   // ���ԦҸէԪ�
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
    return "/world/area/muye/npc/ka.c";  // ��|�d
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"���S�����U$n�q�L�Ҹժ��H\n"NOR,
        "$N���D�G"HIG"�ӡI�o�ǬO���Ȫ����y�I\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 1000 �I�C\n";
    msg += "�Ȥl 10000 ��C\n";
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
    player->add_point("learn", 1000);
    tell_object(player, HIY"(�A��o�F 1000 �I�ǲ��I�ơC)\n"NOR);
    player->add("bank", 10000);
    tell_object(player, HIY"(�A��o�F 10000 ��Ȥl�C)\n"NOR);
}

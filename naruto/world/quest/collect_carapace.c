#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

/* �����ȬO�_�୫�Ƹ�  return 0  ���୫��
                       return 1  �i����
   ��ĳ�̦n�]�w���୫�ơC
 */
void create() { seteuid(getuid()); }

int isNewly() { return 0; }

// ���ȦW��
string getName() {
    return "�Ҵ߷j��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�}�۩��ѩ�������A�Q�n������������W���@�Ǹ˹��A�����\n";
    msg += "�ܤ[�S���|�l�a�A�ӥB�~�����[�����~�A����Ĥ@�ӷQ�쪺���~\n";
    msg += "�N�O�ͪ��̪��~�ߡA�n�ݤS��w�@���C\n";
    msg += "���ѩ��̭����ȤH���ѵ��A���Ҵߦ�m�M��G\n";
    msg += "���Z��w�t�ҡC\n";
    msg += "���Z�򩳢w���ߡB�ɴߡB���ߡC\n";
    msg += "�j�Ѵ˪L�w���l�ߡC\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 12;
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
    if( player->query("level") < 12 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/muye/npc/fooder.c";  // ���ѩ�����
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�C�Y�I��.\n"NOR,
        "$N�M�ݵ۫ȤH�G"HIG"���������C�n�����I���...�ӫ��ﵽ�O�H\n\n"NOR,
        CYN"�ȤH�̤C�L�K�ު��Q�׵�...\n"NOR,
        "$N��M�j���a���D�G"HIG"�G�M�٬O�Ҵ������F�豾�W�̦n�ݪ��I\n"NOR,
        "$N�M�ݵ۫ȤH�G"HIG"���H�����ڬD��@�ǥҴ߶ܡH\n"NOR,
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
        "/world/area/lake/npc/eq/shrimp.c": 4,     // ����
        "/world/area/lake/npc/eq/crab.c": 4,       // �ɴ�
        "/world/area/lake/npc/eq/shell.c": 4,      // ����
        "/world/eq/armor/turtle.c": 1,             // �t��
        "/world/area/old_forest/npc/eq/coco.c": 5, // ���l��
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
    return "/world/area/muye/npc/fooder.c";  // ���ѩ�����
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N��Y�a�j�ۡG"HIG"�~�M�a�^�ӳo��h���ҴߡI\n"NOR,
        CYN"$N���������_�R��!!!\n"NOR,
        "$N���$n���D�G"HIG"��⩱�̧G�m���o����R�����a$n�����I\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 1000 �I�C\n";
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
}

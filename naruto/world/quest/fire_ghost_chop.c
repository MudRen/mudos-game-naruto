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
    return "��O���K���R";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�A�Q�M�����ǲߡu"HIR"�N����"NOR"�v���ޯ�A���O�����@�ɶ��ѰO���O�b��\n";
    msg += "�򱡪p�U�~�ϥΥX�o�ۡA�]�ӵL�k�оɧA�C�]���A�u�n�ӵۯ����ҵ�\n";
    msg += "���M��h�M�䪫�~�A�Ʊ�����������O�СC\n";

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
    if( player->query_skill("fire ghost chop", 1) ) return 0;
    if( player->query_class() == "work_sea" ) return 0;
    if( player->query_class() == "little_sea" ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/ship/npc/zoro.c";   // ����
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"����H�Q�ǿN���١H\n"NOR,
        "$N�@�y�ôb���D�G"HIG"���O���Ψ��۪���...���I�O���_�ӤF...\n"NOR,
        "$N���D�G"HIG"�n���O�o��÷�l...������M...�٦�..�o�H\n"NOR,
        "$N���D�G"HIG"$n������o�ǪF���ӧa�A�]�\�����ڪ��O�СC\n"NOR,
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
        "/world/eq/hand/fist.c": 1,               // ������M
        "/world/eq/belt/cord.c": 1,               // ÷�l
        "/world/area/benthal/npc/food/oil.c": 20, // ���x�o
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
    return "/world/area/ship/npc/zoro.c";   // ����
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�C�Y�I���...\n"NOR,
        "$N���M���D�G"HIG"��F�I�N�O���Ӣۢ�������k�I\n"NOR,
        "$N���D�G"HIG"�]���F�H���������μ�W�o��÷�l�I���~�ϤF�ڭ̡C\n"NOR,
        "$N���$n���D�G"HIG"�ڷQ�_�ӤF�A�o�N�ЧA�p��ϥοN���١C\n\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIR"�N����"NOR"�v\n";
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
    player->set_skill("fire ghost chop", 2);
    tell_object(player, HIY"(�g�L���������ɤ���A�A�N�N���پǷ|�F�C)\n"NOR);
}

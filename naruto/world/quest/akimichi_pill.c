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
    return "����@��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "��D�@�ڪ��a�ǯ��ġA���O��D�a�ڦʦ~���I�����n���󤧤@�C��D\n";
    msg += "�a�s�@�N������D�B���A�̪񥿦b�дo�s�@���Ī����Ƥ����F�A���n\n";
    msg += "�I�W�A�Q�ǲ߳o�өۦ��A�K�n�D�A�h�~����_�䪺�m���A������C\n";
    msg += "����B���n�D���ƶq�᮳�^�ӵ��B���N�i�H�F�C\n";

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
    if( player->query_class() == "inferior" ) return 0;
    if( player->query_skill("akimichi pill", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/muye/npc/din.c";   // �B��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�C�Y�I��.\n"NOR,
        "$N�Y�۹s�����D�G"HIG"$n�Q�Ǭ�D���ġH�����n�I\n"NOR,
        "$N�Y�۹s�����D�G"HIG"$n�h�~����_�䪺�u�m���A���v���ڰ��ޤ@�ǵ�^�ӡC\n"NOR,
        "$N�Y�۹s�����D�G"HIG"���^�ӧڴN��$n�ޯ�I�O����Q�������Ѯv���D��I\n"NOR,
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
        "/world/area/rural_area/item/pill_obj01.c": 10,   // �Ե�
        "/world/area/rural_area/item/pill_obj02.c": 10,   // ���ڽ�
        "/world/area/rural_area/item/pill_obj03.c": 10,   // �p����
        "/world/area/rural_area/item/pill_obj04.c": 10,   // ���
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
    return "/world/area/muye/npc/din.c";   // �B��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N�Y�۹s�����D�G"HIG"�����^�ӤF�A���N�y�L�i�D$n�@�Ǭ�D���Ī����ѧa...\n"NOR,
        CYN"$N���L�s������$n�ѻ���D����...\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIR"��D����"NOR"�v\n";
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
    player->set_skill("akimichi pill", 2);
    tell_object(player, HIY"(�g�L�B�������ɫ�A�A�j�����D���Ī������F)\n"NOR);
}

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
    return "�D�Է���";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�ŭ}�j�˫��w�A�h��s�s�X�x�������W���ѤT���������^�ӦV�L\n";
    msg += "���i�A�@�ӥi�H���չ�O�A�G�ӥi�H�ݬݯ����⪺�����覡�ǲ߾ǲ�\n";
    msg += "�b�J��j�j�Ͻ����O�����ӫ��˥h���ۤv���@�A������^�ӦV�ŭ}\n";
    msg += "�j�˧i���g���A�۫H�L�ַܼN��ޯ�е��A���C\n";

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
    if( player->query("guild") != "hunter" ) return 0;
    if( player->query_class() == "hxh_initial" ) return 0;
    if( player->query_skill("destory fist", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/magic_house/npc/johnson.c";   // �ŭ}�j��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"$n��������G���j�����I\n"NOR,
        "$N���D�G"HIG"���L���O�o���٤����I\n"NOR,
        "$N���D�G"HIG"�h�j���W����s�s�X�x��ѤT�쯥���������@�@�I\n"NOR,
        "$N���D�G"HIG"����������չ�O�ٯର���x���`�I�@�|��o�I\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/ship/npc/mob3.c": 3,     // ������
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
    return "/world/area/magic_house/npc/johnson.c";   // �ŭ}�j��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"$n�����������I\n"NOR,
        "$N���D�G"HIG"�ݨӳo�M�}�a���̾A�X$n�F�C\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIM"�}�a��"NOR"�v\n";
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
    player->set_skill("destory fist", 2);
    tell_object(player, HIY"(�ŭ}�j�˱N�}�a������¦�е��F�A)\n"NOR);
}

#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

/* �����ȬO�_�୫�Ƹ�  return 0  ���୫��
                       return 1  �i����
   ��ĳ�̦n�]�w���୫�ơC
 */
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�̫���@";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "��V�C�u�P��L��V�a�ڪ��H���R�e�h���Ի�a�����K�D�d���A���O\n";
    msg += "�b�b���W�Q�����U�ԩҰ�ŧ�A�u���C�u�������˰k�F�^�ӡA���M�g�L\n";
    msg += "�������v���A�o���M�����L����A�]���L���U�A�������o�Ӥ��A�F�F\n";
    msg += "�L���ͥH�ӳ̫᪺���@�C\n";

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
    if( player->query_skill("white eyes", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/muye/npc/white_eyes_ninja.c";   // ��V�C�u
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N�𼫦a���D�G"HIG"�i�c�������Ԫ�...�~�M��ŧ�ڭ�...\n"NOR,
        "$N���L�a���D�G"HIG"���ǧڤӤ�����I�S���o�{�L�̪��I��I\n"NOR,
        "$N���$n���D�G"HIG"$n�����ڳ��o�Ӥ��ܡI\n"NOR,
        "$N���D�G"HIG"�u�n�F�F�o�Ӥ��@�A�ڥi�H�N�ѤU���ͩR���浹$n�C\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/sneakhole/npc/ninja04.c": 15,      // �����Ԫ�
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
    return "/world/area/muye/npc/white_eyes_ninja.c";   // ��V�C�u
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���Ħa���D�G"HIG"�����L�̤F�H�I�Ӧn�F...�Ӧn�F�I\n"NOR,
        CYN"$N�ӹL�E�ʡA�R�X�F�@�f�A��...\n"NOR,
        "$N���D�G"HIG"...�ݨӧڤ]�����[�F�C\n"NOR,
        "$N���$n���D�G"HIG"�ڨM�w�N�ڳѾl�������浹$n�C\n"NOR,
        "$N���D�G"HIG"�ڭ̤�V�@�ڪ��ղ�$n����ť���L�a�A�n�n�B�Χa...\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "��o��V�C�u���ͩR�H\n";
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
    player->set_skill("white eyes", 2);
    tell_object(player, HIY"(�����N�C�u���������ӵ��F�A�A�A��o��V�a�����~���ɤF)\n"NOR);
    npc->die();

    destruct(npc);
}

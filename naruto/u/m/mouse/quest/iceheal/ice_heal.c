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
    return "�B����";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�Ĥj�v���M���o�쪺�@�Ӥ�l�A�W���Ҽg���~�M�O���Ǥw�[���ĵ�\n";
    msg += "�y�B�����z�I���L�o�ĵ������ƫD�`���_�ǡA���ݭn�@�ǯS�O��\n";
    msg += "�����A���������ΰ��n�ζ��������H���L�Ĥj�v�]���L�]�չL�Τ@\n";
    msg += "�뭹���h�s�@�L�A���G�N�u�O���q�����Ӥw�A�ҥH�L�]�b�h�óo��\n";
    msg += "��l���i�H�{�סC\n";

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
    return "/world/area/wizard/npc/piller.c";   // �Ĥj�v
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"�̪�ڱo��F�@�ӯ��_������C\n"NOR,
        "$N���D�G"HIG"�u�n����հt�X�ӡA���Ӥ�ثe�ҽ檺�ī~���n���ħa�I\n"NOR,
        "$N���D�G"HIG"���L���ƫD�`�S�O�A�s�ڳ������D�n�W���h��C\n"NOR,
        "$N���D�G"HIG"�p�G$n���o�ǧ��Ƨڨ�O�������ջs�C\n"NOR,
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
        "/world/item/purple_rice.c": 1,                        // ����
        "/world/item/gold_adzuki.c": 1,                        // ��������
        "/world/item/smoke_mung.c": 1,                         // ���t��
        "/world/item/peanut.c": 1,                             // �����
        "/world/item/longan.c": 1,                             // �۶갮
        "/world/area/whale_island/npc/food/sweet_broth.c": 10, // ����
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
    return "/world/area/wizard/npc/piller.c";   // �Ĥj�v
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���$n���ӻH�A���D:�n�p�l ���e�~��I�I\n"NOR,
        "$N���$n���D�G"HIG"�S�Q��$n�ٯu������Ƨ˨ӤF�I\n"NOR,
        "$N���$n���D�G"HIG"���U�ӴN�浹�ڧa�I\n\n"NOR,
        CYN"$N�N���ƥ�i�j�礤�Τj�����N�C\n"NOR,
        CYN"�u���礤�Q�X���m�����A�O�H�ؤ�������ݵۡC\n\n"NOR,
        CYN"���M$N���X�@�Ӥj�֡A�̭��˺��F�B���C\n"NOR,
        CYN"$N�N�j�֩���礤�A�o�X�F�F���n���C\n\n"NOR,
        CYN"����֤��B���Ƭ�����A$N�K�N���˱����W�s���B���C\n\n"NOR,
        "$N�����a���D�G"HIG"�N�F�@�j��O�I�����D��X�J�I\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ƸJ"HIC"�B��"HIY"����"NOR"�C\n";
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
    int amount;
    object item;

    amount = random(3) + 1;    // �]�w�i��o�쪺���~�ƶq��1-4
    item = new("/world/drug/ice_heal.c");

    item->set_amount(amount);  // �[�J�ƶq

    if( item->move(player) )
        tell_object(player, HIY"(���G�@�@�ˤF "HIG+amount+HIY" �J���B�����C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(���G�@�@�ˤF "HIG+amount+HIY" �J���B�����A���O���b�a�W�F�C)\n"NOR);
    }
    npc->set_amount(0);
}

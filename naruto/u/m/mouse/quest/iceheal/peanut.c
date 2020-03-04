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
    return "�����";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�j���ӤH�ߵ۪�͵��ݫȤH�W���A�A�q����g�L�o�Q����ͪ�����\n";
    msg += "�٦��j���ӤH���@�Ƹ���ͫܦn�Y���ˤl���l�޶i�h�F�A���F�Y��\n";
    msg += "�ݰ_�Ӧn���ܦn�Y����͡A���F�R�]�n����j���I\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 25;
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
    if( player->query("level") < 25 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/lake/npc/seller.c";   // �j���ӤH
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���ۤ@�U����Ͷߤ���...\n"NOR,
        "$N�n��$n���D�G"HIG"$n������ƶܡH�Q�R����j���H\n\n"NOR,
        CYN"$N�o�{$n���O�n�ۥL��W�������...\n"NOR,
        "$N�H�N�����D�G"HIG"�Q�Y��͡H�i�H�I�h���Z�򩳱K�Ǯ��j�����ڧa�I\n"NOR,
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
        "/world/area/lake/npc/item/vase.c": 5,     // �j����~
        "/world/area/lake/npc/item/doll.c": 4,     // ��o����
        "/world/area/lake/npc/item/pottery.c": 3,  // ��������
        "/world/area/lake/npc/item/treasury.c": 1, // ��y��
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
    return "/world/area/lake/npc/seller.c";   // �j���ӤH
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�J�Ӫ�Ų�w�ۮ��쪺�j���C\n"NOR,
        "$N���$n���D�G"HIG"���M���O���f�A���O����]�����q�q�աI\n\n"NOR,
        "$N���$n���D�G"HIG"�o��Q�n����ʹN���h�a�I\n"NOR,
        "$N���$n���D�G"HIG"�U���W���i�O�S�O�ӶR��ͪ��I\n"NOR,
        "$N���$n���D�G"HIG"�ڥi�O�j���ӤH�I���O��ͰӤH�I\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�@�U"YEL"�����"NOR"�C\n";
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
    object item;

    item = new("/world/item/peanut.c");
    if( item->move(player) )
        tell_object(player, HIY"(�A��o�F�@�U����͡C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�A��o�F�@�U����͡A���O���b�a�W�F�C)\n"NOR);
    }
}

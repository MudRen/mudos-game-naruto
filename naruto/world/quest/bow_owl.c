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
    return "�\�ڪ��a��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "ť���\�ڳ����@�Ӵ��Ѱ\�H�׽m���a��u�F���r�v�̪�Q�@�s�֦��j\n";
    msg += "�j�O�q���l�����y�a�����z�J�I�F�A�ڻ��w�g��\�ڳ����y���F���p\n";
    msg += "���жˡA�ҥH�ڪ��\�Y�K�e�өe�U�Ʊ榳�~����������C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 45;
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
    if( player->query_level() < 45 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/thorn_pine/npc/head.c";   // �\�Y
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"�o�ǻa�����u�O�Ӳs�g�F�C\n"NOR,
        "$N���D�G"HIG"�u�����D�ӫ���I�e�̡C\n"NOR,
        CYN"$N�u���v���@�n�ĤF�f��C\n"NOR,
        "$N���D�G"HIG"�n�O���H���������^�������A�ڤ@�w�n�n�����L�C\n"NOR,
        "$N���D�G"HIG"�ڻ��� 50 �����k�b�r������L��...\n"NOR,
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
    return ([]);
}

// �������Ȫ����󰣤F�t�δ��Ѫ�
// 1. �j�����~
// 2. ���F�����ƶq���Ǫ����~
// ���ݭn���ܡA�٥i�H�ۭq�������ȱ���
// return 1, ����������, return 0;������
int postCondition(object player, object npc)
{
    if( !present("_OWL_EYE_", player) ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/world/area/thorn_pine/npc/head.c";   // �\�Y
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�ݵ�$n�������q��ȤW���F�_�ӡC\n"NOR,
        "$N���D�G"HIG"�ӴΰաI�ש�]�H��Ĺ���s�a�����F�ܡI�H\n"NOR,
        "$N���D�G"HIG"�N��S�����������]�L�ҿסI\n"NOR,
        "$N���D�G"HIG"�u�n���������N�����y�I\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "����"HIR"������"NOR"�����y�C\n";
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
    int i;

    item = present("_OWL_EYE_", player);
    i = item->query_amount();

    if( i > 100 ) {
        i = 100;
        item->add_amount(-i);
    } else {
        destruct(item);
    }
    player->add_point("learn", i*1000);
    player->add("bank", i*50000);
    tell_object(player, HIY"(�A�o��F�\�Y������ "+i*1000+" �I�ǲ��I��)\n"NOR);
    tell_object(player, HIY"(�\�Y���B�~���F�A "+i*50000+" ��Ȥl�I)\n"NOR);
    return;
}

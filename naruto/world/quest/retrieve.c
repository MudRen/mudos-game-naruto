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
    return "�o�󪫦^��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "���\�����k�A�L�O�M���^���X���ɴݯd�������^���a�A���M��L\n";
    msg += "�F��쥻�]�i�H��L�^���A���L�L���Q��O�\�ҥh���j�a���వ��\n";
    msg += "�ơC�ҥH���X���ݯd���n�^���ɦA��L�a�C\n\n";
    msg += "���ȻݨD�G\n";
    msg += "    �Ȥl ? ��C\n";
    msg += "    �X���᪺�o�󪫡C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 1;
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
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/thorn_pine/npc/fee.c";   // �\��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���ۻ�ջ��D�G"HIG"�n�^���o�󪫳�H\n"NOR,
        CYN"$N���y�L�@���G�ڥ����Q���o�Ӥu�@�C\n"NOR,
        "$N���n�a���D�G"HIG"�����S���Y���I��F�I\n"NOR,
        "$N��$n�j�q�G"HIG"�ڥu���X���o�󪫡I���D�F�ܡI\n"NOR,
        "$N��$n�j�q�G"HIG"�l��@�b�@�ʨ�Ȥl�I�o�o�@��@�d��Ȥl�I\n"NOR,
        "$N�H���I�_�@�ڷϻ��D�G"HIG"�����ܤ��D�F�A���Q�^���N�u�a�C\n"NOR,
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
    if( !present("scrap", player) && !present("residue", player) ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/world/area/thorn_pine/npc/fee.c";   // �\��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���_�s�P�ݤF�@�U�A$n�ϩ��ݨ��@�D�����{�L...\n"NOR,
        "$N���$n���D�G"HIG"�n�F�I�ѤU���N�浹�ڧa�C\n"NOR,
        CYN"�Q����$N���M���p��L�����A�T��U�N�N�o�󪫷h���F�C\n\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�M�z�o�󪫡C\n";
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
    int i, j;
    object item;

    if( objectp(item = present("scrap", player)) ) {
        i = item->query_amount();
        j = i*1000;
        tell_object(player, HIY"�M���o�o"HIR+chinese_number(item->query_amount())+HIY"��B"NOR);
        destruct(item);
    } else {
        j = 0;
    }
    if( objectp(item = present("residue", player)) ) {
        i = item->query_amount();
        j += i*100;
        tell_object(player, HIY"�M���l��"HIM+chinese_number(item->query_amount())+HIY"�b�B"NOR);
        destruct(item);
    }
    player->add("bank", -j);
    tell_object(player, HIY"�`�@���A"HIG+chinese_number(j)+"��Ȥl"HIY"�C\n\n"NOR);
}

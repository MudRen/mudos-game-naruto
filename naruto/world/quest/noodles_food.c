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
    return "���ѭ���";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�츭�����ѩ�����Q�n��o�s�����ѡA�]���e�U�H�����L�M��s����\n";
    msg += "�̭��n���ϥΧ��ơA�N�O���b���L���������x�C\n";

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
    if( player->query_level() < 25 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/muye/npc/fooder.c";   // ���ѩ�����
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�o�b�F�ܤ[�A�]��$n���Ө��~�F�@���t�I�^��Ȥl�U�C\n"NOR,
        "$N���D�G"HIG"��ӬO$n���I�~�F�ڤ@���I\n"NOR,
        CYN"$N�y�W�S�X���c�����e�C\n"NOR,
        "$N���D�G"HIG"�]��$n��~�~��ڤF�A�N���ڭӦ��a�I\n"NOR,
        "$N���D�G"HIG"�ڻݭn�j�q�����x�A�p�G���^�ӧڷ|��$n���y���I\n"NOR,
        "$N���D�G"HIG"���L�̦h�u�n 100 �����A�Ӧh���ȷ|�a���O�I\n"NOR,
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
    if( !present("_BEAR_PAW_", player) ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/world/area/muye/npc/fooder.c";   // ���ѩ�����
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���Ħa�S���S�s�A�@���p�߱N���Ѵ��祴½�F�A�S���ۤv�z�z�s�C\n"NOR,
        "$N���D�G"HIG"�u�O�ӴΤF�I�o�U�l�S�����ƥi�H�~���o�ԡI\n"NOR,
        "$N���D�G"HIG"���y�N�o�˺�a�I�@�ں��x 3000 ���I\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "����"HIK"���x"NOR"�����y�C\n";
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

    item = present("_BEAR_PAW_", player);
    i = item->query_amount();

    if( i > 100 ) {
        i = 100;
        item->add_amount(-i);
    } else {
        destruct(item);
    } 
    player->add("bank", i*3000);
    tell_object(player, HIY"(�A�o��F���ѩ����󵹤��� "+i*3000+" �����y��)\n"NOR);
    return;
}

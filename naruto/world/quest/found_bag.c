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
    return "��������";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�K�����󬰤F�s�@����P�i�A�@���ͪ����u��A���զb���ƥ]���[\n";
    msg += "�J�@�Ǧ����A�@�����X�����C���L�̪�Q�̦��F�ܦh���Ǯ{�ϥL\n";
    msg += "�L�k�⨭�e�h�Ķ�����A�ҥH�N���ȩe�U���A�����L�����@�ǥ��n\n";
    msg += "�����ơA�Ʊ�L���c�Q�|���\�I\n";

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
    return "/world/area/muye/npc/iron.c";   // �K������
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"�����ڤ@�Ӧ��ܡH\n"NOR,
        "$N���$n���D�G"HIG"�ڻݭn�@�ǽ��G�i��зs�X���޳N�C\n"NOR,
        "$N�K�ܻ��D�G"HIG"���O�Ǯ{�Ӧh���������}�o�̡C\n"NOR,
        CYN"$N�ΤO��F$n�@�U�j�n�۵ۡG�u$n�I�N�M�w�O�A�F�I�v\n"NOR,
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
        "/world/area/rural_area/item/pill_obj03.c": 10, // ���
        "/world/area/rural_area/item/pill_obj02.c": 10, // ���ڽ�
        "/world/area/rural_area/item/pill_obj01.c": 5,  // �Ե�
        "/world/drug/mpill4.c": 5,                      // �W�j����
        "/world/item/longan.c": 1,                      // �۶갮
        "/world/item/gold_adzuki.c": 1,                 // ��������
        "/world/area/rural_area/npc/item/wafer.c": 8,   // �z��
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
    return "/world/area/muye/npc/iron.c";   // �K������
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�S�X�@�y�u�ڪG�M�S�ݿ��H�v�����C\n"NOR,
        "$N���$n���D�G"HIG"��ı�o$n��A�X��ڪ��Ǯ{�O�I\n"NOR,
        "$N���$n���D�G"HIG"�o�]���ƥ]�N�e��$n�a�I\n"NOR,
        CYN"$N�r�֦a���ۡC\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�@�]���ƥ]�C\n";
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

    item = new("/world/area/old_forest/item/bag.c");
    if( item->move(player) )
        tell_object(player, HIY"(�K�����󪺧��ƥ]���Q�浹�A�F�C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�]�����W�ӭ��A�K�����󪺧��ƥ]����a�W�F�C)\n"NOR);
    }
}

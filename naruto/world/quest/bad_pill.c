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
    return "�j�ŧ���";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�A���p�ߤ��F�j�N�g�H�ѧ��媺�G�k�u�H�ͤY�v���ޥκɥ����k\n";
    msg += "�]�����U�ӡA�]��ť���i�o�֦��j�ŧ��Ī���O�A�ҥH�Q��o��o\n";
    msg += "�Q�����Y�l�������A�S�Q��i�o�~�M�n�D�A���I�@���O�Τ~������\n";
    msg += "����...�u�O�X�H���M...\n\n";
    msg += "���ȻݨD�G\n";
    msg += "    �Ȥl 100000 ��C\n";

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
    if( !present("_BAD_PILL", player) ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/old_forest/npc/ying.c";   // �i�o
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$n�J�Ӫ��N�Ҥ����Ŭr�i�D$N...\n"NOR,
        "$N���D�G"HIG"�o��²�檺�Ʊ���ڴN��F�A�j�ŧ��ĥi�O�ڪ��j���I\n"NOR,
        CYN"$N�y�W�S�X�@�ٸ޲������e�C\n"NOR,
        "$N���D�G"HIG"���N���ӤQ�U��Ȥl�L�ӧa�I\n"NOR,
        CYN"$n�G�s�@�n, ���y�u���]�w��?!?!?�v����.\n"NOR,
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
    if( player->query("bank") < 100000 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/world/area/old_forest/npc/ying.c";   // �i�o
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�ݵۻȦ�̪��s�ڪ��B�I�F�I�Y�C\n"NOR,
        "$N���$n���D�G"HIG"�ݧڪ�t�a�I\n"NOR,
        CYN"$N�L�L�K�_�F���Y�A����x���|�V�ѡC\n"NOR,
        CYN"�u��$N��x�«�@½�A$n�y�ɷP�쨭�W�@�}��h�C\n"NOR,
        CYN"���H�ͤY�w�g�Q$N�����U�F�C\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�h���H�ͤY�C\n";
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

    item = present("_BAD_PILL", player);
    player->add("bank", -100000);
    tell_object(player, HIY"(�i�o���\�����İ����F�A�A�P�쨭�l���P����)\n"NOR);
    destruct(item);
}

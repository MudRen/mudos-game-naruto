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
    return "�U�ԦҸ�";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�B�����s��Ԫ̤��ųQ������Z�򩳰���Ҹե��ȡA���Ȫ����e�O\n";
    msg += "��L�����Ԫ̩ҧ�쪺�c�l�u�Ǯa���_�v�����}��k�A���Ťd���U\n";
    msg += "�W���q��}�l���̥�ť�즳���}�Ҫ���k�A���O�o�l�׵L�k����\n";
    msg += "�����}�k�P�Ѷ}�Ǯa���_�������A�����o�a�C\n";

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
    if( player->query_skill("lending ticket") < 20 ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/lake/npc/ninja4.c";   // ����
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�u���v���@�n�ĤF�f��C\n"NOR,
        "$N���D�G"HIG"�q��}�l���̰��Ӫ��H�ȩ������b�o...\n"NOR,
        "$N���D�G"HIG"��򤰻򳣧䤣��O�I\n"NOR,
        CYN"$N�u���v���@�n�ĤF�f��C\n"NOR,
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
        "/world/area/lake/npc/item/paper.c": 3,   // ������
        "/world/area/lake/npc/item/reel.c": 3,    // ����ѫʨ�
        "/world/area/lake/npc/item/reel2.c": 3,   // �Ŧ�ѫʨ�
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
    return "/world/area/lake/npc/ninja4.c";   // ����
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�ּ֪���R����!!!\n"NOR,
        "$N���$n���D�G"HIG"�o�˧ڴN�i�H��t�F�I\n"NOR,
        "$N���$n���D�G"HIG"����$n�I�ڤ�$n�ӤH���I\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�n���S������y...\n";
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

    item = new("/daemon/skill/hxh/special/obj/rain_ticket.c");
    if( item->move(player) )
        tell_object(player, HIY"(�]�����Ť�F�A�H���A�]���A�o��@�i�ɶU��C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�]�����Ť�F�A�H���A�]���A�o��@�i�ɶU��A���O���b�a�W�F�C)\n"NOR);
    }
}

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
    return "�S����M����M��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�@���z�ޤj�����p��M�ǡA�]���X�ͮɭ�n�J��D�ڻP���]�@�ڨ�\n";
    msg += "��P�ɪ��i��A�ҥH�p��M�Ǫ������b�a�p��M�ǰk���ɵ�M�N�~\n";
    msg += "�����Ӥ����F�C�A������e���s����M�ܡH���M�e�n�D���s��M\n";
    msg += "���Ǥ��Ӥ@��....\n";

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
    return "/world/area/bone/npc/little_ton.c";   // �p�q���Q
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"�ڤ]�n�Q�n�@���M�I\n"NOR,
        "$N���D�G"HIG"�i�O�O�Ф������a�ڰk���ɦ��ݨ�@���s�s���M�I\n"NOR,
        "$N���D�G"HIG"����n������n�I$n�����ڮ��ܡI\n"NOR,
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
        "/world/area/bone/npc/wp/snake_blade.c": 1,        // �s�M
        "/world/wp/newblade.c": 1,                         // �s�;ԤM [���F�s�ͥu���q�k�q�����f�Φ�]
        "/world/area/thorn_pine/npc/wp/assault_blade.c": 1 // �����ԤM 
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
    return "/world/area/bone/npc/little_ton.c";   // �p�q���Q
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"�N�O�o�ӡI\n"NOR,
        "$N���$n���D�G"HIG"����$n�I�o�ӤH������ۡI���ڪ��j�A����$n�I\n"NOR,
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

    item = new("/daemon/skill/hxh/special/obj/ton_ticket.c");
    if( item->move(player) )
        tell_object(player, HIY"(�]���p�q���Q��F�A�H���A�]���A�o��@�i�ɶU��C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�]���p�q���Q��F�A�H���A�]���A�o��@�i�ɶU��A���O���b�a�W�F�C)\n"NOR);
    }
}

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
    return "�T��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�C�~�k�l���n�D�A�u�n�������T�ػ�z�A�L�N�N���~����Ŧ�s�@\n";
    msg += "�X�ӵ��A�C���L������o��k�l�֦��s�@���~��Ŧ����O�O�H�S��\n";
    msg += "���򺡬O���~���˪L���u���L�@��H���A�o�����D�������o�Ӫ��F\n";
    msg += "�C�`�����N�T����A���a�I\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 40;
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
    if( !player->query_temp("know_dragon") ) return 0;
    if( player->query_class() == "hxh_intermediate" ) return 1;
    else if( player->query_class() == "middle" ) return 1;
    else if( player->query_class() == "thief_sea" ) return 1;
    else if( player->query_class() == "soldier_sea" ) return 1;
    else return 0;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/god_forest/npc/man.c";   // �C�~�k�l
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$n�N�s�Ťj���Q�ۤƻP�ݫe�Ŭ}���Ʊ��i�D$N\n"NOR,
        CYN"$N�L�`�a�q�q��.\n"NOR,
        "$N���D�G"HIG"���ǳ̪񪺯��~�˪L�n���S�O��...\n"NOR,
        "$N���D�G"HIG"�|�]�ӧ����~����...�Q���Ʊ��w�g�o�i�����Y���F�C\n"NOR,
        "$N���D�G"HIG"�Ȧ��@���A�h���T��ڡA�N��$n����Ŧ�C\n"NOR,
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
        "/world/area/lv60_area/npc/item/soul1.c": 1,      // ����
        "/world/area/lv60_area/npc/item/soul2.c": 1,      // �s��
        "/world/area/lv60_area/npc/item/soul3.c": 1,      // �߻�
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
    return "/world/area/god_forest/npc/man.c";   // �C�~�k�l
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"�N�O�o�T�˪F��A���U�ӴN�浹�ڧa�C\n"NOR,
        CYN"$N���X�@�����Y�J�誺��Ŧ�A��F�@�ǥj�y�A�u���T�T��z�����J��Ŧ���C\n"NOR,
        CYN"����$N���X�k��i������Ŧ�@���A��Ŧ�N���֦��F�ͩR��}�l���ʡC\n"NOR,
        "$N���$n���D�G"HIG"�n�F�A�o����Ŧ�N�浹�A�A�O�A�ӷЧڤF�C\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = HIY"���~"RED"��Ŧ"NOR"�@��\n";
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

    item = new("/world/area/lv60_area/npc/item/heart.c");
    if( item->move(player) )
        tell_object(player, HIY"(�A�N�T��浹�C�~�k�l��A�o��F���~��Ŧ�C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�A�N�T��浹�C�~�k�l��A�o��F���~��Ŧ�A���O���b�a�W�F�C)\n"NOR);
    }
}

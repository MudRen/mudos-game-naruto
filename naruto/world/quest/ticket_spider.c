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
    return "�i�����j��H";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�]�\�O�]�����y���Ѫ��Ӥ֡A�S�Ϊ̬O�j�a���w�g��ѳo��ϥ@�D\n";
    msg += "�j�^���A�`���{�b���L�w�g���~���o���J�٭n�G�F�A�@��S���j\n";
    msg += "���H�G���j��H�A�N���v�v�l�S���K��A���C�־��S���n��@�ˡC\n";
    msg += "�Ʊ�n�ߤH�K���D�����A�����L�a�C\n";

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
    return "/world/area/sneakhole/npc/spiderman.c";   // ���Ѫ���
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�Q��ˤ߳B, �Ԥ�����n�j��.\n"NOR,
        "$N���D�G"HIG"��...��...\n"NOR,
        "$N���D�G"HIG"�S���j���H�G���ڨ쩳�⤰��I\n"NOR,
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
        "/world/area/sneakhole/npc/item/mucus.c": 50,   // �j���H�G
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
    return "/world/area/sneakhole/npc/spiderman.c";   // ���Ѫ���
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�e�ص��ޡA�n���ݨ�F�@�󤣥i��ĳ���ơC\n"NOR,
        "$N�@�����@�Ⲵ�\���$n���D�G"HIG"�o�ӥ@�ɻݭn$n�I\n"NOR,
        "$N���$n���D�G"HIG"�o�ӤH���N����ۤF�I\n"NOR,
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

    item = new("/daemon/skill/hxh/special/obj/spider_ticket.c");
    if( item->move(player) )
        tell_object(player, HIY"(�]�����Ѫ��Ѥ�F�A�H���A�]���A�o��@�i�ɶU��C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�]�����Ѫ��Ѥ�F�A�H���A�]���A�o��@�i�ɶU��A���O���b�a�W�F�C)\n"NOR);
    }
}

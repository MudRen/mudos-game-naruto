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
    return "���i���q";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�g�Ѱ��o����өH���ӪL�쥻�O�@�ӧ����A�]�����������۶��\n";
    msg += "�b�C�~�۶�q���u�����Y�۶ꪺ�j�����ʡA���G�Y�����ʮɪ����\n";
    msg += "�n���P�ڤH�������D�ڿ���A�e�̻D��۶ꭻ����~�j�|��J���l\n";
    msg += "���l�]���Q�}�a�p��...\n";

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
    return "/world/area/echo/npc/chu.c";   // ���
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���ۤ��j���D�G"HIG"�o�ǥi�c���D�H�A�ڤ@�w���|��L�e�̡I\n"NOR,
        CYN"$n�W�e�߰ݨƱ����g�L...\n\n"NOR,
        "$N���D�G"HIG"�o�̭쥻�O�Ӭ��R���s�����l�A�M���شӮ۶�C\n"NOR,
        "$N���D�G"HIG"�C�~�٬��F�۶��|��`��I�ڭ̳��٬��۸`�C\n"NOR,
        "$N���L�a���D�G"HIG"�֪��D�����۸`���ɭԦ]���N�۶ꪺ�����C\n"NOR,
        "$N���L�a���D�G"HIG"�~�M�ިӤF�@��D�H...���l�]�N�o�˨S�F...\n"NOR,
        CYN"$N�u���v���@�n�ĤF�f��C\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/echo/npc/snake03.c": 15,  // �D�H
        "/world/area/echo/npc/snake01.c": 1,   // �D�u
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    mapping item = ([
        "/world/area/wild/npc/item/snake_skin.c": 10,   // �D��
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
    return "/world/area/echo/npc/chu.c";   // ���
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�e�ص��ޡA�n���ݨ�F�@�󤣥i��ĳ���ơC\n"NOR,
        "$N���$n���D�G"HIG"$n�~�M�����F�o��h���D�H�I\n"NOR,
        "$N���$n���D�G"HIG"�ٱN�L�̪��Y�سD�u�]�����F�I\n"NOR,
        CYN"$N�C�Y�I��.\n\n"NOR,
        "$N�F�\�a��$n���D�G"HIG"�ڤ]�S����F���e��$n...�N���Ǯ۶갮�n�F�I\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�@�U"HIW"�۶갮"NOR"�C\n";
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

    item = new("/world/item/longan.c");
    if( item->move(player) )
        tell_object(player, HIY"(�A��o�F�@�U�۶갮�C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�A��o�F�@�U�۶갮�A���O���b�a�W�F�C)\n"NOR);
    }
}

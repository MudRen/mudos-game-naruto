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
    return "���̥���";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�B���̪񤣪��D�q���̧˨ӤF�ܦh�����̶��A���O�o�@�������D�n\n";
    msg += "���i�N�~�|��n�Y�A��Ӧ����h���Q�L������ȡA�b�˪L���J\n";
    msg += "��@��W�s�ۿP�h���H�i�D�L�A���̭n�f�t��Q�L�̭��������G\n";
    msg += "�A���D�~�|�o�����X�ӡC��O�B�����R���b��Q�L���M�䵵��A�o\n";
    msg += "�����F��Q�L���y��A���G�Q�몺�����O�˵L�k�A�h�F�C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 30;
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
    if( player->query("level") < 30 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/muye/npc/din.c";   // �B��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�u���v���@�n�ĤF�f��C\n"NOR,
        "$N���L�a���D�G"HIG"��Q�L����u�O�ӳ·ФF...\n"NOR,
        "$N���L�a���D�G"HIG"�o�ˤl�ڭn��򮳵����G�O...\n"NOR,
        CYN"$N�u���v���@�n�ĤF�f��C\n"NOR,
    });
        
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/thorn_pine/npc/tree.c": 10,  // ��Q�L
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    mapping item = ([
        "/world/area/thorn_pine/npc/item/water02.c": 6,   // �����G
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
    return "/world/area/muye/npc/din.c";   // �B��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���Ħa���D�G"HIG"�����G�I\n"NOR,
        "$N���Ħa���D�G"HIG"$n�u�����^�ӵ��ڤF�I\n"NOR,
        CYN"$N���������_�R��!!!\n\n"NOR,
        "$N���$n���D�G"HIG"�Ӱ����F���ѰO����$n�C\n"NOR,
        "$N���$n���D�G"HIG"�ڳo�̵��̤Ӧh�F�A�N����$n�@�ǧa�I\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�@�]"HIM"����"NOR"�C\n";
    msg += "�Ȥl 1000 ��C\n";
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

    item = new("/world/item/purple_rice.c");
    if( item->move(player) )
        tell_object(player, HIY"(�A��o�F�@�]���̡C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�A��o�F�@�]���̡A���O���b�a�W�F�C)\n"NOR);
    }
    player->add("bank", 1000);
    tell_object(player, HIY"(�A��o�F 1000 ��Ȥl�C)\n"NOR);
}

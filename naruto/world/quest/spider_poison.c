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
    return "�j���a��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�H���q�W���@�Ӭ}�޳Q�@�j�s���c���j����ڤF�A�q�W���~�����@��\n";
    msg += "�L�����O�ܦw�ߪ��ͬ��C�]���{���������M�w�o�X�a�ऽ�i�A�Ʊ��\n";
    msg += "�Ц��O�𪺤H���������j��C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 15;
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
    if( player->query_level() < 15 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/whale_island/npc/village_head.c";   // �H���q����
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���W�U���q��$n�A���G���b����$n���԰���O...\n"NOR,
        "$N�L���a��$n�G"HIG"$n�����o�Ӯq�W���H�@��ƶܡH\n"NOR,
        "$N�T�ܭW�y�a���G"HIG"���e�}�w�q���츭�����q�D...�{�b�~�M�Q�@�s�j��e��F...\n"NOR,
        "$N���D�G"HIG"�]���e�̼ƶq���h...�ڭ̮ڥ��S��k���I�C\n"NOR,
        "$N���D�G"HIG"�i�H���U�ڭ̶ܡH�����O���|�֪��I\n"NOR,
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
    if( !present("__QUEST_D_2__", player) ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/world/area/whale_island/npc/village_head.c";   // �H���q����
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�ݵ�$n"CYN"�����a�j�s�@�n �ݢ֡@��ϡI�I\n"NOR,
        "$N���D�G"HIG"�F���Ӧn�ԡI�o�˴N���~��}�w�s�}�F�I\n"NOR,
        "$N���D�G"HIG"�����O�@�~�r�G 500 ���I\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "����"HIM"�j��r�G"NOR"�����y�C\n";
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

    item = present("__QUEST_D_2__", player);
    i = item->query_amount();

    if( i > 500 ) {
        i = 500;
        item->add_amount(-i);
        message_vision("$N�C�Y���D�R"HIG"���ڷǳƪ����B�u��I 500 �~����...\n"NOR, npc, player);
        message_vision("$N���D�R"HIG"��L�h���ٳ·�$n�ۤv�B�z���a�C\n"NOR, npc, player);
    } else {
        destruct(item);
    }
    player->add("bank", i*500);
    tell_object(player, HIY"(�A�o��F���������� "+i*500+" �����y��)\n"NOR);
    return;
}

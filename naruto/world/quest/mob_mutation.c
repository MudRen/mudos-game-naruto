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
    return "�ͪ����ܨƥ�";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "��ӹ������ѹ��@�����æb�·t��êŶ������ʪ����έ̡A���W��\n";
    msg += "�o�ͤF�_�S���ܤơA�]�����ܦӨ���n��j�A��㦳�}�a�O�C�W��\n";
    msg += "�����{���o�بƱ��A���`�N�A�H��i��|�v�T���L���ͪ��]����\n";
    msg += "���ܡA�ҥH���b���ȴ��X���e�N�w�g�}�l��s���������D�F�A�ߤ@\n";
    msg += "����ʥF�N�O��کM�e�̱�Ĳ����ơC\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 10;
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
    if( player->query("level") < 10 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/bone/npc/gau.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"�̪񪺹��������ܵo�;��v�U�ӷU���F...\n"NOR,
        "$N���$n���D�G"HIG"�������ڰ��@�ǽլd�ܡH\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/muye/npc/cockroach4.c": 10,         // ��������
        "/world/area/whale_island/npc/cockroach4.c": 10, // ���ܮ�����
        "/world/area/muye/npc/cockroach5.c": 10,         // ���ܤj����
        "/world/area/whale_island/npc/cockroach5.c": 10, // ���ܤj������
        "/world/area/muye/npc/cockroach6.c": 10,         // ���ܥ�����
        "/world/area/whale_island/npc/cockroach6.c": 10, // ���ܥ�������
        "/world/area/muye/npc/mouse4.c": 10,             // ���ܦѹ�
        "/world/area/echo/npc/mouse4.c": 10,             // ���ܦa��
        "/world/area/muye/npc/mouse5.c": 10,             // ���ܤj�ѹ�
        "/world/area/echo/npc/mouse5.c": 10,             // ���ܪΦa��
        "/world/area/muye/npc/mouse6.c": 10,             // ���ܥ��ѹ�
        "/world/area/echo/npc/mouse6.c": 10,             // ���ܭD�a��
    ]);
    return kill;
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
    return 1;
}
	
// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/world/area/bone/npc/gau.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N������Ʊ��ۻ��D�G"HIG"��...��Ӳ{�b�w�g�o�i���p���F...\n"NOR,
        "$N�����a���D�G"HIG"�o�����Ȥ츭���|����$n�̰������y�I�P�¤F�I\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 800 �I�C\n";
    msg += "�Ȥl 16000 ��C\n";
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
    player->add_point("learn", 800);
    tell_object(player, HIY"(�A��o�F 800 �I�ǲ��I�ơC)\n"NOR);
    player->add("bank", 16000);
    tell_object(player, HIY"(�A��o�F 16000 ��Ȥl�C)\n"NOR);
}

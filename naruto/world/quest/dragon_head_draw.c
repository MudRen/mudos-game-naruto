#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

/* �����ȬO�_�୫�Ƹ�  return 0  ���୫��
                       return 1  �i����
   ��ĳ�̦n�]�w���୫�ơC
 */
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�Y���a��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�Ŵ��ԪQ���q�߭n�D�A�h�j���U�ذʪ����Y�A�]���u�s�Y�v�����n�y\n";
    msg += "�L���I�ˤl�~�t�٬��s�A��~�Q���q�߬��F�l�X�ǻ������Ŵ��ԥi�O\n";
    msg += "�O�F�n�j���@�f�\�ҡA�u�n�A����F��Q���ҭn�D���ơA�۫H�L�]�|\n";
    msg += "�@�N�N�o���ޯ�е��A���C\n";

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
    if( player->query_skill("dragon-head draw", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/magic_house/npc/hideki.c";   // �Q���q��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�G�s�@�n, ���y�u���]�w��?!?!?�v����.\n"NOR,
        "$N���D�G"HIG"�s�Y���e�O�ڭW�m�F�ƤQ�~�~�ש󦨥\���ޥ��C\n"NOR,
        "$N���D�G"HIG"�p�G$n�@�N�h�j���@���Y�^�ӡA�ڷ|�Ҽ{��$n���C\n"NOR,
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
        "/world/area/muye/npc/eq/mouse_head.c": 1,     // ���Y
        "/world/area/wild/npc/eq/wolf_head.c": 1,      // �T�Y
        "/world/area/wild/npc/eq/pig_head.c": 1,       // �½��Y
        "/world/area/muye/npc/item/turtle_head.c": 10, // �t�Y
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
    return "/world/area/magic_house/npc/hideki.c";   // �Q���q��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"���j���ӤF�H\n"NOR,
        CYN"$N�C�Y�I��.\n"NOR,
        "$N���D�G"HIG"�n�a�A�ڱ�$n�s�Y���e�C\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIG"�s�Y���e"NOR"�v\n";
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
void reward(object player, object npc)
{
    player->set_skill("dragon-head draw", 2);
    tell_object(player, HIY"(�A�V�O���M�Q���q�߾ǲߡA�ש�Ƿ|�s�Y���e�F)\n"NOR);
}

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
    return "��Ԧ���";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�v¡�N�O�@���򥻪������ԳN�A���M�O�򥻡A�o�ݭn�t�X�F�����d�J\n";
    msg += "�ԹB�ΡC�]���K����N������ҫ��ɪ��m�ߤ覡�i�D�A�A�n�D�A�h\n";
    msg += "�j�Ѵ˪L����W�i��@�Ӥp���ȡA���^�@�ǦU���������G�C�b��K��\n";
    msg += "�ʶ������i�H�V�m�d�J�Ԫ��ϥΡA�ӥB�j�Ѵ˪L�������äF�ܦh�g��\n";
    msg += "�A�i��|��M�����A�A�Ǧ��ӰV�mĵ�٩M���ܪ���O�C\n";

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
    if( player->query("guild") != "muye" ) return 0;
    if( player->query_class() == "inferior" ) return 0;
    if( player->query_skill("heal buff", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/muye/npc/ying.c";   // �p��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"�n�ǲߪv¡�N�����n����$n�@�Ӧ���C\n"NOR,
        "$N���D�G"HIG"�o�]�O������j�H�ҵ��ڪ�����C\n"NOR,
        "$N���D�G"HIG"$n�h�j�Ѵ˪L����K�W�i����ȡC\n"NOR,
        "$N���D�G"HIG"�����F�n�D�����ȫ�A�^�ӧ�ڧa�C\n"NOR,
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
        "/world/area/old_forest/npc/item/fruit.c": 15,   // ��G
        "/world/area/old_forest/npc/item/fruit3.c": 15,  // ���G
        "/world/area/old_forest/npc/item/fruit2.c": 6,   // ���G
        "/world/area/old_forest/npc/item/fruit4.c": 1,   // ���G��
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
    return "/world/area/muye/npc/ying.c";   // �p��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�I�F�I�Y�C\n"NOR,
        "$N���D�G"HIG"$n���Q�������ȡA�v¡�N�]�i�H��$n�F�C\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIW"�v¡�N"NOR"�v\n";
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
    player->set_skill("heal buff", 2);
    tell_object(player, HIY"(�K����N�v¡�N���ϥΤ�k�з|�A�F)\n"NOR);
}

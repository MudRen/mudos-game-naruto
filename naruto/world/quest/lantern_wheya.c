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
    return "�v���j�D�Y";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�@�شϮ��b�ԨƪL���Ǫ��Ү����OŢ�A�ڻ����OŢ�֦��v���ˮ`��\n";
    msg += "���_�ĪG�A�]�����ԧ������j�D�Y�D�`�Q�n�o��o�ӿOŢ�A�]���ڻ�\n";
    msg += "���e�����s�X�F�����i��츭�A�������j�D�Y�D�Ԧۤv���Ѯv�᭸�A\n";
    msg += "���M��Ӧ��ۤv������]�Q�o�h�A�ҥH�~�p������o�ӿOŢ....���O\n";
    msg += "�p�G�A���Q������....�b�j�D�Y����a�W�i�d�U�O�����ơC\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 35;
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
    if( player->query_level() < 35 ) return 0;
    if( player->query("quest/lantern") ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/bone/npc/lon.c";   // �˨��褧��
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"��H�Q���D���U�j�D�Y�j�H��OŢ���������H\n"NOR,
        "$N���D�G"HIG"��M�O�ᤣ�������Ȱ]�_�C\n"NOR,
        "$N���D�G"HIG"�츭�����ؼ��y�����覡�ڥ��N�椣�q�C\n"NOR,
        "$N���D�G"HIG"�o�~�Y������ϰ����i���A�������I\n"NOR,
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
    if( !present("_TONBELI_A_", player) ) return 0;
    if( player->query("quest/lantern") ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/world/area/bone/npc/lon.c";   // �˨��褧��
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"�ܦn�I�o�ˤj�D�Y�j�H���ͤ���]�����F�I\n"NOR,
        "$N���D�G"HIG"�N�@�Ӭ�����R���H�ӻ��A$n�����ܤ����I\n"NOR,
        "$N���D�G"HIG"�o�I���N���h���n�a�C\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "����"HIG"�q���Q�OŢ"NOR"�����y�C\n";
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

    item = present("_TONBELI_A_", player);
    i = item->query_amount();

    if( i > 100 ) {
        i = 100;
        item->add_amount(-i);
    } else {
        destruct(item);
    }
    // �Ψt�Υh���Ҧ������ɧ�O�_��������Y�귽
    // �����o�˥[�ӥä[�� quest �s���H��]��K�ϥ�
    player->set("quest/lantern", 1);
    player->add("bank", i*30000);
    tell_object(player, HIY"(�A�o��F�˨��褧�������� "+i*30000+" �����y��)\n"NOR);
    return;
}

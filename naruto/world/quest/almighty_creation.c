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
    return "�W�C";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "��[�������M�w�g�֦��L�ƪ��L���A�o���M�߷R�j���s���Z���A�o��\n";
    msg += "�L�V�A�ҭn�D���Z�����A���@��u����C�v���G�b�츭���w���H����\n";
    msg += "�ᤤ�i�H�����@�G�A��L���Z���o�����S���������ѡA�ݨӷQ�����o\n";
    msg += "�ӥ��ȨèS���Q������²��C\n";

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
    if( player->query_skill("almighty creation", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/magic_house/npc/gilga.c";   // ��[����
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"���M�ڳ��w�j���L���A���Ƥd�~�ӳo��ڤw�g�P�칽�ФF�C\n"NOR,
        "$N���D�G"HIG"�j���o�بơA�u�n���Ѥ@�I�Q�q�N�@���H�m�ۥh���C\n"NOR,
        "$N���D�G"HIG"����$n�H�ڧ��_�w�ϥ��v�浹$n�A$n���ڧ�Z����ӡC\n"NOR,
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
        "/world/area/bone/npc/wp/shield.c": 1,             // �޼C
        "/world/area/thorn_pine/npc/wp/lines_sword.c": 1,  // �课�C
        "/world/area/old_forest/npc/wp/tree_sword.c": 1,   // ����C
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
    return "/world/area/magic_house/npc/gilga.c";   // ��[����
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"�������I�ݧa�A�Q��Z���N�O�o��²��C\n"NOR,
        "$N���D�G"HIG"�ڪ��u�����_�w�v�ϥ��v�N�浹$n�F�I\n"NOR,
        "$N���D�G"HIG"���L�������O�����F��A��$n�o�˪��H�L�k�s��ϥΧa�I\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIR"�L�����C�s"NOR"�v\n";
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
    player->set_skill("almighty creation", 2);
    tell_object(player, HIY"(�A��o�F��[���פ����_�w���ϥ��v�Q)\n"NOR);
}

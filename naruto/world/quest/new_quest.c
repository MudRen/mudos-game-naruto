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
    return "���ȱо�";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�d�ߥ����榳�S���o�{���ȧ�����������H\n";
    msg += "�S���I�o�ӥ��Ȫ���������N�O������M�Q��Ȥl�I\n\n";
    msg += "�����Ȥl�O�i�H���|�����~�A�]�N�O�@��Ȥl�B�G��Ȥl...����\n";
    msg += "�������ݩ󤣥i���|�����~�A���W�u�n�h�@��N�|�h���@�ӪŶ��A\n";
    msg += "�O���I���~�ݦb"HIY"�浹�e�U�H(ask �e�U�H)"NOR"��~�|�O�ơI\n";
    msg += "�٭n����@�I�O�A���~"HIY"�i�H���}"NOR"�浹�e�U�H��I\n";
    msg += "�ҥH����p�G�J��n�D�ܦh���~�����ȡA�i�H�Ҽ{���嵹��I\n";
    msg += "�ӱ��� Mob �N�|�۰ʰO�ƤF�I\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 1;
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
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/wizard/npc/eqer.c";  // ���j�v
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"�ݨ�ڪ��W�r�̫e������"BLINK+HIY"�I"NOR+HIG"�a�C\n"NOR,
        "$N���D�G"HIG"�u�n���ũάO��L�ݨD�F��A�\�h NPC �������ȥi���C\n\n"NOR,
        "$N���D�G"HIG"�ڳo���O��$n�������Ȩƥ�²��p���ȡC\n"NOR,
        "$N���D�G"HIG"������|�o��ڰ������Ҥ@��C\n"NOR,
        "$N���D�G"HIG"�Q�n�ǲߴN�� "HIY"y"NOR" �a�C\n\n"NOR,
        "$N���D�G"HIG"�b���U���ȫ�i�H�� quest ���O�d�߬�����T�C(help quest)\n"NOR,
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
        "/world/eq/cloth/cloth.c": 2,     // ����
        "/obj/money/silver.c": 10,        // �Ȥl
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
    return "/world/area/wizard/npc/eqer.c";  // ���j�v
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"�o�����ӲM�����~���Ȭ������ƥ�F�a�C\n"NOR,
        "$N���D�G"HIG"�o�ӬO��~���n�n�浹�A�����ҡC\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�@��s�ͥ��ҡC\n";
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
    object eq;

    eq = new("/world/eq/armor/armor.c");
    if( eq->move(player) )
        tell_object(player, HIY"(�A��o�F�@��s�ͥ��ҡC)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��eq����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(eq, player);
        // �p�G�O�b room ���A��eq����player�ҳB���ж���
        else eq->move(environment(player));
        tell_object(player, HIY"(�A��o�F�@��s�ͥ��ҡA���O���b�a�W�F�C)\n"NOR);
    }
}

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
    return "�԰��о�";
}

// ���ȴy�z
string getDetail() {
    string msg;
        
    msg  = "�o��i���ͱo�ܰڡA�֩w�O�s�Ӫ��C\n\n";
    msg += "��X�~���� Mob �ɥi�H�ϥΫ��O�V Mob �Q��(help kill, help fight)\n";
    msg += "�p�G���p�ߨ���ˮ`�A�O�o���]�n�۰ʰk�]�H���U�@���I(help wimpy)\n\n";
    msg += "�`������ѤW�H�����a�ϤW�M��"HIR"��"NOR"�O���a�I\n";
    msg += "�p�G�o�{�����N��e�o�ʧ����I�b�����e����O�o�߫����I(help get)\n\n";
    msg += "�e�����ƥ󳣧�����A�յ۴M��Z�j�v�a�I\n";
    msg += "�۫H�L�|�ַܼN���ѪZ�����A�A���U�A���Q�������I\n";

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
    return "/world/area/wizard/npc/chi.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"�o��i���ͱo�ܰڡA�֩w�O�s�Ӫ��C\n"NOR,
        "$N���$n���D�G"HIG"�o�ӥ��ȬO�ЧA�p��b�@�ɤ��԰����C\n"NOR,
        "$N���$n���D�G"HIG"�M�w���o�ӥ��ȴN�� "HIY"y"HIG" �a�I\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/npc/dog.c": 1,  // ����
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
    return "/world/area/wizard/npc/wper.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"$n�N�O���fè���ШӪ��s��a�I\n"NOR,
        "$N���$n���D�G"HIG"�o��s�;ԤM$n�N�a�W�a�I���M���O����n�Z���C\n"NOR,
        "$N���$n���D�G"HIG"�˳ƪZ���i�H��ܥ���B�k��M����I(help wield)\n"NOR,
        "$N���$n���D�G"HIG"�Z�������˳Ƥ���~���[�ݯ�O��(help identify)�C\n"NOR,
        "$N���$n���D�G"HIG"�άO�ϥ� query �\��]��d�ݨ�U�ت����~��I(help query)\n"NOR,
        "$N���$n���D�G"HIG"�ܤ��h���I��$n�ۤv���էa�I\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�@��s�;ԤM�C\n";
    return msg;
}
/*
    ���ȼ��y
    ���y���ӯ�ۥѵo���A�p�G
        1. ��o�g��
        2. ��o���~
        3. ��o�u��Buff
        4. �߱o�Y�ޯ�
        5. ��缾�a���A, ex: ��¾
*/
void reward(object player, object npc) {
    object wp;

    wp = new("/world/wp/newblade.c");
    if( wp->move(player) )
        tell_object(player, HIY"(�A��o�F�@��s�;ԤM�C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��wp����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(wp, player);
        // �p�G�O�b room ���A��wp����player�ҳB���ж���
        else wp->move(environment(player));
        tell_object(player, HIY"(�A��o�F�@��s�;ԤM�A���O���b�a�W�F�C)\n"NOR);
    }
}

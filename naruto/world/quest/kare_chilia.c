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
    return "�@�����Ԣ�";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "���򵹧A�����ȡA�s�A�h�ѤW�H�������������Ӫ��T�쥫���L��C\n";

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
    if( player->query("level") < 15 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/rural_area/npc/gi.c";   // ����
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�D�`�`�Ȫ��j�n�y�s�T�T\n"NOR,
        "$N��W�a���D�G"HIG"$n�O�֡I���O�������Ӫ�����a�I\n"NOR,
        "$N���D�G"HIG"����I��ӬO�Q�n�@�����I\n"NOR,
        "$N���D�G"HIG"�h���F�ѤW�H���������L��I�L�̬O�������Ӱl���ڪ��I\n"NOR,
        "$N���D�G"HIG"�n�����T�ӤH�a�H...�����L�̴N��$n�@�����I\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/npc/vagabond.c": 3,  // �����L��
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
    return "/world/area/rural_area/npc/gi.c";   // ����
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�e�ص��ޡA�n���ݨ�F�@�󤣥i��ĳ���ơC\n"NOR,
        "$N���$n���D�G"HIG"$n�o�å��Z���[�J�ª��|���ѥ��¡I\n"NOR,
        "$N���$n���D�G"HIG"�n���n�[�J...����C\n"NOR,
        CYN"$N�C�Y�I��.\n\n"NOR,
        "$N�F�\�a��$n�۹D�G"HIG"�ڪ��򵹤j�a����d�U�O�V�ª��|��\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�@�]"YEL"�@����"NOR"�C\n";
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

    item = new("/world/area/rural_area/item/powder01.c");
    if( item->move(player) )
        tell_object(player, HIY"(�A��o�F�@�]�@�����C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�A��o�F�@�]�@�����A���O���b�a�W�F�C)\n"NOR);
    }
}

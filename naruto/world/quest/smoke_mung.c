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
    return "�~��������";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�H���q���ѱC�C��M�ܷQ�A�����~�����ɭԦۤv�����񨧶p�A�]��\n";
    msg += "�ݭn�����ƬO�j�Ѵ˪L�̤g�ۦb�Y���G��A�o��تF��̵ۦѱC�C\n";
    msg += "�����l���O���﮳���쪺�A�O���M�g�۷m�G��A�N�s�𳣪����W�h\n";
    msg += "�F�a�I�ɧA���O�q�����ѱC�C�Y��񨧶p�a�C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 25;
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
    if( player->query("level") < 25 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/whale_island/npc/oldwoman.c";   // �ѱC�C
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�L�`�a����ۤѪ�...\n"NOR,
        "$N�Ⲵ�L���a���$n�G"HIG"$n���n�A�����ڳo�ӦѱC�C�@�Ӧ��a�C\n"NOR,
        "$N�Ⲵ�L���a���$n�G"HIG"��M�n�Q�Y�~�����ɭԦۤv�����񨧶p�C\n"NOR,
        "$N�Ⲵ�L���a���$n�G"HIG"���ݭn�j�Ѵ˪L�̤g�۩ҦY���G��A�����ڮ��ܡH\n"NOR,
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
        "/world/area/old_forest/npc/item/fruit.c": 6,   // ��G
        "/world/area/old_forest/npc/item/fruit3.c": 6,  // ���G
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
    return "/world/area/whale_island/npc/oldwoman.c";   // �ѱC�C
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���������_�R��!!!\n"NOR,
        "$N���$n���D�G"HIG"�O�G����I�o�˷Q���X�n�Y���񨧴N���O���D�F�I\n\n"NOR,
        CYN"$N�ɰ_���ӡA�N�G���i���襤�C\n"NOR,
        CYN"���«�_��...$N�N�񨧩�b���M���b�ϤW�t�N�C\n\n"NOR,
        CYN"�@�|�\��...�ǻ������񨧴N�����F�C\n"NOR,
        "$N���$n���D�G"HIG"�����I�����F�I�o�ǷϾ��L���񨧴N��$n����§�a�I\n"NOR,
        "$N���D�G"HIG"�C�C�ڭn�}�l���񨧶p�աI\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�@�M"HIG"���t��"NOR"�C\n";
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

    item = new("/world/item/smoke_mung.c");
    if( item->move(player) )
        tell_object(player, HIY"(�A��o�F�@�M���t�񨧡C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�A��o�F�@�M���t�񨧡A���O���b�a�W�F�C)\n"NOR);
    }
}

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
    return "��������";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�~��b�j�������������C�ҩd�A�쥻�C�ѳ��L�۲M���h�l����ñq��\n";
    msg += "�o�쭹�����ּ֥ͬ��A���O�]���q�k�q���ث᥿�q�������ܤF�|�P��\n";
    msg += "���y�A�ɭP�쥻������ϩ~�M�]�X�ܦh�����������A�o�Ǯ����]�H��\n";
    msg += "�䬰�����A���O�髬���j���q��[��H�A������m�����������ҩd��\n";
    msg += "���伵����A�w�g�֭n�Q���~���j���������ѤF�A�ҩ��o���J��F�A\n";
    msg += "�A���U�L�̲M�������a�I\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 30;
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
    if( player->query("level") < 30 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/benthal/npc/father.c";   // ����
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"�_�䪺�ǲ����y$n���Ӧ����ѹL�a�H\n"NOR,
        "$N���D�G"HIG"���O���ӥ��q�������ܮ��y�����G�I\n"NOR,
        "$N���D�G"HIG"�٤ިӤF�@�j�諸��������...�`���ڭ̤Ұ��T�\���֨S�۸��F...\n"NOR,
        "$N���D�G"HIG"$n�������ڮ������Ǯ����ܡH\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/benthal/npc/anemone.c": 200,  // ��������
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    mapping item = ([
        "/world/area/benthal/npc/item/root.c": 80, // ����
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
    return "/world/area/benthal/npc/father.c";   // ����
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���������s�n�I\n"NOR,
        "$N���$n���D�G"HIG"�S�Q��$n���ڮ����o��h�������I\n"NOR,
        "$N���$n���D�G"HIG"���F����$n�A�ڴN�N�������ڳ��s�����Ұe��$n�a�I\n\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�@��"HIG"����"NOR+GRN"�s���Z"NOR"\n";
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
    object item;

    item = new("/world/area/benthal/npc/eq/root_armor.c");
    if( item->move(player) )
        tell_object(player, HIY"(�A��o�F�@������s���Z�C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�A��o�F�@������s���Z�A���O���b�a�W�F�C)\n"NOR);
    }
}

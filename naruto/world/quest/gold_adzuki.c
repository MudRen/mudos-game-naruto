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
    return "��������";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�s��~�a��������ҺشӪ��O���u�}�~�誺�����A�C�~�j�j�p�p��\n";
    msg += "�o�F���֤��ɪ����A�̪�o�X�~�o�ܤ�ť���L�̪������o���A��]\n";
    msg += "�O�@�s�s��ö}�P���K��a�A�}�a�F�s��~�a�g�a���a��A�����\n";
    msg += "�Ӭ������a���ܤ֤F�A�A�[�W���s�s���٤T�����Q�]�ӥи̰�����\n";
    msg += "�^�h�R�ȡA��O�s��~�a�дo�C\n";

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
    return "/world/area/muye/npc/dou.c";   // �s��~����
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�C�Y�I��.\n"NOR,
        "$N�ۨ��ۻy�G"HIG"�ӫ��ˤ~�໰�����ǵs��O...\n"NOR,
        "$N�ۨ��ۻy�G"HIG"���٭n�U�ۤ��Ԧҳ�...���H�����ڴN�n�F�C\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/wild/npc/scar_bandit.c": 5,  // �M�͵s
        "/world/area/wild/npc/lame_bandit.c": 5,  // �_���s
        "/world/area/wild/npc/ren_bandit.c": 5,   // �����s
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
    return "/world/area/muye/npc/dou.c";   // �s��~����
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"�a�ڸ̪��H�q���ڻ��s��n���}�l�M���F�C\n"NOR,
        "$N���$n���D�G"HIG"��ӬO�]��$n�b���������L�̡C\n"NOR,
        "$N���$n���D�G"HIG"���F����$n�A�ڴN�e��$n�ڭ̮a�ں벣�������a�C\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�@��"HIY"��������"NOR"�C\n";
    msg += "�Ȥl 1500 ��C\n";
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

    item = new("/world/item/gold_adzuki.c");
    if( item->move(player) )
        tell_object(player, HIY"(�A��o�F�@�����������C)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�A��o�F�@�����������A���O���b�a�W�F�C)\n"NOR);
    }
    player->add("bank", 1500);
    tell_object(player, HIY"(�A��o�F 1500 ��Ȥl�C)\n"NOR);
}

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
    return "���ʥ��W�B��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "��}�l�ܥͮ𪺥s�A�h�}�l��....����A�O���Z������Z�A�z�ѬO\n";
    msg += "�]�����Z��O�L��}�l�̳��w���a��....����n�z�C�`�������o��\n";
    msg += "��ַݡA���y���Ӥ]����...�N...�����L�a�C\n";

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
    return "/world/area/lake/npc/gin.c";  // ��}�l
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"$n�I�ֹL�ӡI���ƭn$n�����I\n"NOR,
        "$N���$n���D�G"HIG"�}�l�򨺸̦��ܦh���Z$n���D�a�I�H\n\n"NOR,
        "$n�ôb�a���D�G"HIG"���̤��O�s���Z...\n"NOR,
        "$N�ͮ�a�j�ۡG"HIG"������Z��I$n�Q�𦺧ڶܡI\n"NOR,
        CYN"$n�S�X�@��[ʨ]���y...\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/muye/npc/goose.c": 15,  // ���Z
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
// ���i�ƪ����~�ƶq�u��]�w��1, ���M���ȷ|�L�k����
mapping getItem() {
    mapping item = ([
        "/world/area/muye/npc/item/plume.c": 20,  // �Ф�
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
    return "/world/area/lake/npc/gin.c";  // ��}�l
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���³J�@�˪���ۤv�̯��C\n"NOR,
        "$N���Ħa���D�G"HIG"�o�U�l�S���Z�F�a�I\n"NOR,
        "$N���Ħa���D�G"HIG"���̴N�s�}�l��աI\n"NOR,
        "$N���Ħa���D�G"HIG"�o�Ǽ��൹$n�աI\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 500 �I�C\n";
    msg += "�Ȥl 20000 ��C\n";
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
    player->add_point("learn", 500);
    tell_object(player, HIY"(�A��o�F 500 �I�ǲ��I�ơC)\n"NOR);
    player->add("bank", 20000);
    tell_object(player, HIY"(�A��o�F 20000 ��Ȥl�C)\n\n"NOR);
    call_out("say_1", 2, npc);
}
void say_1() {
    message_vision(CYN"�����M�]�Ӥ@��W�i���ޮa...\n"NOR, this_player());
    message_vision("�ޮa��i�a���D�R"HIG"�D�H���n�F�I���Z..�}�l�򪺤��Z�S�ܦh�F�I\n\n"NOR, this_player());
    call_out("say_2", 2, this_object());
}
void say_2() {
    message_vision("��}�l�j�ۡR"HIG"����~���å����F�˦����I�֧�L��^�ӡI\n"NOR, this_player());
    message_vision("��}�l�W��ۡR"HIG"��~���ӤH�O������ˤl...��H���ѤF�H\n\n"NOR, this_player());
    message_vision(CYN"�X�o�Ӿ��|�ְ{�H�a...�O�ޥL�F�C\n"NOR, this_player());
}

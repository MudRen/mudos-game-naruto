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
    return "�o�J���ѹ�";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�츭�Ŭu�a�쥻�O�j�a���R�h���a��A�̪��M�_�X�\�h���ѹ���\n";
    msg += "�o�áA�O�Ŭu�Ϫ��ͷN�@���d�V�C�w������ФH���ˬd��o�{�O�U\n";
    msg += "���D���ѹ��̫r�}�F�ޤl�]�i�Ӫ��C���M�צn�F�ޤl���󤴵M����\n";
    msg += "�ߡA�]���ФH�����������C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 2;
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
    if( player->query("level") < 2 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/muye/npc/pooler.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"�ѹ��I�ѹ��I�����D�`�ڷl���F�h�֥ͷN�I\n"NOR,
        CYN"$N�y�W�C�@�����@��!�n���D�`�ͮ�!\n"NOR,
        "$N���$n���D�G"HIG"���F�����ѹ��٭n���ڹ����ҩ��I\n"NOR,
    });
        
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/muye/npc/mouse.c": 15,  // �ѹ�
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    mapping item = ([
        "/world/area/muye/npc/item/mouse_tail.c": 15, // ����
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
    return "/world/area/muye/npc/pooler.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"��㪺�T�O�����S���I\n"NOR,
        "$N���Ħa���D�G"HIG"$n�����ܦn�I�츭�Ŭu�P��$n�����I\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 120 �I�C\n";
    msg += "�Ȥl 150 ��C\n";
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
    player->add_point("learn", 120);
    tell_object(player, HIY"(�A��o�F 120 �I�ǲ��I�ơC)\n"NOR);
    player->add("bank", 150);
    tell_object(player, HIY"(�A��o�F 150 ��Ȥl�C)\n"NOR);
}

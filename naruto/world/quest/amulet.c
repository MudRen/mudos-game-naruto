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
    return "�@����";
}

// ���ȴy�z
string getDetail() {
    string msg;
        
    msg  = "�o��I�D�ݰ_�ӦL��o�¡A��������i��|�o�ͦ�����a�ڡA���i��\n";
    msg += "�V�ڡI\n\n";
    msg += "�U�ܻ����n�G���N�����O���A�S�N���|�X�Ʊ��I\n\n";
    msg += "�A�u�n�^�m�@�I���o���A�ڥi��O�ҧA�o�}�l���省�w�A���|�o�ͥ�";
    msg += "��N�~\n\n";
    msg += "���ȻݨD�G\n";
    msg += "    �Ȥl 1000000 ��C\n";
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
    return "/world/area/wizard/npc/temple_master.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"�o��I�D�ݰ_�ӦL��o�¡A��������i��|�o�ͦ�����a�ڡA���i���V�ڡI\n"NOR,
        "$N���$n���D�G"HIG"�U�ܻ����n�G���N�����O���A�S�N���|�X�Ʊ��I\n"NOR,
        "$N���$n���D�G"HIG"�A�u�n�^�m�@�I���o���A�ڥi��O�ҧA�o�}�l���省�w�A���|�o�ͥ���N�~�C\n"NOR,
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
    if( player->query("bank") < 1000000 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/world/area/wizard/npc/temple_master.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G"HIG"�ܦn�ܦn�I�ݨӧA�O�Q�q�F�A�ӨӨӡA�o���@���Ů��h�a�C\n"NOR,
        "$N���$n���D�G"HIG"���i�H�O���A���w���C\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "�@���@���šC\n";
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
    object amulet;

    amulet= new("/world/item/amulet.c");
    if( amulet->move(player) ) {
        tell_object(player, HIY"(�A��o�F�@���@���šC)\n"NOR);
    } else {
        if( !environment(player)->is_area() ) {
            amulet->move(environment(player));
            tell_object(player, HIY"(�A��o�F�@���@���šA���O���b�a�W�F�C)\n"NOR);
        } else {
            move_side(amulet, player);
            tell_object(player, HIY"(�A��o�F�@���@���šA���O���b�a�W�F�C)\n"NOR);
        }
    }
    player->add("bank", -1000000);
}

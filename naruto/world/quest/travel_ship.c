/*  travel_muye.c
        
    write by Acme       - 2007.02.05
 */

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
    return "�M�� - ������";
}

// ���ȴy�z
string getDetail() {
    string msg;
        
    msg  = "�o��i���ͪ��ܰڡA�֩w�O�s�Ӫ��C�ӨӨӡA���ڱa�A�@�@�o�ӥ@��\n";
    msg += "�쩳���Ӥ���ˤl�C\n\n";
    msg += "�ڻ��A�b�������u���j��D�v�W���W���u�����������v�������A�W\n";
    msg += "���i�O�E���F���h�n��O�I�Q�n���f�����N�ӥh�ݬݡI\n\n";
    msg += "���A�b�ȹC���ɭԤ��p�߰g�F���A�ڳo�̦��@���@�ɦa�ϡA�A�N���h\n";
    msg += "�ݬݧa�C(���O�Ghelp world)�C�t�~�A�A�i�H�H���H�a���b���~�d��\n";
    msg += "�a�ϡC(���O�Gmap)�C�i�H���W�A�ѧA�Ҩ��B����m�C\n\n";
    msg += "���O������b�u���j����D�v�W�����m�o�S���H��o�I�N��O�n��\n";
    msg += "�a�ϤW���@���s�u����ǰe�]�v���a��A���Y����s��K�O�ǰe��@\n";
    msg += "�ɦU�a���A�ȡA�]�L�k��F���̡I\n\n";
    msg += "����I�H�A�����D���ǰe�H���ڱбЧA�a�A���A��F�@�B�Aı�o��\n";
    msg += "���˪��a��ɡA�q�`�A�i�H�i��j��(���O�Gsearch)�C�j�����ᦳ��\n";
    msg += "�|�N�~�a�o�{���S�O���ƪ��s�b�C�q�`�b�o�ӮɭԡA�A�K�i�H�A�i�@\n";
    msg += "�B���d��(���O�Glook, �ҡGlook �P�l) �C�N�i�H�o���J�Ӫ��T��\n";
    msg += "�F�C�b�a�ϤW�p�G�o�{�C�⤣�P�άO�M����S�O���P���r�A�]�\����\n";
    msg += "����F��b���̳�I\n\n";
    msg += "�n�աA�o�ܤ��h���F�A�۫H�u�n�V�O�@�w������������������I\n";
    msg += "����N�h����"HIY"�|��"NOR"���ܧa�I\n";

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
    �^�ǫD�s�Ȫ��ܲŦX����C
 */
int preCondition(object player) {
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/wizard/npc/zhang.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�o��i���ͪ��ܰڡA�֩w�O�s�Ӫ��C�ӨӨӡA���ڱa�A�@�@�o�ӥ@�ɨ쩳���Ӥ���ˤl�C\n",
        "$N���$n���D�G�ڻ��A�b�u���j����D�v�W�����u�����������v�����I�@�ɬF�����F���i�Y�h�O�I\n",
        "$N���$n���D�G�A���ӭn�h�@��}�Ӳ��ɤ~�O�ڡC\n",
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
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/world/area/ship/npc/luffy.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G��H�O�s��j���s�A�Ӫ��ܡI\n",
        "$N���$n���D�G�ڭ̰��W�N�n�}���F�I\n",
        "$N���$n���D�G�@�_�Y�a�I\n",
    });
        
    return msg;
}

string getReward()
{
    string msg = "�ǲ��I�� 100 �I�C\n";
    msg += "�@������K���C\n";
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
    object food;

    player->add_point("learn", 100);
    tell_object(player, HIY"(�A��o�F 100 �I�ǲ��I�ơC)\n"NOR);

    food = new("/world/area/ship/npc/item/bento.c");
    if( food->move(player) )
        tell_object(player, HIY"(�A��o�F�@������K���C)\n"NOR);
    else {
        if( !environment(player)->is_area() ) {
            food->move(environment(player));
        } move_side(food, player);  // �Nfood����Pplayer�P�@�檺area�ϰ줤
        tell_object(player, HIY"(�A��o�F�@������K���A���O���b�a�W�F�C)\n"NOR);
    }
}
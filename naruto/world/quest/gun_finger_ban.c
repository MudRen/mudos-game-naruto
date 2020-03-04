#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

/* �����ȬO�_�୫�Ƹ�  return 0  ���୫��
                       return 1  �i����
   ��ĳ�̦n�]�w���୫�ơC
 */
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�·t�����q";
}

// ���ȴy�z
string getDetail() {
    string msg;

    if( this_player()->query("title") == "�@�ɬF�����x" ) {
        msg  = "����F�i���x�ҧi�������ȡA���L�A��򻡳o�]���I�L���A���F�Vù\n";
        msg += "�����_�ǲߪZ�N�~�M�n�h���`���x�����СA�P�˨������x�H��....��\n";
        msg += "�׶·t�����q�N�O�p���ܡA���F�ǲߡu"HIW"���j�E��"NOR"�v�ӷl���X�W�z�̤]\n";
        msg += "�L�ҿ�....���\�F��ؼЫ᪽���h��ù���E���_�N�i�H�F�A����F�i\n";
        msg += "���x�N�o�˰��q���s���i�D�A�C�u�Ʊ�A�]�������x���j�̪��I�v\n";
    } else if( this_player()->query("title") == "��s�s�X�x" ) {
        msg  = "�Ѣޢ����x����F�i�ҧi�������ȡA���F�Vù�����_�ǲߪZ�N�ӥh��\n";
        msg += "���x���Э�Ӯ��x�����O�o�򪺲J�G�A���L�o����x���G���I�²ª�\n";
        msg += "�A�~�M��o�Ʊ��i�D�F�@������٤���ı....���F�ǲߡu"HIW"���j�E��"NOR"�v\n";
        msg += "....�H�K�a�I���\�F��ؼЫ᪽���h��ù���E���_�N�i�H�F�A����F\n";
        msg += "�i�N�o�˰��q���s���i�D�A�C�u�Ʊ�A�]�������x���j�̪��I�v\n";
    } else {
        msg  = "�p�G�A�ݨ�o�����ӬO���ȥX���F...�֧�Ův�ӭײz�a�C\n";
    }
    return msg;
}

// ���ȵ���
int getLevel() {
    return 20;
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
    if( player->query("guild") != "piece" ) return 0;
    if( player->query_skill("gun ban", 1) ) return 0;
    if( player->query_class() == "work_sea" ) return 0;
    if( player->query_class() == "little_sea" ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/sifa_isle/npc/si.c";   // ����F�i
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"����I$n�N�O���e����Q��ù�����_�ǲߪZ�N���H�a�I\n"NOR,
        "$N���D�G"HIG"�u�n$n��U��������x���СA�Q�[�J�Ѣޢ��]���O���D���I\n"NOR,
        "$N���D�G"HIG"�����o�@�ӱj�̴N��l���X�ʭӮz�̤]�L�ҿסI\n"NOR,
        "$N���D�G"HIG"���I�O�ڤ@�w�n�w�����I\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/ship/npc/soldier2.c": 20,     // ���x����
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
    return "/world/area/sifa_isle/npc/lu.c";   // ù�����_
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�ܩ_�Ǫ�������$n.\n"NOR,
        "$N���D�G"HIG"��F�A�J�M�O���x���R�O¾�~�S������t�O�C\n"NOR,
        "$N���D�G"HIG"$n�N�n�n�ǵۧa�C\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIW"���j�E��"NOR"�v\n";
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
    player->set_skill("gun ban", 2);
    tell_object(player, HIY"(�g�Lù�����_�����ɫ�A�A�Ǩ촳����n�F)\n"NOR);
}

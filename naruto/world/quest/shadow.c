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
    return "�U�l�Ŭu";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "��H��ۤT�Ԥ��@���ۨӤ]�צ�ԳN�]���@�q�ɶ��F�A�o���쥻�w�w\n";
    msg += "�n��j�Ѵ˪L���Ŭu�ϡu�����v���O��F�Ŭu�ϮɦۨӤ]�ݨ�F�@��\n";
    msg += "�U�l�A�ߨ�k�M�j��A�������H�|�F�@�y�A�s�צ�]���ޤF�A��H\n";
    msg += "�u�n�^�@�֩��ѩ��Y���ѡC���F����~��צ�ԳN�A��H��A������\n";
    msg += "���j�Ѵ˪L���U�l�C\n";

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
    if( player->query("guild") != "muye" ) return 0;
    if( player->query_class() == "inferior" ) return 0;
    if( player->query_skill("shadow", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/muye/npc/naruto.c";   // ��H
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���y�ôb�A�s�ѳ��֭n�w��F.\n"NOR,
        "$N���D�G"HIG"�n��P�H���n�Чڷs�ԳN�A���@�ݨ�U�l�N�𪺶]���F�I\n"NOR,
        "$N���D�G"HIG"$n�h���������j�Ѵ˪L���U�l�a�I\n"NOR,
        "$N���D�G"HIG"�p�G�n��P�H�Чڷs�ԳN�A�ڴN��$n�v�������N�I\n"NOR,
    });
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/old_forest/npc/monkeyg.c": 20,   // ���U
        "/world/area/old_forest/npc/monkeyb.c": 15,   // ���U
        "/world/area/old_forest/npc/monkeys.c": 10,   // ���U
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
    return "/world/area/muye/npc/naruto.c";   // ��H
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�G"HIG"$n��U�l�����F�ܡI�n��P�H�I�S���U�l�F�I\n"NOR,
        CYN"�ۨӤ]���M�X�{�b����.\n"NOR,
        "�ۨӤ]���D�G"HIG"�n�a�I���ڭ̰��W�L�h�I\n"NOR,
        "$N���D�G"HIG"�o�O�v�����N�����b�A$n�n�n�ǧa�I�ڤ]�n�h�Ƿs�ԳN�F�I\n"NOR,
        CYN"$N��ۦۨӤ]�@�_���}�F�@�֩��ѩ�.\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "�ǲߧޯ�u"HIB"�v�����N"NOR"�v\n";
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
    player->set_skill("shadow", 2);
    tell_object(player, HIY"(�A�ݵۻ�H�d�U�����b�A�N�v�����N�Ƿ|�F)\n"NOR);

    // ��H����
    destruct(npc);
}

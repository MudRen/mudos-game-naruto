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
    return "�ѱi�Ļ���";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "���M�ѱi�]���k��Q�D�H�j���Ӥ߱��{�e�A���O�]���Ʊ�ۤv������\n";
    msg += "�N�����ǡA�]���b�A�d�U���U���U�A�ѱi�M�w�N�L���F�����Ѫ��t�@\n";
    msg += "���⵴���u�Ļ��ѡv�Ǳµ��A�A�Ʊ�b�ѱi�Z�o���оɤU�A����p�@\n";
    msg += "�Ƿ|�o�����ޡC\n";

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
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/world/area/echo/npc/zhang.c";  // �ѱi
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
     CYN"$n�Q�V$N���v�A���O�o�Q$N�@�f�^���F�C\n"NOR,
        "$N���D�G"HIG"�ڤk��w�g�Q�쨫�n�X�Q�ѤF�A���٦��߱����{�·~�I\n"NOR,
        "$n���D�G"HIG"���D�z�Ʊ�z�������N�����ǶܡI\n"NOR,
        "$n���D�G"HIG"�N��z�]�����b���ѡA�������U�z�~��A�Ȥj���a�I\n"NOR,
     CYN"$Nť�D��h�F�@�U�A�w�w�a�ĤF�f��C\n"NOR,
        "$N���D�G"HIG"�n�a�I�ڤ]���Q���ڪ��������ǡI\n"NOR,
        "$N���D�G"HIG"$n�h��Ļ��Ѫ����Ʒj���^�ӡA�ڴN�ЧA�s�@�Ļ��ѡI\n"NOR,
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
        "/world/area/rural_area/npc/item/chile.c": 5,    // ������
        "/world/area/rural_area/npc/item/soy.c": 1,      // ��o
        "/world/area/rural_area/item/powder02.c": 1,     // ���ԯ�
        "/world/area/rural_area/item/pill_obj04.c": 5,   // �p����
        "/world/area/rural_area/item/pill_obj01.c": 5,   // �Ե�
        "/world/area/rural_area/item/pill_obj02.c": 10,  // ���ڽ�
        "/world/area/rural_area/npc/item/sugar.c": 5,    // �}
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
    return "/world/area/echo/npc/zhang.c";  // �ѱi
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
     CYN"$N�ݵ�$n�ǳƪ����ơA���N���I�I�Y�C\n"NOR,
        "$N���D�G"HIG"�ǳƦn�F�N�}�l�a�A�⻶�ԥ����F�z���C\n"NOR,
        "$N���D�G"HIG"�M���J���Ӫ��Ե���ڽ��A�[�J�ĵ���Y�C\n"NOR,
        "$N���D�G"HIG"�����u�F�A�[�J���ԯ��A�A�q������M�}�ը��C\n"NOR,
        "$N���D�G"HIG"��o�t��A�M��U�ѡA���u�C\n"NOR,
     CYN"$n��ť���J�ӡA���M�@�h�~�Q��e�@�y�ܡA���u�H\n"NOR,
    });

    return msg;
}

string getReward()
{
    string msg = "�ǲ߻Ļ��ѡC\n";
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

    item = new("/world/area/echo/npc/item/noodle2.c");
    if( item->move(player) )
        tell_object(player, HIY"(�A��o�F�@�J�Ļ��ѡC)\n"NOR);
    else {
        // �N�������~����P���a�P�@�檺area�ϰ줤
        // �p�G�O�b area ���A��item����player�ҳB���y�Ц�m
        if( environment(player)->is_area() ) move_side(item, player);
        // �p�G�O�b room ���A��item����player�ҳB���ж���
        else item->move(environment(player));
        tell_object(player, HIY"(�A��o�F�@�J�Ļ��ѡA���O���b�a�W�F�C)\n"NOR);
    }
    message_vision("\n$N���D�G"HIG"$n�Ƿ|�Ļ��ѤF�a�A�֥h�A�Ȥj���O�ӷЧڤF�C\n"NOR, npc, player);
    message_vision("$n�x�b�a���D�G"HIG"�v�űz��~���ӧ֤F...�ڨS�O�M��...\n"NOR, npc, player);
    message_vision(CYN"$N���y�d�h���C�n�۵ۡG�֯�ϱϧڪ��k����I\n"NOR, npc, player);
    message_vision("$n�x�b�a���D�G"HIG"�v�šH...\n"NOR, npc, player);
    message_vision(CYN"$N���y�d�h���C�n�۵ۡG�֯�ϱϧڪ��k����I\n"NOR, npc, player);
    message_vision("$n���D�G"HIG"......\n"NOR, npc, player);
    message_vision(CYN"$N���y�d�h���C�n�۵ۡG�֯�ϱϧڪ��k����I\n"NOR, npc, player);
    tell_object(player, HIY"(�A�߸̤@�Q...��F�N����ɶ��R�J�ѧa�C)\n"NOR);
}

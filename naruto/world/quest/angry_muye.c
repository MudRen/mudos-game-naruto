/*  TestQuest.c
	
	�@�ӥΨӴ��ե��Ȩt�Υ��T�ʪ����եΥ��ȡA�]�O���ȼ��g���d�ҡC
	
	�ثe���Ȥ䴩�����G
		1. �����Y�Ǽƶq���Ǫ�
		2. ���o�Y�Ǽƶq�����~
		3. �y�X�ʥ���  (�N���YA�n�A�h��YB�A�Y�i��������)
	
	�`�N�G�]���H�ɦW���ѧO�A�b�]�w���ɦW�O�o�[�W .c 
	
    write by Acme	- 2007.02.04
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
    return "�ͮ𪺤츭�Y";
}

// ���ȴy�z
string getDetail() {
    string msg;
	
    msg  = "�츭�����츭�Y�e�Ǥ�l�h�j�Ѵ˪L���̮ɡA�Q�@�j�s��U�ƨg���l\n";
    msg += "���C�츭�Y�n�D�A���L�аV�o�ǵU�l�A�ña�@�ǵU�����ҩ��C\n";

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
    return "/world/area/muye/npc/muye.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�`�`���ĤF�@�f��C\n"NOR,
        "$N���$n���D�G�e�Ǥ�l�ڨ�j�Ѵ˪L���̮ɡA�Q�@�j�s��U�l���C\n",
        "$N���$n���D�G�٤��ɪ����ۤl��ڡA��b�O�����ܡA�𦺧ڤF�C\n",
        "$N���$n���D�G�A�����ڥh�аV�аV���ǵU�l�ܡH���e���|�I�W�Y�~�O�ڡC\n",
        "$N���$n���D�G���K�a�@�ǵU���^�ӡA�ҩ��A�w�g�аV�F���ǵU�l�C\n",
    });
	
    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/old_forest/npc/monkey.c": 5,  // �U�l
        "/world/area/old_forest/npc/monkeyb.c": 5, // ���U
        "/world/area/old_forest/npc/monkeys.c": 5, // ���U
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    mapping item = ([
        "/world/area/old_forest/npc/item/monkey_tooth.c": 10, // �U��
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
    return "/world/area/muye/npc/muye.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G��b�O�ӴΤF�A�n�����ǵU�l�|�I�W�Y�~�O�ڡI\n",
        "$N���$n���D�G�u�O�P�§A�r�I\n",
        CYN"$N�ּ֪���R���СC\n"NOR,
    });
	
    return msg;
}

string getReward()
{
        string msg = "�ǲ��I�� 1000 �I�C\n";
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
        player->add_point("learn", 1000);
    tell_object(player, HIY"(�A��o�F 1000 �I�ǲ��I�ơC)\n"NOR);
}

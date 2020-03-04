/* �ԳN�G�����N(substitute) */

#include <ansi.h>
#define SKILL_NAME "substitute"
#define SKILL_NAME_C "�����N"
#define SKILL_CLASS "ninja"

inherit SKILL;

void create()
{
    seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
}

string query_class() { return SKILL_CLASS; }

// �n enable �~�|���@��
int valid_enable(string base_skill) { return base_skill == "dodge"; }

void skill_advanced(object me, string skill)
{
    int lv = me->query_skill(skill, 1);
    switch( lv ) {
        case 189: me->set_skill_require(skill, 1500000); break; // ���d3 : 189��190
        case 149: me->set_skill_require(skill, 1000000); break; // ���d2 : 149��150
        case  99: me->set_skill_require(skill, 500000);  break; // ���d1 :  99��100
        default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

string *defend_message = ({
    HIW"�uť���u�I�v���@�n�A���$n�������O�@���j���Y�C\n"NOR,
    HIW"�b����$N�������ܦ��F�@���j���Y�C\n"NOR,
    HIW"�@�}���ϹL�h�A���$n�������O�@���j���Y�C\n"NOR,
});

string *dodge_msg = ({
    "���O�M$p$l���F�X�o",
    "���O�Q$p���F�a���}�F",
    "���O$n���l�@���A�{�F�}�h",
    "���O�Q$p�ή��׶}",
    "���O$n�w���ǳơA���W���������}",
    "���O�S��",
});

string *dodge_enable = ({
    "���O$N�������u�O$n���ۼv",
    "�P�a�@�n�A$N�����F���e�����Y",
    "��$n���v���M�����A��ӥu�O������",
    "$N�h���z�z�s�A�~�M����F�@�L�a�ä�����",
    "���G�@�����߹��q�Ť����U�ӯ{��$N���Y",
    "�|�P�Ф�í��A���$N�����������Ӫ��E�Y",
});

// target ����ˮ`�e�A���ޯ���]�L receive_damage 
// �p��K�i�H�s�@ "�ȮɵL�ħ�" �άO "�ˮ`�l����" �������ޯ�
int receiveDamage(object me, object target, int damage)
{
    int ratio;
    string msg;
    if( me->query_skill(SKILL_NAME) < 20 ) return damage;
    ratio = me->query_skill(SKILL_NAME)*10/200;
    
    // �m���� 10% �����|�����l���ˮ`
    if( ratio < random(100) ) return damage;
    
    // �T��
    msg = defend_message[random(sizeof(defend_message))];
    message_vision(msg, me, target);

    // �l��mp
    me->damage_stat("mp", random(damage/10) + 1, me);
    
    // �W�[�ޯ�g��
    me->improve_skill(SKILL_NAME, 1);
    
    return 0;
}

string getEvadeAction(object me)
{
    string skill = me->skill_mapped("dodge");

    // �S�� enable ����ޯ�
    if( !skill || skill == "dodge" )
        return dodge_msg[random(sizeof(dodge_msg))];
    else return dodge_enable[random(sizeof(dodge_enable))];
}

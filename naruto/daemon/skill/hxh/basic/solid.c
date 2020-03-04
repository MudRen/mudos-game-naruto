// �y�H����O�G��(solid)
// create by Tmr
// update by Acme 2007.03.16
// �y�L�W�j�ĪG by mouse 2007/7/25

#include <ansi.h>
#define SKILL_NAME "solid"
#define SKILL_NAME_C "��"
#define SKILL_CLASS "psychical"

inherit SKILL;

// �n�D DEMON_D �n���ޯ�
void create()
{
    seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
}

// �ޯ����
string query_class() { return SKILL_CLASS; }

// �n enable �~�|���@��
int valid_enable(string base_skill) { return base_skill == "parry"; }

// �ޯ�ɯū�|�I�s���禡�A�q�`�Ψӳ]�w�ɤU�@�ũһݪ��g��
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

string *parry_msg_solid = ({
    HIW"�uť���u�I�v���@�n�A$N�N���O�b�����w��������C\n"NOR,
    HIW"$n����b�K�ɤ����ܪ����i�R�A�յ۫d�z$N�������¤O�C\n"NOR,
    HIW"�b�d�v�@�v���ڡA$n�j�T�a�������W���O���K�סA�թ�צ�$N�������C\n"NOR,
});

string *parry_msg = ({
    "���O�Q$n��}�F",
    "���O�Q$n�צ�F",
});

string *parry_enable = ({
    "���O$n�B�ΰ���פF$N������",
    "���O$n�ϥΰ�N�𶰤��b�ó��A�w�ͥͦa�צ�F$N������",
    "$n�ߧY�o�ʰ�N$N������}�F",
});

int receiveDamage(object me, object target, int damage)
{ 
    int lv;

    // enable���P�_�n�����~�Aparry�S�˰�̵M�|�ϥΡA�ҥH�b�o�]�[�W�P�_
    if( me->skill_mapped("parry") != "solid" ) return damage;
    if( me->query_stat("mp") < 100 ) return damage;

    lv = me->query_skill(SKILL_NAME)*2 + random(me->query_skill("parry"));
    if( random(me->query_skill(SKILL_NAME)) < random(200) ) return damage;

    // ��ˮ`�N�w�g�O 0 �F�A�ϥΰ�o�ܦ����ˮ`
    // ���Ӷˮ`�W�L��@�w�ȥH�W�~�|�y���ˮ`
    // �L�C�N�@�ˬO�� 0 �w
    if( damage > lv/2 ) {
        damage -= lv;
        if( damage < 0 ) damage = random(20) + 5;
    } else {
        damage = 0;
    }
    // ���\�[�j���m
    message_vision(parry_msg_solid[random(sizeof(parry_msg_solid))], target, me);

    // �����@�ǩ��O
    me->damage_stat("mp", damage/20+random(10), me);

    // �W�[�g���
    me->improve_skill(SKILL_NAME, 1);

    return damage;
}

string getDefendAction(object me)
{
    string skill = me->skill_mapped("parry");

    // �S�� enable ����ޯ�
    if( !skill || skill == "parry" )
        return parry_msg[random(sizeof(parry_msg))];
    else return parry_enable[random(sizeof(parry_enable))];
}

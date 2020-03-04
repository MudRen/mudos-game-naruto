// ���ҳ� npc �Ϊ� by mouse 2007/7/26

#include <ansi.h>
#define SKILL_NAME "noshadow step"
#define SKILL_NAME_C "�L�v�}"
#define SKILL_CLASS "activity"

inherit SKILL;

void create()
{
    seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
}

string query_class() { return SKILL_CLASS; }

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
    HIW"$N"HIW"�}�U�B��s��A���������b$n�����e�C\n"NOR,
    HIW"$N"HIW"�ϥX�u�L�v�}�v�b$n�٨S�`�N��ɴN¶����F�C\n"NOR,
    HIW"$N"HIW"���M�X�{�b$n������A��$n�~�F�@�j���C\n"NOR,
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

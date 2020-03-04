#include <ansi.h>
#define SKILL_NAME "body iron"
#define SKILL_NAME_C "�K��"
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
    HIW"�u���v�a�@�n�A$n"HIW"�������n������F���K�C\n"NOR,
    HIW"$n"HIW"�ΤO��$N"HIW"�����o�������K���@��ⳣ�¤F...\n"NOR,
    HIW"$N"HIW"�ϥίS��"NOR"�y�K���z"HIW"�w�O���$n"HIW"�������C\n"NOR,
});

// target ����ˮ`�e�A���ޯ���]�L receive_damage 
// �p��K�i�H�s�@ "�ȮɵL�ħ�" �άO "�ˮ`�l����" �������ޯ�
int receiveDamage(object me, object target, int damage)
{
    int ratio, sk;
    string msg;

    sk = me->query_skill(SKILL_NAME);

    if( me->query_skill(SKILL_NAME) < 20 ) return damage;
    ratio = sk/10;

    // �T��
    // �m���� 20% �����|�l���ˮ` 600
    if( ratio > random(100) ) {
        msg = defend_message[random(sizeof(defend_message))];
        message_vision(msg, me, target);
        if( damage <= sk*3 ) {
            message_vision(HIW"$N"HIW"�������m�F$n"HIW"�������A�S���y������ˮ`�C\n"NOR, me, target);
            me->damage_stat("mp", random(damage/10) + 1, me);
            return 0;
        } else {
            damage = damage - sk*3;
            message_vision(HIW"$N"HIW"���M�ϥ��K����ק����A���M�Q�}���m�y��"HIR"("+damage+")"HIW"�I�ˮ`�C\n"NOR, me, target);
            me->damage_stat("mp", random(sk*3/10), me);
        }
        // �W�[�ޯ�g��
        me->improve_skill(SKILL_NAME, 1);
        return damage;
    }
    return damage;
}

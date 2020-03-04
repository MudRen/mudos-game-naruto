#include <ansi.h>
#define SKILL_NAME "wolf blade"
#define SKILL_NAME_C "�M�T�y"
#define SKILL_CLASS "blade"

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

int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/20;
}

int attack(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*9/40;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "flow" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�� flow �o�ӥ\\��C\n");
        return 0;
    }

    if( me->query_skill("blade", 1) < 50 || sk < 20 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk ) {
        tell_object(me, "�A�����A�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_condition("bladewolf", 1) != 0) {
        tell_object(me, "�A�w�g�b�ϥ�" + SKILL_NAME_C + "�ޥ��F�C\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, int sk)
{
    mapping cnd = ([]);

    message_vision("$N"HIC"�ϥX��u�@��ޥ��y"HIG+SKILL_NAME_C+HIC"�z�I\n"NOR, me);

    cnd["name"] = HIG+SKILL_NAME_C+NOR;
    cnd["duration"] = sk/2;
    cnd["intimidate"] = sk/2;
    cnd["evade"] = sk/2;

    me->set_condition("bladewolf", cnd);
    me->damage_stat("mp", sk, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act)
{
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, sk) ) return 1;

    do_perform(me, sk);
    return 1;
}

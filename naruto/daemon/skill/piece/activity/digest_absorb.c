#include <ansi.h>
#define SKILL_NAME "digest absorb"
#define SKILL_NAME_C "���Ƨl��"
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

int wittiness(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/40;
}

int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/20;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "check" ) {
        tell_object(me, "�ثe"+SKILL_NAME_C+"�� check �o�ӥ\\��C\n");
        return 0;
    }

    if( me->query_condition("da_busy") ) {
        tell_object(me, "�A�~��ϥιL���Ƨl���A�y�L�𮧤@�U�A�Χa�C\n");
        return 0;
    }

    if( sk < 60 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk*3/2 ) {
        tell_object(me, "�A�����A�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_condition("da", 1) != 0) {
        tell_object(me, "�A�w�g�b�ϥ�" + SKILL_NAME_C + "�ޥ��F�C\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, int sk)
{
    mapping cnd = ([]);

    me->damage_stat("mp", sk*3/2, me);
    message_vision("$N���بϥ�"HIW"�u�ͩR�k��E���Ƨl���v"NOR"�A���驿�D���G...\n"NOR, me);

    cnd["name"] = HIW+SKILL_NAME_C+NOR;
    cnd["duration"] = sk/8;
    cnd["hp"] = me->query_stat_maximum("hp")*(sk/100)/100;

    me->set_condition("da", cnd);

    cnd["name"] = HIW+"(CD)����"+NOR;
    cnd["duration"] = sk/2;

    me->set_condition("da_busy", cnd);
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

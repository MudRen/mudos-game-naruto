#include <ansi.h>
#define SKILL_NAME "snipe soul"
#define SKILL_NAME_C "��������"
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

int exact(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/8;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "up" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�u�� up �o�ӥ\\��C\n");
        return 0;
    }

    if( me->query_condition("snipe", 1) != 0) {
        tell_object(me, "�A�w�g�b�ϥ�" + SKILL_NAME_C + "�F�C\n");
        return 0;
    }

    if( me->query_skill("activity", 1) < 100 || sk < 20 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk ) {
        tell_object(me, "�A�����A�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, int sk)
{
    mapping cnd = ([]);

    message_vision("$N���X����l����a�b�y�W�A�i�{�X"HIY"�y"HIR"������"HIY"�z"NOR"�V�ۤv�������������ݻ��I\n"NOR, me);

    cnd["name"] = HIY"������"NOR;
    cnd["duration"] = sk/4;
    cnd["exact"] = sk;
    cnd["defend"] = sk/2;

    me->set_condition("snipe", cnd);
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

#include <ansi.h>
#define SKILL_NAME "fight body"
#define SKILL_NAME_C "��ø�Z��"
#define SKILL_CLASS "martial"

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
    return ability + me->query_skill(SKILL_NAME)*13/200;
}

int sock(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/40;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�"+SKILL_NAME_C+"�C\n");
        return 0;
    }

    if( act != "check" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�� check �o�ӥ\\��C\n");
        return 0;
    }

    if( me->query_skill("martial", 1) < 50 || sk < 20 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_condition("fb_busy", 1) != 0) {
        tell_object(me, "����������վA������~��ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_stat("mp") < sk*3/2 ) {
        tell_object(me, "�A�����A�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, int sk)
{
    mapping cnd = ([]);

    message_vision("$N"HIY"������v���ܤơA�����̾A�X�԰������A�C\n"NOR, me);

    cnd["name"] = HIR+SKILL_NAME_C+NOR;
    cnd["duration"] = sk/4;
    cnd["attack"] = sk/2;
    cnd["intimidate"] = sk/2;

    me->set_condition("fb", cnd);

    cnd["name"] = HIR"(�վA)"NOR;
    cnd["duration"] = sk+random(50);

    me->set_condition("fb_busy", cnd);

    me->damage_stat("mp", sk+random(sk/2), me);
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

// ��D���� ���ԤY�ϥ�

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("akimichi2");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    mapping buff = ([]);

    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIR"$N�餺�����N�ש���������z�o�X�ӡA��$N�h�W�����C\n"NOR, me);

        buff["name"] = RED"�����P"NOR;
        buff["duration"] = 300;

        me->set_condition("akimichi3", buff);
        me->delete_condition(cnd);
        return;
    }
}

void condition_apply(object me, string cnd, mapping cnd_data)
{
    mapping mcnd;

    if( !mapp(mcnd = me->query_condition(cnd)) ) mcnd = ([]);

    mcnd["duration"] = cnd_data["duration"];

    me->add_temp("apply/attack", mcnd["attack"] );   // �����O�q
    me->add_temp("apply/armor", mcnd["armor"] );     // ���m�O�q
    me->add_temp("apply/mp", mcnd["mp"] );           // �]�O
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "akimichi2" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("akimichi2");
    if( !cnd_data ) return;

    me->add_temp("apply/attack", -cnd_data["attack"] );
    me->add_temp("apply/armor", -cnd_data["armor"] );
    me->add_temp("apply/mp", -cnd_data["mp"] );

    if( me->query_stat("mp") > me->query_stat_maximum("mp") ) me->set_stat_current("mp", me->query_stat_maximum("mp"));
}

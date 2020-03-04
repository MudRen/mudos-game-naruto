// ���L���s

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("fourskills");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision("$N"CYN"���W���L���s���ĪG�w�g�ֳt�����F�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}

void condition_apply(object me, string cnd, mapping cnd_data)
{
    mapping mcnd;
    
    if( !mapp(mcnd = me->query_condition(cnd)) ) mcnd = ([]);
    
    mcnd["duration"] = cnd_data["duration"];
    
    me->add_temp("apply/exact", 100 );          // �W�[�R����O
    me->add_temp("apply/evade", 100 );          // �W�[�j�ׯ�O
    me->add_temp("apply/attack", 100 );         // �W�[�����O�q
    me->add_temp("apply/armor", 100 );          // �W�[���m�O�q
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "fourskills" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("fourskills");
    if( !cnd_data ) return;

    me->add_temp("apply/exact", -100 );          // ��֩R����O
    me->add_temp("apply/evade", -100 );          // ��ְj�ׯ�O
    me->add_temp("apply/attack", -100 );         // ��֧����O�q
    me->add_temp("apply/armor", -100 );          // ��֨��m�O�q
}

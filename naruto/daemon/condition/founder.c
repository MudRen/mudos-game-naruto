// ű�y

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("founder");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( me->query_temp("founder") >= 10 ) {
        message_vision(HIC"$N�ΤO����ۭ��l�A���������l�[�šC\n"NOR, me);
        me->add_temp("founder2", 1);
        me->set_temp("founder", 0);
    }
    if( me->query_temp("founder2") >= 10 ) {
        message_vision(HIR"$N�`�N�ۧ��ƪ��N���{�סA�N�Ȥ@�ɮ̯��X�F�t���C\n"NOR, me);
        me->set_temp("founder2", 0);
    }
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIY"���l���ūקֳt�U���A�G�A�X���w�g�����A�Ӷi��̫�u�@(getwp)�F�C\n"NOR, me);
        me->delete_condition(cnd);
        me->delete_temp("founder");
        me->delete_temp("founder2");
        me->start_busy(1);
        return;
    }
    me->start_busy(2);
    me->add_temp("founder", 1);
}
void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "founder" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("founder");
    if( !cnd_data ) return;

    // �H���U�@�A�b�o�̤]�R�@��temp
    me->delete_temp("founder");
    me->delete_temp("founder2");
}

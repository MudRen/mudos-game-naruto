// �����ഫ�ΧN�o��

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("ghost_change_down");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIW"$N���G�Pı�믫�n�h�F\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}

void condition_apply(object me, string cnd, mapping cnd_data)
{
    mapping mcnd;
    
    if( !mapp(mcnd = me->query_condition(cnd)) ) mcnd = ([]);
    
    mcnd["duration"] = cnd_data["duration"];
    
    me->add_temp("apply/str", -mcnd["str"] );   // ���
    me->add_temp("apply/dex", -mcnd["dex"] );   // ���
    me->add_temp("apply/con", -mcnd["con"] );   // ���
    me->add_temp("apply/int", -mcnd["int"] );   // ���
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "ghost_change_down" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("ghost_change_down");
    if( !cnd_data ) return;

    me->add_temp("apply/str", cnd_data["str"] );   // �W�[
    me->add_temp("apply/dex", cnd_data["dex"] );   // �W�[
    me->add_temp("apply/con", cnd_data["con"] );   // �W�[
    me->add_temp("apply/int", cnd_data["int"] );   // �W�[
}

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("body_strength_cond");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        return;
    }
}

void condition_apply(object me, string cnd, mapping cnd_data)
{
    me->add_temp("apply/attack", cnd_data["attack"] );          // �W�[�����O
    me->add_temp("apply/armor", cnd_data["armor"] );            // �W�[���m�O
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    me->add_temp("apply/attack", -cnd_data["attack"] );
    me->add_temp("apply/armor", -cnd_data["armor"] );
}

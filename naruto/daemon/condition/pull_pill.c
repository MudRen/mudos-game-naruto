// �޹A�@���Ϊ�

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("pull_pill");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(CYN"$N���Y�Q�F�Q�A�{�b�^�h���Ӥ��|�Q��F�a�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}

// �c�]���}��cd

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("diabo_busy");
}

// �i�H�Ψӵ��ޯ�W�[�N�o���ɶ�
// �W�r��ɶ��������w, �ۥѮM�J�a
// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        return;
    }
}
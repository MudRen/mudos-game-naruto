// ��D���� �Ե�Y�B�@���Y�ϥ�

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("akimichi3");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( me->query_temp("chili_blood") >= 10 ) {
        message_vision(HIR"$N���M�R�X�@�j�f�A��A²���N�֭˦b�a�W�F�C\n"NOR, me);
        me->receive_damage(me->query_stat("hp")*4/5, me);
        me->damage_stat("ap", me->query_stat("ap")*4/5, me);
        me->set_temp("chili_blood", 0);
    }
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(CYN"$N�ݰ_�Ӧ��G�n�h�F�C\n"NOR, me);
        me->delete_condition(cnd);
        me->delete_temp("chili_blood");
        return;
    }
    me->add_temp("chili_blood", 1);
}
void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "akimichi3" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("akimichi3");
    if( !cnd_data ) return;

    // �H���U�@�A�b�o�̤]�R�@���R��temp
    me->delete_temp("chili_blood");
}

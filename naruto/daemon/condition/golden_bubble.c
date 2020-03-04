// �d���k���w�w�G��-�����w�j�ĪG

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("golden_bubble");
}

// �C update �@�� �P�_�O���O�٦b�԰��A���O�N�Ѱ�
void condition_update(object me, string cnd, mixed cnd_data)
{
    mapping weapons;
    string skill;
    object ob;

    if( !me->is_fighting() ) {
        message_vision(HIC"$N"NOR+HIC"�n���e���k���F�԰��A�ߨ����N�w�w�~���C\n"NOR, me);
        me->delete("no_defend");
        me->delete("no_combat");
        me->delete_condition("golden_bubble");
        return;
    }
    // �Τ߸��P�_�Z��
    if( me->query_condition("golden_bubble") != 0 && mapp(weapons = me->query_temp("weapon")) && sizeof(weapons) ) {
        foreach(skill, ob in weapons) ob->unequip();
    }
    me->set("no_defend", 1);      // ���ਾ�m
    me->set("no_combat", 1);      // �������
}
void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "golden_bubble" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("golden_bubble");
    if( !cnd_data ) return;

    me->delete("no_defend");
    me->delete("no_combat");
}

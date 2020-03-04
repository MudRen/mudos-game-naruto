// �|�}���N

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("four_foot");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    mapping weapons;
    string skill;
    object ob;

    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision("$N���W��"HIR"�~��"NOR"�w�g�������h�F�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }

/* �Z�������Ȯɮ���
    if( me->query_condition("four_foot") != 0 && mapp(weapons = me->query_temp("weapon")) && sizeof(weapons) ) {
        foreach(skill, ob in weapons) ob->unequip();
    }
*/

}

void condition_apply(object me, string cnd, mapping cnd_data)
{
    mapping mcnd;
    
    if( !mapp(mcnd = me->query_condition(cnd)) ) mcnd = ([]);
    
    mcnd["duration"] = cnd_data["duration"];

    me->set_race("beast");                                 // �ܦ��ʪ�
    me->add_temp("apply/attack", mcnd["attack"] );         // �W�[�����O�q
    me->add_temp("apply/evade", mcnd["evade"] );           // �W�[�j�ׯ�O
    me->add_temp("apply/ap", mcnd["ap"] );                 // �W�[��O
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "four_foot" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("four_foot");
    if( !cnd_data ) return;

    me->set_race("human");
    me->add_temp("apply/attack", -cnd_data["attack"] );
    me->add_temp("apply/evade", -cnd_data["evade"] );
    me->add_temp("apply/ap", -cnd_data["ap"] );

    if( me->query_stat("ap") > me->query_stat_maximum("ap") ) me->set_stat_current("ap", me->query_stat_maximum("ap"));
}

/* apheal4.c 
   ���A ap ����_�į�A��_�q�O�T�w��

   ��Ƶ��c
   ([ "duration": �ɮ� ])
*/
#include <ansi.h>

inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("apheal4");
}

void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !living(me) ) return;
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        return;
    }

    // ��_AP��
    me->heal_stat("ap", 40);
}


void food_condition_apply(object me, mapping cnd_data)
{
    mapping apheal;
    
    if( !mapp(apheal = me->query_condition("apheal4")) )
        apheal = ([]);
    
    apheal["duration"] += cnd_data["duration"];
    apheal["name"] = BGRN"��Ŵ����N"NOR;
    
    if( apheal["duration"] <= 0 ) apheal["duration"] = 1;
    else if( apheal["duration"] > 140 ) apheal["duration"] = 140;
    
    me->set_condition("apheal4", apheal);
}

/*
void condition_apply(object me, string cnd, mapping cnd_data) { }
void condition_unapply(object me, string cnd, mapping cnd_data) { }
*/
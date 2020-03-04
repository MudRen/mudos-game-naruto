/* mpheal2.c 
   ���A mp ����_�į�A��_�q�O�T�w��

   ��Ƶ��c
   ([ "duration": �ɮ� ])
*/
#include <ansi.h>

inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("mpheal2");
}

void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !living(me) ) return;
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        return;
    }

    // ��_MP��
    me->heal_stat("mp", 20);
}


void food_condition_apply(object me, mapping cnd_data)
{
    mapping mpheal;
    
    if( !mapp(mpheal = me->query_condition("mpheal2")) )
        mpheal = ([]);
    
    mpheal["duration"] += cnd_data["duration"];
    mpheal["name"] = BMAG"�ЯŤѦa�N"NOR;
    
    if( mpheal["duration"] <= 0 ) mpheal["duration"] = 1;
    else if( mpheal["duration"] > 180 ) mpheal["duration"] = 180;
    
    me->set_condition("mpheal2", mpheal);
}

/*
void condition_apply(object me, string cnd, mapping cnd_data) { }
void condition_unapply(object me, string cnd, mapping cnd_data) { }
*/

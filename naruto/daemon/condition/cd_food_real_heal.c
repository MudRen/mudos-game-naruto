/* cd_food_real_heal.c
   �Y�ɫ�_���A������CD�ɶ�buff
*/
#include <ansi.h>

inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("cd_food_real_heal");
}

void condition_update(object me, string cnd, mixed cnd_data)
{
    int heal;
    
    if( !living(me) ) return;
    
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        return;
    }
}

/*
void condition_apply(object me, mapping cnd_data)
{
    mapping cnd;

    if( !mapp(cnd = me->query_condition("cd_food_real_heal")) )
        cnd = ([]);

    cnd["duration"] = 60;
    cnd["name"] = BLU"(�N�o)"HIK"�ī~"NOR;

    me->set_condition("cd_food_real_heal", cnd);
}
*/
/*
void condition_apply(object me, string cnd, mapping cnd_data) { }
void condition_unapply(object me, string cnd, mapping cnd_data) { }
*/

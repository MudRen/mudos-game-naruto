/* food.c
   �зǭ��������_ ap, hp, mp ����

   ��Ƶ��c
   ([ "duration": �ɮ�,
   	  "ap": ����,
   	  "hp": ����,
   	  "mp": ����
   ])
*/
#include <ansi.h>

inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("food");
}

void condition_update(object me, string cnd, mixed cnd_data)
{
    int heal;
    
    if( !living(me) ) return;
    
    // �b�԰����άO�ɮĨ�F�A�h����ĪG
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 || me->is_fighting() ) {
        tell_object(me, "�A�w�g�����F�i��...\n");
        me->delete_condition(cnd);
        return;
    }

    // ��_AP��
    heal = cnd_data["heal_ap"];
    me->heal_stat("ap", heal);

    // ��_HP��
    heal = cnd_data["heal_hp"];
    me->heal_stat("hp", heal);

    // ��_MP��
    heal = cnd_data["heal_mp"];
    me->heal_stat("mp", heal);
    
    // �i���������
    me->start_busy(2);
}

/*
void condition_apply(object me, string cnd, mapping cnd_data)
{
    cnd_data["name"] = HIG"�i����"NOR;
    me->set_condition(cnd, cnd_data);
}
*/
/*
void condition_apply(object me, string cnd, mapping cnd_data) { }
void condition_unapply(object me, string cnd, mapping cnd_data) { }
*/

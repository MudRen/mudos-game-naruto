/* food.c */

#include <dbase.h>
#include <name.h>
#include <ansi.h>

inherit COMBINED_ITEM;

int stuff_ob(object me)
{
    int heal;
    string cnd;
mapping con, condition, key;

    // �ߧY��_��
    if( query("heal") ) {
    // �٦bcd
        if( me->query_condition("cd_food_real_heal") ) {
        tell_object(me, "�A�{�b�٨S����k�Y�U�o�Ӫ��~�C\n");
            return 0;
        }

        if( heal = query("heal/ap") ) {
            me->heal_stat("ap", heal);
            tell_object(me, "�A���믫��������_�F " + heal + " �I�C\n");
        }

        if( heal = query("heal/hp") ) {
            me->heal_stat("hp", heal);
            tell_object(me, "�A����O��������_�F " + heal + " �I�C\n");
        }

        if( heal = query("heal/mp") ) {
            me->heal_stat("mp", heal);
            tell_object(me, "�A���]�O��������_�F " + heal + " �I�C\n");
        }

        condition = ([]);
        condition["duration"] = 60;
        condition["name"] = BLU"(�N�o)"HIK"�ī~"NOR;
        me->set_condition("cd_food_real_heal", condition);
        return 1;
    }

    // �����_��
    if( query("condition") ) {
        // ���Ī��A�]�w
        con = query("condition");
        foreach(cnd in keys(con)) {
            condition = ([]);
        foreach(key in keys(con[cnd]) )
            condition[key] = con[cnd][key];
            me->set_condition(cnd, condition);
        }
        return 1;
    }

    return 1;
}

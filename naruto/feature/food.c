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

    // 立即恢復型
    if( query("heal") ) {
    // 還在cd
        if( me->query_condition("cd_food_real_heal") ) {
        tell_object(me, "你現在還沒有辦法吃下這個物品。\n");
            return 0;
        }

        if( heal = query("heal/ap") ) {
            me->heal_stat("ap", heal);
            tell_object(me, "你的精神值瞬間恢復了 " + heal + " 點。\n");
        }

        if( heal = query("heal/hp") ) {
            me->heal_stat("hp", heal);
            tell_object(me, "你的體力值瞬間恢復了 " + heal + " 點。\n");
        }

        if( heal = query("heal/mp") ) {
            me->heal_stat("mp", heal);
            tell_object(me, "你的魔力值瞬間恢復了 " + heal + " 點。\n");
        }

        condition = ([]);
        condition["duration"] = 60;
        condition["name"] = BLU"(冷卻)"HIK"藥品"NOR;
        me->set_condition("cd_food_real_heal", condition);
        return 1;
    }

    // 持續恢復型
    if( query("condition") ) {
        // 長效狀態設定
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

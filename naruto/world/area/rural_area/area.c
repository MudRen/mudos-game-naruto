#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "鄉野農村");
    set("x_axis_size", 41);            // 橫向大小
    set("y_axis_size", 31);            // 縱向大小
    setup();
}
void init()
{
    add_action("do_pull", "pull");
}
void do_check(object me)
{
    mapping cnd = ([]);
    if( random(5) > 3 ) {
        message_vision("旁邊的農夫對著$N大喊："HIG"喂！幹什麼偷拔作物！\n"NOR, me);
        tell_object(me,CYN"你連忙逃到一旁，暫時不敢再來拔東西了。\n"NOR);

        cnd["name"] = HIG"偷拔"NOR;
        cnd["duration"] = 180;

        me->set_condition("pull_pill", cnd);
    }
}
int do_pull(string arg)
{
    object me, area, item;
    int x, y;

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( me->query_level() < 15 ) return notify_fail("你沒有膽子偷拔農作物。\n");
    if( me->query_condition("pull_pill") != 0 ) return notify_fail("農夫正盯著你呢，晚點再來拔吧。\n");
    if( me->is_busy() ) return notify_fail("哪來的第三隻手去拔其他作物。\n");

    if( x >= 23 && x <= 27 && y >= 4 && y <= 12 ) {
        message_vision("$N抓住"HIR"蘿蔔頭"NOR"用力一扯，硬是把"HIR"紅蘿蔔"NOR"給拔出來了。\n", me);

        item = new(__DIR__"item/pill_obj02.c");
        if( item->move(me) ) tell_object(me,HIR"(你得到一根紅蘿蔔)\n"NOR);
        else {
            if( environment(me)->is_area() ) move_side(item, me);
            else item->move(environment(me));
            tell_object(me,HIR"(你得到一根紅蘿蔔，但是掉在地上了)\n"NOR);
        }
        me->start_busy(2);
        do_check(me);
        return 1;
    } else if( x >= 29 && x <= 36 && y >= 8 && y <= 12 ) {
        message_vision("$N把手戳入土壤中，抓住"RED"小辣椒"NOR"的腰身，將"RED"小辣椒"NOR"扯出來了。\n", me);

        item = new(__DIR__"item/pill_obj04.c");
        if( item->move(me) ) tell_object(me,HIR"(你得到一條小辣椒)\n"NOR);
        else {
            if( environment(me)->is_area() ) move_side(item, me);
            else item->move(environment(me));
            tell_object(me,HIR"(你得到一條小辣椒，但是掉在地上了)\n"NOR);
        }
        me->start_busy(2);
        do_check(me);
        return 1;
    } else if( x >= 27 && x <= 36 && y >= 18 && y <= 20 ) {
        message_vision("$N伸出手抓住"HIG"菠菜"NOR"的兩邊，用力一拔將"HIG"菠菜"NOR"整棵拔了出來。\n", me);

        item = new(__DIR__"item/pill_obj01.c");
        if( item->move(me) ) tell_object(me,HIG"(你得到一棵菠菜)\n"NOR);
        else {
            if( environment(me)->is_area() ) move_side(item, me);
            else item->move(environment(me));
            tell_object(me,HIG"(你得到一棵菠菜，但是掉在地上了)\n"NOR);
        }
        me->start_busy(2);
        do_check(me);
        return 1;
    } else if( x >= 27 && x <= 36 && y >= 22 && y <= 24 ) {
        message_vision("$N捏住"HIG"芹菜"NOR"的頂端，輕輕地順著土壤的邊緣抽了出來，完全沒傷到"HIG"芹菜"NOR"。\n", me);

        item = new(__DIR__"item/pill_obj03.c");
        if( item->move(me) ) tell_object(me,HIG"(你得到一根芹菜)\n"NOR);
        else {
            if( environment(me)->is_area() ) move_side(item, me);
            else item->move(environment(me));
            tell_object(me,HIG"(你得到一根芹菜，但是掉在地上了)\n"NOR);
        }
        me->start_busy(2);
        do_check(me);
        return 1;
    }
    return notify_fail("這裡似乎只有雜草能拔。\n");
}

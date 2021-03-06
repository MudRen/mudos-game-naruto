#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(GRN"菠菜丸"NOR, ({ "holenso pill", "pill" }));
    if( !clonep() ) {
        set("unit", "顆");
        set("value", 0);
        set("base_value", 0);
        set("base_weight", 1);
        set("no_box", 1);
        set("long","秋道一族的秘藥，外表看起來很像市面上賣的文魚菠菜丸。\n");
    }
    setup();
}

void do_use(object me, string arg)
{
    mapping cnd = ([]);
    object *inv, item;
    int sk, add, out;

    inv = all_inventory(me);

    if( me->is_busy() ) {
        write("你正在忙碌，沒空吃藥。\n");
        return;
    }
    if( me->query_attr("con") < 50 ) {
        write("你的體格無法負擔秋道秘藥。\n");
        return;
    }
    if( me->query_condition("akimichi1") != 0 ) {
        write("你已經吃過秋道秘藥了，等時效過了再吃吧。\n");
        return;
    }
    if( me->query_condition("akimichi2") != 0 ) {
        write("你已經吃過秋道秘藥了，等時效過了再吃吧。\n");
        return;
    }
    if( me->query_condition("akimichi3") != 0 ) {
        write("辛辣感還沒退去前不能再吃藥。\n");
        return;
    }
    foreach(item in inv) {
        if( item->query("equipped") ) {
            write("吃下秋道秘藥時身體會散發熱氣，因此不能穿著任何裝備。\n");
            return;
        }
    }
    sk = me->query_skill("akimichi pill");

    if( sk < 40 ) {
        write("你的秋道秘藥知識不足，不知道如何食用才會有效果。\n");
        return;
    }
    add = me->query_stat_maximum("hp")/3;
    if( sk < 100 ) out = add*2;
    else if( sk < 160 ) out = add;
    else out = add/2;

    if( me->query_stat_maximum("ap") < out ) {
        write("你的身體無法負擔菠菜丸的效果。\n");
        return;
    }
    message_vision("\n$N將$n丟入口中嚼了幾下，只見$N的身材似乎又變胖了許多。\n"NOR, me, this_object());
    tell_object(me,HIG"菠菜丸發揮效用了！你感覺全身的血液膨脹，衝的腦門有點混亂！\n"NOR);

    cnd["name"] = GRN"菠菜丸"NOR;
    cnd["duration"] = sk;
    cnd["hp"] = add;
    cnd["ap"] = out*-1;
    cnd["mp"] = 0;

    me->set_condition("akimichi1", cnd);
    me->heal_stat("hp", add);
    me->improve_skill("akimichi medicine", 1);
    me->start_busy(2);

    // 個數減少
    this_object()->add_amount(-1);
    if( !this_object()->query_amount() )
        destruct(this_object());
}

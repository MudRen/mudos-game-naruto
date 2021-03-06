#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"咖哩丸"NOR, ({ "kare pill", "pill" }));
    if( !clonep() ) {
        set("unit", "顆");
        set("value", 0);
        set("base_value", 0);
        set("base_weight", 1);
        set("no_box", 1);
        set("long","秋道一族的秘藥，但是看起來就像咖哩飯團，沒什麼特別。\n");
    }
    setup();
}

void do_use(object me, string arg)
{
    mapping cnd = ([]);
    object *inv, item;
    int sk, add;

    inv = all_inventory(me);

    if( me->is_busy() ) {
        write("你正在忙碌，沒空吃藥。\n");
        return;
    }
    if( me->query_attr("con") < 60 ) {
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
    if( sk >= 50 ) add = me->query_stat_maximum("mp")*(sk/50 - 1);
    else add = 0;

    message_vision("\n$N將$n丟入口中含著，只見$N的身材愈來愈消瘦...\n"NOR, me, this_object());
    tell_object(me,HIY"咖哩丸發揮效用了！你的查克拉增加了數倍，但是體力精神卻減弱了...\n"NOR);

    cnd["name"] = YEL"咖哩丸"NOR;
    cnd["duration"] = sk;
    cnd["hp"] = me->query_stat_maximum("hp")/2 - me->query_stat_maximum("hp");
    cnd["ap"] = me->query_stat_maximum("ap")/2 - me->query_stat_maximum("ap");
    cnd["mp"] = add;

    me->set_condition("akimichi1", cnd);
    me->heal_stat("mp", add);
    me->improve_skill("akimichi medicine", 1);
    me->start_busy(2);

    // 個數減少
    this_object()->add_amount(-1);
    if( !this_object()->query_amount() )
        destruct(this_object());
}

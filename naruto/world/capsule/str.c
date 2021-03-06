#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIR"[力量]"NOR+RED"重"HIW"生"HIK"膠囊"NOR, ({ "STR capsule", "capsule" }));
    set("unit", "粒");
    set("value", -1);
    set("no_box", 1);
    set("no_sell", 1);
    set("no_drop", 1);
    set("attr","str");
    set("long", "膠囊狀的小藥丸，但卻不像一般膠囊只是將藥放入以顏色區分種類。\n"
                "此藥外殼的顏色透明能見其中，藥內半邊通紅，半邊雪白。紅中帶著\n"
                "讓人迷惑的流水彩光，白裡卻是一片空白，只有些許的藥粉在裡邊。\n"
                "兩種顏色功能似乎分門別類，但是卻被名醫以手法合成此藥。\n"
             HIY"使用方法為(use capsule)，"NOR+BLINK+HIR"注意："NOR+HIR"吃下後會將該屬性回歸到1級！"NOR);
    setup();
}

void do_use(object me)
{
    int attr;
    object ob = query("attr");
    if( me->query_attr(ob, 1) <= 20 ) {
        write("你現在的狀況不需要吃這個藥。\n");
        return;
    }
    if( me->is_busy() ) {
        write("你正忙著，沒有空吃藥。\n");
        return;
    }
    if( me->is_fighting() ) {
        write("戰鬥中還亂吃藥，當心猝死。\n");
        return;
    }
    message_vision("\n$N拿起$n往嘴裡一丟，喝了口水把$n吞進肚中。\n\n", me, this_object());

    attr = me->query_attr(ob, 1) - 20;

    message_vision(HIW"$N忽然腳下一個不穩，眼睛一白口吐白沫倒在地上。\n\n"NOR, me);

    me->add_point("attribute", attr);
    me->set_attr(ob, 20);

    me->unconcious();
    destruct(this_object());
}

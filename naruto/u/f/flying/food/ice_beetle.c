#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIC"冰凍甲蟲"NOR, ({ "Ice Beetle", "ice", "beetle " }));
    set("unit", "大隻");
    set("base_unit", "大隻");
    set("base_value", -1);
    set("base_weight", 200);
    set("food_stuff", 10);    // 食物量，食品一定要有食物量
    set("long", "藥大師的秘方所製成，不斷地散出微弱的寒氣，是一碗能去火消暑，\n"
                "還能消除全身疲勞的極品良藥，因為成功完成這種甜粥的人少之又少\n"
                "所以就算商人也怕買到假藥而不敢收購。\n"
             HIW"使用方法為"HIC"(use ice)"HIW"，效果是精神"HIR"MAX"HIW"。\n"NOR);
    setup();
}

void do_use(object me)
{
    message_vision("$N拿出一隻冒出臭氣的$n，一口氣就啃了下去。\n", me, this_object());
    message_vision(HIC"$N感到全身一陣嘔意，腦中一片暈眩。\n"NOR, me, this_object());
    me->heal_stat("hp", me->query_stat_maximum("ap"));
    tell_object(me,HIY"(你的精神回復了 "HIR+me->query_stat_maximum("ap")+HIY" 點。)\n"NOR);
    destruct(this_object());
}


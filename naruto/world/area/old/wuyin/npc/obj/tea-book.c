#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(YEL"「茶莖」"NOR, ({ "tea book", "book" }) );
    set_weight(10);

    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "本");
        set("long", "一本講述如何栽種茶樹的書藉，書中序言提及：有良好的茶樹根莖，\n"
                    "方能長出上品的茶葉，故書名取「茶莖」。\n");
    }
    setup();
}

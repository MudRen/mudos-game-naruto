#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIY"沙礫"NOR, ({ "gravel" }));
    if( !clonep() ) {
        set("base_unit", "粒");
        set("unit", "粒");
        set("base_value", 2);
        set("base_weight", 1);
        set("long", "尚未凝聚起來的細小沙子，摸起來粗粗的感覺。");
    }
    setup();
}
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIR"梟之眼"NOR, ({ "owl eyes", "eyes", "_OWL_EYE_" }));
    if( !clonep() ) {
        set("base_unit", "對");
        set("base_value", 50000);
        set("base_weight", 600);
        set("long", "蒼之梟的眼睛，目光銳利，被收藏家所喜愛。\n");
    }
    setup();
}

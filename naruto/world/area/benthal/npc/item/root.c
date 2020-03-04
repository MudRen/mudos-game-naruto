#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(GRN"葵根"NOR, ({ "anemone root", "root" }));

    if( !clonep() ) {
        set("base_unit", "條");
        set("base_value", 300);
        set("base_weight", 100);
        set("long", "海流區所生存的巨型海葵之根部，非常有韌性。\n");
    }
    setup();
}

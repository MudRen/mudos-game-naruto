#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(BCYN+HIC"青玉"NOR, ({ "sapphire" }));
    if( !clonep() ) {
        set("base_unit", "顆");
        set("unit", "顆");
        set("base_value", 20000);
        set("base_weight", 1);
        set("no_box", 1);
        set("long", "青藍色的玉，看久了會讓人感覺放鬆心情，是公侯伯爵們最喜愛的玉\n"
                    "石，其中的高級品藍光更如大海，會有隨波擺動的感覺。");
    }
    setup();
}
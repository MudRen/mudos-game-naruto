#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("寶路", ({ "bowlu", "_BOW_LU_" }));
    if( !clonep() ) {
        set("base_unit", "包");
        set("unit", "包");
        set("base_value", 500);
        set("base_weight", 50);
        set("long", "狗食品，前陣子有問題吃了會腎衰竭而死。");
    }
    setup();
}

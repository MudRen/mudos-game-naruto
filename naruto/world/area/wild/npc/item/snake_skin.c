#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(GRN"�D��"NOR, ({ "snake's skin", "skin", "_SNAKE_SKIN_" }));

    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 10);
        set("base_weight", 600);
        set("long", "�@���ٺ⧹�㪺�D�֡C\n");
    }
    setup();
}

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"���"NOR, ({ "cortex" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 200);
        set("base_weight", 10);
        set("long", "��Q�L��H����֡A�ɱ`�Q�H�����C");
    }
    setup();
}

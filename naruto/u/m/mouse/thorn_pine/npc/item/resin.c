#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"���"NOR, ({ "resin" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 300);
        set("base_weight", 10);
        set("long", "��Q�L��H����סA�ֶq�i�H�i�C���e�C");
    }
    setup();
}

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"��K"NOR, ({ "branch", "_BRANCH_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 100);
        set("base_weight", 10);
        set("no_box", 1);
        set("long", "��Q�L��H����K�A�ɱ`�Q�H�����C");
    }
    setup();
}

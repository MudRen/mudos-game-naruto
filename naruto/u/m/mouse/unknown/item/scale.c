#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name("����", ({ "fish scale", "scale", "_GIN_LINE_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 500);
        set("base_weight", 700);
        set("long", "�h�A���몺����A�~����W�@�i�A�D�`��w�C\n");
    }
    setup();
}

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIK"���ª����Y"NOR, ({ "black stone" }));
    if( !clonep() ) {
        set("base_unit", "�T");
        set("unit", "�T");
        set("base_value", 0);
        set("base_weight", 1);
        set("no_box", 1);
        set("long", "�@���¦⪺�p���Y�A�ݰ_�ӫD�`���_���C");
    }
    setup();
}

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("��y��", ({ "treasury", "_WOOD_TREASURY_" }));
    if( !clonep() ) {
        set("base_unit", "�y");
        set("unit", "�y");
        set("base_value", 20);
        set("base_weight", 100);
        set("long", "�J���������Y�Ať���̭��`�|�ä@�ǬöQ�_���C");
    }
    setup();
}

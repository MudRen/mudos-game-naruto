#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIW"�L��"NOR, ({ "particle" }));
    if( !clonep() ) {
        set("base_unit", "�I");
        set("unit", "�I");
        set("base_value", 1);
        set("base_weight", 1);
        set("long", "�ƴ��b�Ů𤤪��Ӥp�ɤl�A�S����ΡC");
    }
    setup();
}

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(WHT"�l��"NOR, ({ "residue" }));
    if( !clonep() ) {
        set("base_unit", "�b");
        set("unit", "�b");
        set("base_value", 0);
        set("base_weight", 50);
        set("no_drop", 1);
        set("no_auc", 1);
        set("no_give", 1);
        set("long", "�H�H�Ƕ¦�ĦX���A�O�X���G������Ѿl���o��ơC");
    }
    setup();
}

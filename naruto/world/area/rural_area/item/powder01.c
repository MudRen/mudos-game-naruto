#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"�@����"NOR, ({ "curry powder", "powder", "_KARE_C_" }));
    if( !clonep() ) {
        set("unit", "�]");
        set("value", 0);
        set("base_value", 0);
        set("base_weight", 10);
        set("long","�s�@�֦��@�����������~�ɡA�q�`���|�K�[�����C\n");
    }
    setup();
}

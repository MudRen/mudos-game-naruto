#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(GRN"藤條"NOR, ({ "rattan" }));
    set_weight(2000);
    setup_weapon(4, 8, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "根");
        set("value", 1212);
        set("long", "一根長長的藤條，應該可以拿來打人。\n" );
    }

    setup();
}

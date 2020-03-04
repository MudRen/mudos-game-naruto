#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("石槍"NOR, ({ "stone lance", "lance", "_FOUNDER_WP_" }));
    set_weight(30000);
    setup_weapon(10, 10, 100, 1);
    if( !clonep() ) {
        set("wield_as", "twohanded");
        set("unit", "根");
        set("value", 0);
        set("no_combine", 1);
        set("coal_need", 6);
        set("iron_need", 20);
        set("copper_need", 12);
        set("long", "沉重的大槍，完全用硬石所製成，不用雙手根本拿不動。\n" );
    }
    setup();
}

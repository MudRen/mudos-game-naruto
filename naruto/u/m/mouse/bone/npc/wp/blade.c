#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("菜刀", ({ "kitchen blade", "blade" }));
    set_weight(15000);
    setup_weapon(50, 55, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 78552);
        set("long", "切菜用的刀子，通倍利所拿的武器。\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "savage hit" : 5,
           "continual hit" : 5,
           "heavy hit" : 5,
    ]) );
    setup();
}

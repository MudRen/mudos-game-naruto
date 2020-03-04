#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("單刀", ({ "blade" }));
    set_weight(5000);
    setup_weapon(14, 18, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "把");
        set("value", 3232);
        set("long", "一把揮舞起來肯定虎虎生風的單刀。\n" );
    }

    setup();
}

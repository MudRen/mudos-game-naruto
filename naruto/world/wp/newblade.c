#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("新生戰刀", ({ "Newchar Blade", "blade" }));
    set_weight(2000);
    setup_weapon(4, 8, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "把");
        set("value", 1);
        set("long", "武大師送給新手的武器。\n" );
    }

    setup();
}

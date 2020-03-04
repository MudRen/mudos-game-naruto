#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIW"大刀"NOR, ({ "big blade", "blade" }));
    set_weight(8000);
    setup_weapon(20, 30, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "twohanded" }) );
        set("unit", "把");
        set("value", 5050);
        set("long", "一把大型的刀，具有十足的破壞力。\n" );
    }

    setup();
}

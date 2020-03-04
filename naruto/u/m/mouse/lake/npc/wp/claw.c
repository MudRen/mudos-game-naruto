#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIR"蟹鉗"NOR, ({ "crab claw", "claw" }));
    set_weight(8000);
    setup_weapon(10, 15, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "根");
        set("value", 2424);
        set("long", "螃蟹的大鉗子，小心別被夾傷了。\n" );
    }
    setup();
}

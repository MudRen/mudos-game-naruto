#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIG"和泉守"HIC"兼定"NOR, ({ "defend katana", "katana" }));
    set_weight(7000);
    setup_weapon(120, 140, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "把");
        set("no_box", 1);
        set("value", 206030);
        set("long", "美濃國名刀，一代兼定二代兼定最為有名，刃長八十五公分。\n" );
    }
    set("apply_weapon/righthand", 
        ([ "int" : 3,
           "evade" : 5,
           "wittiness" : 5,
    ]) );
    setup();
}

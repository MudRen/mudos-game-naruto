#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("刺木棒", ({ "thorn staff", "staff" }));
    set_weight(3000);
    setup_weapon(25, 30, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 4477);
        set("long", "刺松林的刺木所製成的棒子。\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "attack" : 10,
           "exact" : 5,
    ]) );
    setup();
}

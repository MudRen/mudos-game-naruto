#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("軟槍", ({ "soft lance", "lance" }));
    set_weight(4000);
    setup_weapon(40, 50, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 7545);
        set("long", "槍身軟而堅固，適合連續性的攻擊。\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "continual hit" : 5,
    ]) );
    setup();
}

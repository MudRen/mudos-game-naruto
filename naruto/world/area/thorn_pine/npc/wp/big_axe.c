#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIW"巨斧"NOR, ({ "big axe", "axe" }));
    set_weight(9000);
    setup_weapon(40, 60, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 26450);
        set("long", "斧面加寬的斧頭，重量也十分沉重。\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "str" : 2,
    ]) );
    setup();
}

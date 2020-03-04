#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIR"雙刃斧"NOR, ({ "double axe", "axe" }));
    set_weight(10000);
    setup_weapon(40, 45, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 4242);
        set("long", "一把兩端皆有利刃的巨型斧頭。\n" );
    }

    setup();
}

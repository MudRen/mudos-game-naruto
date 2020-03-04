#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(YEL"大斧"NOR, ({ "big axe", "axe" }));
    set_weight(8000);
    setup_weapon(30, 40, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "twohanded" }) );
        set("unit", "把");
        set("value", 7070);
        set("long", "一把破壞力相當驚人的斧頭。\n" );
    }

    setup();
}

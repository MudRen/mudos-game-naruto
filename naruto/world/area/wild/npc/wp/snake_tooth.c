#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("蛇牙", ({ "snake's tooth", "tooth" }));
    set_weight(6000);
    setup_weapon(14, 18, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "根");
        set("value", 3232);
        set("long", "一根巨大的蛇牙，可以拿來當武器使用。\n" );
    }

    setup();
}

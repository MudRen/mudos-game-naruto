#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(MAG"雙截棍"NOR, ({ "pair rod", "rod" }));
    set_weight(6000);
    setup_weapon(24, 32, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "把");
        set("value", 5656);
        set("long", "兩根棍子之間用鐵鍊接在一起的雙截棍。\n" );
    }

    setup();
}

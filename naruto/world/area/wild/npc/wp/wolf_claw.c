#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(YEL"狼爪"NOR, ({ "wolf's claw", "claw" }));
    set_weight(8000);
    setup_weapon(10, 15, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "隻");
        set("value", 2424);
        set("long", "一隻狼的爪，看起來很尖銳。\n" );
    }

    setup();
}

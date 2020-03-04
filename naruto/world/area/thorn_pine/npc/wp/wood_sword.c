#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("木劍", ({ "wood sword", "sword" }));
    set_weight(300);
    setup_weapon(1, 5, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "把");
        set("value", 606);
        set("long", "木頭的劍，一般武器。\n" );
    }
    setup();
}

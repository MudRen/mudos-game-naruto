#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIY"長勾鐵爪"NOR, ({ "iron hook", "hook" }));
    set_weight(1000);
    setup_weapon(20, 35, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "支");
        set("value", 5454);
        set("long", "長型的鐵勾爪，威力比鐵勾更大。\n" );
    }
    setup();
}

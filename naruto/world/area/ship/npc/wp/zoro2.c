#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIK"三代鬼徹"NOR, ({ "ghost katana", "katana" }));
    set_weight(5000);
    setup_weapon(130, 150, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "lefthand" }) );
        set("unit", "把");
        set("no_box", 1);
        set("value", -1);
        set("long", "索隆所擁有的名刀，據說曾經擁有他的劍客全都死於非命，是把妖刀。\n" );
    }
    set("apply_weapon/lefthand",
        ([ "dex": 10,
           "wittiness": 30,
           "savage hit": 10,
    ]) );
    setup();
}

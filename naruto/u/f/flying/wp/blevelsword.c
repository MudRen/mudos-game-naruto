#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(BBLU+HIC"B級制式戰鬥劍"NOR, ({ "blevel sword", "sword" }));
    set_weight(7000);
    setup_weapon(91, 100, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "把");
        set("value", 286690);
        set("long", "一把非常鋒利的B級制式戰鬥劍。\n" );
    }
     // 附加能力
        set("apply_weapon/righthand",
        ([ "exact" : 5,            
 ]) );
        set("apply_weapon/lefthand",
        ([ "exact" : 5,       
 ]) );

    setup();
}



#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("惡搞之劍", ({ "kuso sword", "sword" }));
    set_weight(1500);
    setup_weapon(199, 200, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "把");
        set("value", 10);
        set("long", "惡搞之劍。\n" );
    }
     // 附加能力
        set("apply_weapon/righthand",
        ([ "exact" : 100,            
 ]) );
        set("apply_weapon/lefthand",
        ([ "exact" : 100,       
 ]) );

    setup();
}



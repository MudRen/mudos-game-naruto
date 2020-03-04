#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("新手木劍", ({ "newbie sword", "sword" }));
    set_weight(1500);
    setup_weapon(1, 2, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "把");
        set("value", 10);
        set("long", "一把細細的木劍，劍柄上貼著新手專用。\n" );
    }
     // 附加能力
        set("apply_weapon/righthand",
        ([ "exact" : 1,            
 ]) );
        set("apply_weapon/lefthand",
        ([ "exact" : 1,       
 ]) );

    setup();
}



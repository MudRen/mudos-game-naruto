#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIM"鳳凰刃"NOR, ({ "blade of the phoenix", "blade" }));
    set_weight(15000);
    setup_weapon(90, 100, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "根");
        set("value", 263795);
        set("long", @long
一把有如鳳凰出浴的短刀。
long
);
    }
    
    // 附加能力
    set("apply_weapon/righthand", 
        ([ "dex": 8,
           "attack": 20, 
           "intimidate": 20, 
        ]) );

    setup();
}

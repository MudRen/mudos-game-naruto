#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIY"破碎刃"NOR, ({ "broken blade", "blade" }));
    set_weight(15000);
    setup_weapon(60, 80, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "根");
        set("value", 48270);
        set("long", @long
專門用來打碎別人骨頭的刀子。
long
);
    }
    
    // 附加能力
    set("apply_weapon/righthand", 
        ([ "dex": 2,
           "str": 2,
           "attack": 10, 
           "intimidate": 6, 
           "exact": 4
        ]) );

    setup();
}

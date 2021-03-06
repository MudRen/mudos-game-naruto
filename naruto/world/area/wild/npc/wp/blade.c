#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("砍馬大刀", ({ "large blade", "blade" }));
    set_weight(15000);
    setup_weapon(40, 50, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "twohanded" }) );
        set("unit", "把");
        set("value", 14240);
        set("long", "一把沉重的巨型大刀，揮舞起來肯定相當嚇人。\n" );
    }
    
    // 附加能力
    set("apply_weapon/twohanded", 
        ([ "str" : 3,            // 屬性：力量
           "attack" : 5,         // 攻擊力量
           "intimidate" : 5,     // 攻擊能力
    ]) );

    setup();
}

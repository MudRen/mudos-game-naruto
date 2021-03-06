#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name(GRN"刺木棒"NOR, ({ "dangerous club", "club" }));
    set_weight(10000);
    setup_weapon(20, 70, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "根");
        set("value", 14240);
        set("long", "一根刺木怪強化過的武器，要兩隻手才揮動起來。\n" );
    }
    
    // 附加能力
    set("apply_weapon/twohanded", 
        ([ "attack" : 10,         // 攻擊力量
           "intimidate" : 10,     // 攻擊能力
    ]) );

    setup();
}


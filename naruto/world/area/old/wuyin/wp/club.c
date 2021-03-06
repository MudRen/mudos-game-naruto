#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name(YEL"木棒"NOR, ({ "club" }));
    set_weight(10000);
    setup_weapon(40, 50, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "根");
        set("value", 14240);
        set("long", "一根刺木怪的武器，要兩隻手才揮動起來。\n" );
    }
    
    // 附加能力
    set("apply_weapon/twohanded", 
        ([ "int" : -5,            // 屬性：力量
           "attack" : 10,         // 攻擊力量
           "intimidate" : 10,     // 攻擊能力
    ]) );

    setup();
}


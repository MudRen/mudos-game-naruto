#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("刺槍", ({ "lance", "lance" }));
    set_weight(8000);
    setup_weapon(50, 55, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 36952);
        set("long", "土著使用的雙手長槍，刀刃峰利。\n" );
    }
    // 附加能力
    set("apply_weapon/twohanded", 
        ([ "str" : 2,            // 屬性：力量
           "dex" : 1,            // 屬性：敏捷
           "intimidate" : 10,     // 攻擊能力
    ]) );
    setup();
}

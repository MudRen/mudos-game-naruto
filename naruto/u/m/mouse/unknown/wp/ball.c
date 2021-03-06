#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name("皮球", ({ "ball" }));
    set_weight(800);
    setup_weapon(10, 20, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "顆");
        set("value", 1815);
        set("long", "一顆馬戲團表演用的皮球。\n" );
    }
    // 附加能力
    set("apply_weapon/righthand",
        ([ "attack" : 3,         // 攻擊力量
    ]) );
    setup();
}

#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("彎刀", ({ "curve blade", "blade" }));
    set_weight(10000);
    setup_weapon(50, 60, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "把");
        set("value", 35555);
        set("long", "一把彎曲的長刀，上面刻著一條蛇的圖案。\n" );
    }
    set("apply_weapon/righthand", 
        ([ "attack" : 10,
           "intimidate" : 10,
    ]) );
    setup();
}

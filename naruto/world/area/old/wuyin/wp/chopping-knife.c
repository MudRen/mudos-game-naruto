
#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("菜刀", ({ "chopping knife", "knife" }));
    set_weight(6000);
    setup_weapon(24, 26, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "把");
        set("value", 5000);
        set("long", "哈比兔族的最喜愛武器，時常都藏在背後，冷不防的攻擊敵人。\n" );
    }

    setup();
}


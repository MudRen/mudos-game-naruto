#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIK"突擊戰刀"NOR, ({ "assault blade", "blade" }));
    set_weight(2000);
    setup_weapon(30, 45, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "lefthand", "righthand" }) );
        set("unit", "把");
        set("value", 15174);
        set("long", "漆黑的刀身，適合深夜突擊作戰。\n" );
    }
    set("apply_weapon/righthand", 
        ([ "intimidate" : 10,
           "dex" : 1,
    ]) );
    setup();
}

#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;
inherit ENHANCE_D;

void create()
{
    set_name("長刀", ({ "long blade", "blade" }));
    set_weight(8000);
    setup_weapon(30, 50, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", "righthand");
        set("unit", "把");
        set("value", 5440);
        set("long", "刀口開雙岔的長刀，沙穴強盜們愛用的兵器。\n" );
    }
    set("apply_weapon/righthand", 
        ([ "str" : 2,
        ]) );
    setup();
}

#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("刺木槍", ({ "thron lance", "lance" }));
    set_weight(4000);
    setup_weapon(40, 50, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 5295);
        set("long", "槍頭有刺木的尖刺，能攻擊多個方向。\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "intimidate" : 5,
    ]) );
    setup();
}

#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIW"長柄砍斧"NOR, ({ "long axe", "axe" }));
    set_weight(7000);
    setup_weapon(45, 70, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 29557);
        set("long", "能劃出較大的圓弧增強斧頭一擊劈出的力道。\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "attack" : 10,
    ]) );
    setup();
}
